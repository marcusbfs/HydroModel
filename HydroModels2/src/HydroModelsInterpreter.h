#pragma once

#include "EqNode.h"

#include <memory>
#include <string>
#include <map>
#include <vector>

class InterpreterVisitor;

class HydroModelsInterpreter {

public:
	HydroModelsInterpreter();
	~HydroModelsInterpreter();
	HydroModelsInterpreter(const HydroModelsInterpreter& other) = delete;
	HydroModelsInterpreter& operator=(const HydroModelsInterpreter& other) = delete;
	//methods
	void run(
		const std::string& input_file,
		unsigned* n, unsigned* nmax,
		std::map<std::string, std::map<std::string, EqNodePtr>>& modelVars,
		std::map<std::string, std::map<std::string, EqNodePtr>>& modelPars,
		std::map<std::string, std::vector<EqNodePtr>>& modelEquations,
		std::map<std::string, std::vector<std::string>>& modelHeaders,
		std::map<std::string, std::vector<EqNodePtr>>& modelValuesOutput,
		std::map<std::string, std::vector<double>>& modelMultipliers,
		std::vector<std::string>& out_ModelNames,
		std::vector<std::string>& out_HeadersNames,
		std::map<std::string, std::map<std::string, std::vector<double> > >& ModelValuesOutput
		);

	std::string getOutputString() const;

private:
	// methods
	void preProcessor(std::string& file);
	// properties
	std::unique_ptr<InterpreterVisitor> m_visitor;
};
