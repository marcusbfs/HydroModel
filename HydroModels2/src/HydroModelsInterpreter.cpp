
#include "HydroModelsInterpreter.h"

#include "antlr4-runtime.h"
#include "interpreter/HydroModelsLexer.h"
#include "interpreter/HydroModelsParser.h"
#include "interpreter/HydroModelsBaseVisitor.h"

#include "EqNodePtrESO.h"
#include "ESOSolverFactory.h"

#include "BipartiteGraph.h"
#include "BipartiteGraphAlgorithms.h"

#include "Environments.h"

#include "simplify.h"
#include "EqNode.h"

#include <iomanip>

#include <string>
#include <regex>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

double StringToDouble(const std::string& str) {
	std::istringstream ss(str);
	double v;
	ss >> v;
	return v;
}

class InterpreterVisitor : public HydroModelsBaseVisitor {

	virtual antlrcpp::Any visitProgram(HydroModelsParser::ProgramContext* ctx) override {
		//create global env
		env = std::make_shared< ScopedEnv<EqNodePtr> >();
		vars = std::make_shared<std::map < std::string, EqNodePtr>>();
		envHeaders = std::make_shared<ScopedEnv<std::vector<std::string>>>();
		envValuesOutput = std::make_shared<ScopedEnv<std::vector<EqNodePtr>>>();
		envMultipliers = std::make_shared<ScopedEnv<std::vector<double>>>();


		// define some math constants
		EqNodePtr pi_node = std::make_shared<EqNode>(3.141592653589793238462643383279L, EqNode::OperatorType::Number);
		env->define("pi", pi_node);
		env->define("Pi", pi_node);
		env->define("pI", pi_node);
		env->define("PI", pi_node);

		visitChildren(ctx);
		return 0;
	}

	virtual antlrcpp::Any visitInputStmt(HydroModelsParser::InputStmtContext* ctx) override {
		// update values
		visitChildren(ctx);
		// udpate n and nmax values;
		*n = static_cast<size_t>(env->get("n")->getValue());
		*nmax = static_cast<size_t>(env->get("nmax")->getValue());
		return 0;
	}

	virtual antlrcpp::Any visitVariablesStmt(HydroModelsParser::VariablesStmtContext* ctx) override {
		visitChildren(ctx);
		// save initial values of vars
		for (const auto& var : *vars) {
			initialCond[var.first]["upper"] = var.second->getUpperBound();
			initialCond[var.first]["lower"] = var.second->getLowerBound();
			initialCond[var.first]["default"] = var.second->getValue();
		}
		return 0;
	}

	//parameters assignment
	virtual antlrcpp::Any visitVarDecl(HydroModelsParser::VarDeclContext* ctx) override {
		const std::string& id = ctx->IDENTIFIER()->getText();
		EqNodePtr expr = visit(ctx->expression()).as<EqNodePtr>();
		env->define(id, expr);
		return 0;
	}

	//outputStmt:  OUTPUT LEFT_BRACE outputDecl + RIGHT_BRACE;
	virtual antlrcpp::Any visitOutputStmt(HydroModelsParser::OutputStmtContext* ctx) override {
		headers_vec_temp.clear();
		values_vec_temp.clear();
		mul_vec_temp.clear();
		visitChildren(ctx);
		envHeaders->define("headers", headers_vec_temp);
		envValuesOutput->define("vals", values_vec_temp);
		envMultipliers->define("mul", mul_vec_temp);
		return 0;
	}

	//outputDecl :  STRING COMMA IDENTIFIER SEMICOLON # outputDeclWithoutMul
	//              | STRING COMMA IDENTIFIER COMMA expression SEMICOLON # outputDeclWithMul
	//              ;
	virtual antlrcpp::Any visitOutputDeclWithoutMul(HydroModelsParser::OutputDeclWithoutMulContext* ctx) override {
		// put headers
		const auto& header_str = removeAspas(ctx->STRING()->getText());
		headers_vec_temp.push_back(header_str);
		// put values
		const std::string& id_str = ctx->IDENTIFIER()->getText();
		// if id is variable
		if (vars->find(id_str) != vars->end())
			values_vec_temp.push_back((*vars)[id_str]);
		//else it is parameter. get through env
		else
			values_vec_temp.push_back(env->get(id_str));
		// put multiplier = 1
		mul_vec_temp.push_back(1.0L);
		return 0;
	}

