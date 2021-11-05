
// Generated from HydroModels.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "HydroModelsVisitor.h"


/**
 * This class provides an empty implementation of HydroModelsVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  HydroModelsBaseVisitor : public HydroModelsVisitor {
public:

  virtual antlrcpp::Any visitProgram(HydroModelsParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInputStmt(HydroModelsParser::InputStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(HydroModelsParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariablesStmt(HydroModelsParser::VariablesStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModelStmt(HydroModelsParser::ModelStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParametersStmt(HydroModelsParser::ParametersStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdEqualsExpr(HydroModelsParser::IdEqualsExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdWithDefault(HydroModelsParser::IdWithDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdWithouDefault(HydroModelsParser::IdWithouDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEquationsStmt(HydroModelsParser::EquationsStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEquationAssignEqual(HydroModelsParser::EquationAssignEqualContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEquationAssignOneExpression(HydroModelsParser::EquationAssignOneExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutputStmt(HydroModelsParser::OutputStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutputDeclWithoutMul(HydroModelsParser::OutputDeclWithoutMulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutputDeclWithMul(HydroModelsParser::OutputDeclWithMulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprRecursive(HydroModelsParser::ExprRecursiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprTerm(HydroModelsParser::ExprTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTermFactorSTARSLASHterm(HydroModelsParser::TermFactorSTARSLASHtermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTermFactor(HydroModelsParser::TermFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryFactor(HydroModelsParser::UnaryFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactorEqualsPower(HydroModelsParser::FactorEqualsPowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowerAtomPowerFactor(HydroModelsParser::PowerAtomPowerFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowerAtom(HydroModelsParser::PowerAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomID(HydroModelsParser::AtomIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomNumber(HydroModelsParser::AtomNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomCos(HydroModelsParser::AtomCosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomSin(HydroModelsParser::AtomSinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomExp(HydroModelsParser::AtomExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomLn(HydroModelsParser::AtomLnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomLog10(HydroModelsParser::AtomLog10Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomPowerFunc(HydroModelsParser::AtomPowerFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomParenthesis(HydroModelsParser::AtomParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }


};

