
// Generated from HydroModels.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "HydroModelsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by HydroModelsParser.
 */
class  HydroModelsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by HydroModelsParser.
   */
    virtual antlrcpp::Any visitProgram(HydroModelsParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitInputStmt(HydroModelsParser::InputStmtContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(HydroModelsParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVariablesStmt(HydroModelsParser::VariablesStmtContext *context) = 0;

    virtual antlrcpp::Any visitModelStmt(HydroModelsParser::ModelStmtContext *context) = 0;

    virtual antlrcpp::Any visitParametersStmt(HydroModelsParser::ParametersStmtContext *context) = 0;

    virtual antlrcpp::Any visitIdEqualsExpr(HydroModelsParser::IdEqualsExprContext *context) = 0;

    virtual antlrcpp::Any visitIdWithDefault(HydroModelsParser::IdWithDefaultContext *context) = 0;

    virtual antlrcpp::Any visitIdWithouDefault(HydroModelsParser::IdWithouDefaultContext *context) = 0;

    virtual antlrcpp::Any visitEquationsStmt(HydroModelsParser::EquationsStmtContext *context) = 0;

    virtual antlrcpp::Any visitEquationAssignEqual(HydroModelsParser::EquationAssignEqualContext *context) = 0;

    virtual antlrcpp::Any visitEquationAssignOneExpression(HydroModelsParser::EquationAssignOneExpressionContext *context) = 0;

    virtual antlrcpp::Any visitOutputStmt(HydroModelsParser::OutputStmtContext *context) = 0;

    virtual antlrcpp::Any visitOutputDeclWithoutMul(HydroModelsParser::OutputDeclWithoutMulContext *context) = 0;

    virtual antlrcpp::Any visitOutputDeclWithMul(HydroModelsParser::OutputDeclWithMulContext *context) = 0;

    virtual antlrcpp::Any visitExprRecursive(HydroModelsParser::ExprRecursiveContext *context) = 0;

    virtual antlrcpp::Any visitExprTerm(HydroModelsParser::ExprTermContext *context) = 0;

    virtual antlrcpp::Any visitTermFactorSTARSLASHterm(HydroModelsParser::TermFactorSTARSLASHtermContext *context) = 0;

    virtual antlrcpp::Any visitTermFactor(HydroModelsParser::TermFactorContext *context) = 0;

    virtual antlrcpp::Any visitUnaryFactor(HydroModelsParser::UnaryFactorContext *context) = 0;

    virtual antlrcpp::Any visitFactorEqualsPower(HydroModelsParser::FactorEqualsPowerContext *context) = 0;

    virtual antlrcpp::Any visitPowerAtomPowerFactor(HydroModelsParser::PowerAtomPowerFactorContext *context) = 0;

    virtual antlrcpp::Any visitPowerAtom(HydroModelsParser::PowerAtomContext *context) = 0;

    virtual antlrcpp::Any visitAtomID(HydroModelsParser::AtomIDContext *context) = 0;

    virtual antlrcpp::Any visitAtomNumber(HydroModelsParser::AtomNumberContext *context) = 0;

    virtual antlrcpp::Any visitAtomCos(HydroModelsParser::AtomCosContext *context) = 0;

    virtual antlrcpp::Any visitAtomSin(HydroModelsParser::AtomSinContext *context) = 0;

    virtual antlrcpp::Any visitAtomExp(HydroModelsParser::AtomExpContext *context) = 0;

    virtual antlrcpp::Any visitAtomLn(HydroModelsParser::AtomLnContext *context) = 0;

    virtual antlrcpp::Any visitAtomLog10(HydroModelsParser::AtomLog10Context *context) = 0;

    virtual antlrcpp::Any visitAtomPowerFunc(HydroModelsParser::AtomPowerFuncContext *context) = 0;

    virtual antlrcpp::Any visitAtomParenthesis(HydroModelsParser::AtomParenthesisContext *context) = 0;


};