	virtual antlrcpp::Any visitOutputDeclWithMul(HydroModelsParser::OutputDeclWithMulContext* ctx) override {
		// put headers
		const auto& header_str = removeAspas(ctx->STRING()->getText());
		headers_vec_temp.push_back(header_str);
		// put values
		const std::string& id_str = ctx->IDENTIFIER()->getText();
		// if id is variable
		if (vars->find(id_str) != vars->end())
			values_vec_temp.push_back((*vars)[id_str]);
		//else it is parameter. get through env
		else
			values_vec_temp.push_back(env->get(id_str));
		// put multiplier = 1
		mul_vec_temp.push_back(visit(ctx->expression()).as<EqNodePtr>()->getValue());
		return 0;
	}

	//modelStmt : MODEL STRING LEFT_BRACE parametersStmt? equationsStmt outputStmt RIGHT_BRACE ;
	virtual antlrcpp::Any visitModelStmt(HydroModelsParser::ModelStmtContext* ctx) override {

		// create and enviroment for model and equations 
		const std::string modelId = removeAspas(ctx->STRING()->getText());
		modelEnv[modelId] = std::make_shared<ScopedEnv<EqNodePtr>>(this->env);
		this->env = modelEnv[modelId];

		// save previous env
		std::shared_ptr<ScopedEnv<EqNodePtr>> previous_env = this->env;
		std::shared_ptr<ScopedEnv<std::vector<std::string>>> previous_envHeaders = envHeaders;
		std::shared_ptr<ScopedEnv<std::vector<EqNodePtr>>> previous_envValuesOutput = envValuesOutput;
		std::shared_ptr<ScopedEnv<std::vector<double>>> previous_envMultipliers = envMultipliers;;
		//create new
		this->envHeaders = std::make_shared<ScopedEnv<std::vector<std::string>>>(previous_envHeaders);
		this->envValuesOutput = std::make_shared<ScopedEnv<std::vector<EqNodePtr>>>(previous_envValuesOutput);
		this->envMultipliers = std::make_shared<ScopedEnv<std::vector<double>>>(previous_envMultipliers);

		// for each model, create and copy equations, parameters and variables,
		// allowing them to also create new parameters

		(*modelEquations)[modelId] = std::vector<EqNodePtr>();
		this->equations = &(*modelEquations)[modelId];

		(*modelVars)[modelId] = std::map<std::string, EqNodePtr>();
		(*modelPars)[modelId] = std::map<std::string, EqNodePtr>();

		(*modelHeaders)[modelId] = std::vector<std::string>();
		Headers = &(*modelHeaders)[modelId];

		(*modelValuesOutput)[modelId] = std::vector<EqNodePtr>();
		ValuesOutput = &(*modelValuesOutput)[modelId];

		(*modelMultipliers)[modelId] = std::vector<double>();
		Multipliers = &(*modelMultipliers)[modelId];

		// visit children to get informations
		visitChildren(ctx);

		// get vars
		std::vector<EqNodePtr> varvec;
		// eqnode* to string
		std::map<EqNode*, std::string> var_to_string;
		for (const auto& var : *vars) {
			var_to_string[var.second.get()] = var.first;
			varvec.push_back(var.second);
			//set initial
			var.second->setLowerBound(initialCond[var.first]["lower"]);
			var.second->setUpperBound(initialCond[var.first]["upper"]);
			var.second->v = initialCond[var.first]["default"];
		}

		// simplify all equations (NOT WORKING)
		//for (EqNodePtr& eq : *equations)
		//	SimplifyEqNode::simplify(*eq);

		// =================================================
		// perform a structural analyses

		// main graph
		BipartiteGraph<EqNodePtr> graph;

		// add variables to graph
		for (const EqNodePtr& var : varvec) {
			std::unique_ptr<BipartiteNode<EqNodePtr>> tmp_v =
				std::make_unique<BipartiteNode<EqNodePtr>>(var);
			graph.addV(tmp_v);
		}

		//for each equations, collect all dependents variables
		//and construct a graph
		for (const EqNodePtr& eq : *equations) {
			auto eq_node_graph
				= std::make_unique<BipartiteNode<EqNodePtr>>(eq);

			for (const std::unique_ptr<BipartiteNode<EqNodePtr>>&
				var_node : graph.getVars())
			{
				// equations depends on var -> connect equation and var
				if (eq->depends(*var_node->getObject()))
					eq_node_graph->addEdge(*var_node);
			}
			graph.addE(eq_node_graph);
		}

		// maximum matching
		BipartiteGraphAlgorihtms<EqNodePtr>::MaximumMatching(&graph);
		BipartiteGraphAlgorihtms<EqNodePtr>::MaximumMatching(&graph);
		// divides domain
		int n_over, n_under;
		bool systemIsWellBehavied =
			BipartiteGraphAlgorihtms<EqNodePtr>::DulmageMendelshon(&graph, n_over, n_under);
		// =================================================

		const std::vector<std::string>& headers_vec = envHeaders->get("headers");
		const size_t& headers_size = headers_vec.size();

		const std::vector<EqNodePtr>& valsOut_vec = envValuesOutput->get("vals");
		const size_t& valuesOut_size = valsOut_vec.size();

		const std::vector<double>& mul_vec = envMultipliers->get("mul");
		const size_t& mul_size = mul_vec.size();

		// what if no multipliers stmt?
		if (Multipliers->size() == 0)
			for (size_t i = 0; i < headers_size; ++i)
				Multipliers->push_back(1.0);

		// check if headers and values output have same number
		if (headers_size != valuesOut_size ||
			headers_size != mul_size) {
			std::string error_msg = "Headers and values in model '" +
				modelId + "' doesnt have same size.";
			output_strstream << error_msg << '\n';
			throw std::exception(error_msg.c_str());
			exit(1);
		}

		// get model name
		(*out_ModelNames).push_back(modelId);

		// get headers, values and muls to output (pointers) 
		out_HeadersNames->clear();
		for (const auto& header : headers_vec) {
			out_HeadersNames->push_back(header);
			Headers->push_back(header);
			(*ModelValuesOutput)[modelId][header] = std::vector<double>();
		}
		for (const auto& value : valsOut_vec)
			ValuesOutput->push_back(value);
		for (const auto& mul : mul_vec)
			Multipliers->push_back(mul);

		// test executing code here!
		constexpr double tol = 1e-12;
		constexpr int kmax = 300;
		constexpr int width = 20, precision = 13;
		output_strstream << "Model: " << modelId << "\n\n";

		const auto& size = vars->size();

		if (!systemIsWellBehavied) {
			output_strstream << "System is structurly singular\n\n";
			output_strstream << "Number of equatons: " << graph.ne() << '\n';
			output_strstream << "Number of variables: " << graph.nv() << "\n\n";
			if (n_over > 0) {
				output_strstream << "System has " << n_over << " over constraints\n";
				for (size_t i = 0; i < graph.ne(); ++i) {
					if (graph.getEqs()[i]->hasFlag((int)BipartiteGraphFlags::OVER))
						output_strstream << "eq_" << i + 1 << "\t";
				}
				output_strstream << '\n';
				for (const auto& v : graph.getVars())
					if (v->hasFlag((int)BipartiteGraphFlags::OVER))
						output_strstream << var_to_string[v->getObject().get()] << "\t";
				output_strstream << "\n\n";
			}
			if (n_under > 0) {
				output_strstream << "System has " << n_under << " under constraints\n";
				for (size_t i = 0; i < graph.ne(); ++i) {
					if (graph.getEqs()[i]->hasFlag((int)BipartiteGraphFlags::UNDER))
						output_strstream << "eq_" << i + 1 << "\t";
				}
				output_strstream << '\n';
				for (const auto& v : graph.getVars())
					if (v->hasFlag((int)BipartiteGraphFlags::UNDER))
						output_strstream << var_to_string[v->getObject().get()] << "\t";
			}
			output_strstream << "\n\n";
		}

		else {
			// print headers
			for (const std::string& header : headers_vec)
				output_strstream << std::setw(width) << header;
			output_strstream << '\n';

			const int& n_initial = *n;
			const int& n_final = *nmax;
			const auto& env_num_hydros = this->env->get("n");

			// create object that represents system of equations
			std::unique_ptr<ESO> eso =
				std::make_unique<EqNodePtrESO>(equations, &varvec);

			//create solver object that can solve the previous ESO
			auto nlopt_solver = std::unique_ptr<NLAESOSolver>(
				ESOSolverFactory::getESOSolver(
					ESOSolverFactory::Solver::nlopt, eso.get())
			);

			auto newtonmod_solver = std::unique_ptr<NLAESOSolver>(
				ESOSolverFactory::getESOSolver(
					ESOSolverFactory::Solver::simple, eso.get())
			);

			for (auto i = n_initial; i <= n_final; ++i) {
				// change num hydros
				env_num_hydros->v = i;

				// solve
				try {
					newtonmod_solver->solve();
				} catch (...) {}
				try {
					nlopt_solver->solve();
				} catch (...) {}
				try {
					newtonmod_solver->solve();
				} catch (...) {}

				// print variables
				for (size_t i = 0; i < valsOut_vec.size(); ++i) {
					const EqNodePtr& var = valsOut_vec[i];
					const auto output_value = var->getValue() * mul_vec[i];
					output_strstream << std::setw(width) << std::setprecision(precision)
						<< output_value;
					// put value to output pointer
					(*ModelValuesOutput)[modelId][headers_vec[i]].push_back(output_value);
				}
				output_strstream << '\n';
			}
			output_strstream << '\n';

		} // end of systemisWellBehavierd

		// change back env
		this->env = previous_env;
		this->envHeaders = previous_envHeaders;
		this->envValuesOutput = previous_envValuesOutput;
		this->envMultipliers = previous_envMultipliers;

		return 0;
	}

	virtual antlrcpp::Any visitEquationAssignEqual(HydroModelsParser::EquationAssignEqualContext* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Subtract;
		node->left = visit(ctx->expression()[0]).as<EqNodePtr>();
		node->right = visit(ctx->expression()[1]).as<EqNodePtr>();
		equations->push_back(node);
		return 0;
	}

	virtual antlrcpp::Any visitEquationAssignOneExpression(HydroModelsParser::EquationAssignOneExpressionContext* ctx) override {
		equations->push_back(visit(ctx->expression()).as<EqNodePtr>());
		return 0;
	}

	virtual antlrcpp::Any visitIdEqualsExpr(HydroModelsParser::IdEqualsExprContext* ctx) override {
		std::string id = ctx->IDENTIFIER()->getText();
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Variable;
		node->v = visit(ctx->expression()).as<EqNodePtr>()->getValue();
		(*vars)[id] = node;
		return 0;
	}

	virtual antlrcpp::Any visitIdWithDefault(HydroModelsParser::IdWithDefaultContext* ctx) override {
		std::string id = ctx->IDENTIFIER()->getText();
		double val = visit(ctx->expression()[0]).as<EqNodePtr>()->getValue();
		double lower = visit(ctx->expression()[1]).as<EqNodePtr>()->getValue();
		double upper = visit(ctx->expression()[2]).as<EqNodePtr>()->getValue();
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Variable;
		node->v = val;
		node->setLowerBound(lower);
		node->setUpperBound(upper);
		(*vars)[id] = node;
		return 0;
	}

	virtual antlrcpp::Any visitIdWithouDefault(HydroModelsParser::IdWithouDefaultContext* ctx) override {
		std::string id = ctx->IDENTIFIER()->getText();
		double lower = visit(ctx->expression()[0]).as<EqNodePtr>()->getValue();
		double upper = visit(ctx->expression()[1]).as<EqNodePtr>()->getValue();
		double val = .5 * (lower + upper);
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Variable;
		node->v = val;
		node->setLowerBound(lower);
		node->setUpperBound(upper);
		(*vars)[id] = node;
		return 0;
	}

	//expression : term  op=( PLUS | MINUS) expression #exprRecursive
	//            | term #exprTerm
	virtual antlrcpp::Any visitExprRecursive(HydroModelsParser::ExprRecursiveContext* ctx) override {
		EqNodePtr newRoot = std::make_shared<EqNode>();
		if (ctx->op->getType() == HydroModelsLexer::PLUS)
			newRoot->op = EqNode::OperatorType::Add;
		else
			newRoot->op = EqNode::OperatorType::Subtract;
		newRoot->left = visit(ctx->term()).as<EqNodePtr>();
		newRoot->right = visit(ctx->expression()).as<EqNodePtr>();
		return newRoot;
	}

	//expression : term  op=( PLUS | MINUS) expression #exprRecursive
		//            | term #exprTerm
	virtual antlrcpp::Any visitExprTerm(HydroModelsParser::ExprTermContext* ctx) override {
		return visit(ctx->term()).as<EqNodePtr>();
	}
	//term : factor op=(STAR | SLASH ) term #termFactorSTARSLASHterm
	//     | factor  #termFactor
	virtual antlrcpp::Any visitTermFactorSTARSLASHterm(HydroModelsParser::TermFactorSTARSLASHtermContext* ctx) override {
		EqNodePtr newRoot = std::make_shared<EqNode>();
		if (ctx->op->getType() == HydroModelsLexer::STAR)
			newRoot->op = EqNode::OperatorType::Multiply;
		else
			newRoot->op = EqNode::OperatorType::Divide;
		newRoot->left = visit(ctx->factor()).as<EqNodePtr>();
		newRoot->right = visit(ctx->term()).as<EqNodePtr>();
		return newRoot;
	}
	virtual antlrcpp::Any visitTermFactor(HydroModelsParser::TermFactorContext* ctx) override {
		return visit(ctx->factor()).as<EqNodePtr>();
	}

	virtual antlrcpp::Any visitUnaryFactor(HydroModelsParser::UnaryFactorContext* ctx) override {
		// factor : (( PLUS | MINUS) factor)  #unaryFactor
		// plus case
		if (HydroModelsLexer::PLUS == ctx->op->getType())
			return visit(ctx->factor()).as<EqNodePtr>();

		// minus case
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Multiply;
		node->left = std::make_shared<EqNode>();
		node->left->op = EqNode::OperatorType::Number;
		node->left->v = -1.0;
		node->right = visit(ctx->factor()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitFactorEqualsPower(HydroModelsParser::FactorEqualsPowerContext* ctx) override {
		// factor : power #factorEqualsPower
		return visit(ctx->power()).as<EqNodePtr>();
	}

	virtual antlrcpp::Any visitPowerAtomPowerFactor(HydroModelsParser::PowerAtomPowerFactorContext* ctx) override {
		//power : atom POWER_OP factor  #powerAtomPowerFactor
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Power;
		node->left = visit(ctx->atom()).as<EqNodePtr>();
		node->right = visit(ctx->factor()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitPowerAtom(HydroModelsParser::PowerAtomContext* ctx) override {
		// power :  atom;
		return visit(ctx->atom()).as<EqNodePtr>();
	}

	virtual antlrcpp::Any visitAtomParenthesis(HydroModelsParser::AtomParenthesisContext* ctx) override {
		return visit(ctx->expression()).as<EqNodePtr>();
	}

	virtual antlrcpp::Any visitAtomCos(HydroModelsParser::AtomCosContext* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Cos;
		node->left = visit(ctx->expression()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitAtomSin(HydroModelsParser::AtomSinContext* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Sin;
		node->left = visit(ctx->expression()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitAtomExp(HydroModelsParser::AtomExpContext* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Exp;
		node->left = visit(ctx->expression()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitAtomLn(HydroModelsParser::AtomLnContext* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Ln;
		node->left = visit(ctx->expression()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitAtomLog10(HydroModelsParser::AtomLog10Context* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Log10;
		node->left = visit(ctx->expression()).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitAtomPowerFunc(HydroModelsParser::AtomPowerFuncContext* ctx) override {
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Power;
		node->left = visit(ctx->expression()[0]).as<EqNodePtr>();
		node->right = visit(ctx->expression()[1]).as<EqNodePtr>();
		return node;
	}

	virtual antlrcpp::Any visitAtomNumber(HydroModelsParser::AtomNumberContext* ctx) override {
		double val;
		val = StringToDouble(ctx->NUMBER()->getText());
		EqNodePtr node = std::make_shared<EqNode>();
		node->op = EqNode::OperatorType::Number;
		node->v = val;
		return node;
	}

	virtual antlrcpp::Any visitAtomID(HydroModelsParser::AtomIDContext* ctx) override {
		// check if id is a variable
		const std::string& id = ctx->IDENTIFIER()->getText();
		if (vars->find(id) != vars->end())
			return (*vars)[id];
		// else is parameter
		return env->get(id);
	}

private:
	// helpers
	std::string removeAspas(const std::string& str) {
		return str.substr(1, str.size() - 2);
	}

public:
	// environments
	std::shared_ptr<ScopedEnv<EqNodePtr>> env;
	std::map<std::string, std::shared_ptr<ScopedEnv<EqNodePtr>>> modelEnv;
	std::shared_ptr<ScopedEnv<std::vector<std::string>>> envHeaders;
	std::shared_ptr<ScopedEnv<std::vector<EqNodePtr>>> envValuesOutput;
	std::shared_ptr<ScopedEnv<std::vector<double>>> envMultipliers;
	std::vector<std::string> headers_vec_temp;
	std::vector<EqNodePtr> values_vec_temp;
	std::vector<double> mul_vec_temp;
	// properties
	std::shared_ptr<std::map<std::string, EqNodePtr>> vars;
	std::map<std::string, std::map<std::string, double>> initialCond;
	// all equations
	std::vector<EqNodePtr>* equations;
	// pointer to current header and output values
	unsigned* n, * nmax;
	std::vector<std::string>* Headers;
	std::vector<EqNodePtr>* ValuesOutput;
	std::vector<double>* Multipliers;
	std::map<std::string, std::map<std::string, std::vector<double> > >* ModelValuesOutput;
	// output
	std::map<std::string, std::map<std::string, EqNodePtr>>* modelVars;
	std::map<std::string, std::map<std::string, EqNodePtr>>* modelPars;
	std::map<std::string, std::vector<EqNodePtr>>* modelEquations;
	std::map<std::string, std::vector<std::string>>* modelHeaders;
	std::map<std::string, std::vector<EqNodePtr>>* modelValuesOutput;
	std::map<std::string, std::vector<double>>* modelMultipliers;
	std::vector<std::string>* out_ModelNames;
	std::vector<std::string>* out_HeadersNames;
	// string of output
	std::stringstream output_strstream;
	// == methods ==
	std::string getOutputString() {
		std::string s(std::istreambuf_iterator<char>(output_strstream), {});
		return s;
	}
};

HydroModelsInterpreter::HydroModelsInterpreter()
	: m_visitor(std::make_unique<InterpreterVisitor>())
{
}

HydroModelsInterpreter::~HydroModelsInterpreter() = default;

void HydroModelsInterpreter::preProcessor(std::string & content)
{
	// substitues pi
	//content = std::regex_replace(content, std::regex(R"(\{pi\})", std::regex_constants::icase), "3.141592653589793238462643383279");
}

void HydroModelsInterpreter::run(
	const std::string & input_file,
	unsigned* n, unsigned* nmax,
	std::map<std::string, std::map<std::string, EqNodePtr>> & modelVars,
	std::map<std::string, std::map<std::string, EqNodePtr>> & modelPars,
	std::map<std::string, std::vector<EqNodePtr>> & modelEquations,
	std::map<std::string, std::vector<std::string>> & modelHeaders,
	std::map<std::string, std::vector<EqNodePtr>> & modelValuesOutput,
	std::map<std::string, std::vector<double>> & modelMultipliers,
	std::vector<std::string>& out_ModelNames,
	std::vector<std::string>& out_HeadersNames,
	std::map<std::string, std::map<std::string, std::vector<double> > >& ModelValuesOutput
)
{
	std::string ifile = input_file;
	std::ifstream input_filestream(ifile);
	std::string file_content(std::istreambuf_iterator<char>(input_filestream), {});

	preProcessor(file_content);

	std::stringstream input_stream(file_content);

	antlr4::ANTLRInputStream file(input_stream);
	HydroModelsLexer lexer(&file);
	antlr4::CommonTokenStream tokens(&lexer);
	HydroModelsParser parser(&tokens);
	antlr4::tree::ParseTree* tree = parser.program();

	this->m_visitor->modelVars = &modelVars;
	this->m_visitor->modelPars = &modelPars;
	this->m_visitor->modelEquations = &modelEquations;
	this->m_visitor->modelHeaders = &modelHeaders;
	this->m_visitor->modelValuesOutput = &modelValuesOutput;
	this->m_visitor->modelMultipliers = &modelMultipliers;
	this->m_visitor->ModelValuesOutput = &ModelValuesOutput;
	this->m_visitor->out_ModelNames = &out_ModelNames;
	this->m_visitor->out_HeadersNames = &out_HeadersNames;
	this->m_visitor->n = n;
	this->m_visitor->nmax = nmax;

	//visit tree
	this->m_visitor->visit(tree);
}

std::string HydroModelsInterpreter::getOutputString() const
{
	return m_visitor->getOutputString();
}


