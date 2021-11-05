
// Generated from HydroModels.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  HydroModelsParser : public antlr4::Parser {
public:
  enum {
    MODEL = 1, VARIABLES = 2, PARAMETERS = 3, EQUATIONS = 4, DEFAULT = 5, 
    LOWER = 6, UPPER = 7, INPUT = 8, OUTPUT = 9, END = 10, LN = 11, LOG10 = 12, 
    POWERFUNC = 13, EXP = 14, COS = 15, SIN = 16, LEFT_PAREN = 17, RIGHT_PAREN = 18, 
    LEFT_BRACE = 19, RIGHT_BRACE = 20, COMMA = 21, MINUS = 22, PLUS = 23, 
    SEMICOLON = 24, SLASH = 25, STAR = 26, EQUAL = 27, POWER_OP = 28, IDENTIFIER = 29, 
    STRING = 30, NUMBER = 31, COMMENTS = 32, BLOCKCOMMENT = 33, WS = 34
  };

  enum {
    RuleProgram = 0, RuleInputStmt = 1, RuleVarDecl = 2, RuleVariablesStmt = 3, 
    RuleModelStmt = 4, RuleParametersStmt = 5, RuleVarassignments = 6, RuleEquationsStmt = 7, 
    RuleEquationassign = 8, RuleOutputStmt = 9, RuleOutputDecl = 10, RuleExpression = 11, 
    RuleTerm = 12, RuleFactor = 13, RulePower = 14, RuleAtom = 15
  };

  HydroModelsParser(antlr4::TokenStream *input);
  ~HydroModelsParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class InputStmtContext;
  class VarDeclContext;
  class VariablesStmtContext;
  class ModelStmtContext;
  class ParametersStmtContext;
  class VarassignmentsContext;
  class EquationsStmtContext;
  class EquationassignContext;
  class OutputStmtContext;
  class OutputDeclContext;
  class ExpressionContext;
  class TermContext;
  class FactorContext;
  class PowerContext;
  class AtomContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariablesStmtContext *variablesStmt();
    InputStmtContext *inputStmt();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *EOF();
    OutputStmtContext *outputStmt();
    std::vector<ModelStmtContext *> modelStmt();
    ModelStmtContext* modelStmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  InputStmtContext : public antlr4::ParserRuleContext {
  public:
    InputStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<VarDeclContext *> varDecl();
    VarDeclContext* varDecl(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputStmtContext* inputStmt();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQUAL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  VariablesStmtContext : public antlr4::ParserRuleContext {
  public:
    VariablesStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLES();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<VarassignmentsContext *> varassignments();
    VarassignmentsContext* varassignments(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariablesStmtContext* variablesStmt();

  class  ModelStmtContext : public antlr4::ParserRuleContext {
  public:
    ModelStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODEL();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    EquationsStmtContext *equationsStmt();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    ParametersStmtContext *parametersStmt();
    OutputStmtContext *outputStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModelStmtContext* modelStmt();

  class  ParametersStmtContext : public antlr4::ParserRuleContext {
  public:
    ParametersStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMETERS();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<VarDeclContext *> varDecl();
    VarDeclContext* varDecl(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersStmtContext* parametersStmt();

  class  VarassignmentsContext : public antlr4::ParserRuleContext {
  public:
    VarassignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarassignmentsContext() = default;
    void copyFrom(VarassignmentsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdWithDefaultContext : public VarassignmentsContext {
  public:
    IdWithDefaultContext(VarassignmentsContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *DEFAULT();
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *LOWER();
    antlr4::tree::TerminalNode *UPPER();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdWithouDefaultContext : public VarassignmentsContext {
  public:
    IdWithouDefaultContext(VarassignmentsContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *LOWER();
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *UPPER();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdEqualsExprContext : public VarassignmentsContext {
  public:
    IdEqualsExprContext(VarassignmentsContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQUAL();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarassignmentsContext* varassignments();

  class  EquationsStmtContext : public antlr4::ParserRuleContext {
  public:
    EquationsStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUATIONS();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<EquationassignContext *> equationassign();
    EquationassignContext* equationassign(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EquationsStmtContext* equationsStmt();

  class  EquationassignContext : public antlr4::ParserRuleContext {
  public:
    EquationassignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EquationassignContext() = default;
    void copyFrom(EquationassignContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EquationAssignOneExpressionContext : public EquationassignContext {
  public:
    EquationAssignOneExpressionContext(EquationassignContext *ctx);

    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EquationAssignEqualContext : public EquationassignContext {
  public:
    EquationAssignEqualContext(EquationassignContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *EQUAL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EquationassignContext* equationassign();

  class  OutputStmtContext : public antlr4::ParserRuleContext {
  public:
    OutputStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OUTPUT();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<OutputDeclContext *> outputDecl();
    OutputDeclContext* outputDecl(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OutputStmtContext* outputStmt();

  class  OutputDeclContext : public antlr4::ParserRuleContext {
  public:
    OutputDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OutputDeclContext() = default;
    void copyFrom(OutputDeclContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OutputDeclWithMulContext : public OutputDeclContext {
  public:
    OutputDeclWithMulContext(OutputDeclContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OutputDeclWithoutMulContext : public OutputDeclContext {
  public:
    OutputDeclWithoutMulContext(OutputDeclContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OutputDeclContext* outputDecl();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprRecursiveContext : public ExpressionContext {
  public:
    ExprRecursiveContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    TermContext *term();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprTermContext : public ExpressionContext {
  public:
    ExprTermContext(ExpressionContext *ctx);

    TermContext *term();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TermFactorSTARSLASHtermContext : public TermContext {
  public:
    TermFactorSTARSLASHtermContext(TermContext *ctx);

    antlr4::Token *op = nullptr;
    FactorContext *factor();
    TermContext *term();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TermFactorContext : public TermContext {
  public:
    TermFactorContext(TermContext *ctx);

    FactorContext *factor();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FactorContext() = default;
    void copyFrom(FactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryFactorContext : public FactorContext {
  public:
    UnaryFactorContext(FactorContext *ctx);

    antlr4::Token *op = nullptr;
    FactorContext *factor();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorEqualsPowerContext : public FactorContext {
  public:
    FactorEqualsPowerContext(FactorContext *ctx);

    PowerContext *power();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FactorContext* factor();

  class  PowerContext : public antlr4::ParserRuleContext {
  public:
    PowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PowerContext() = default;
    void copyFrom(PowerContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PowerAtomContext : public PowerContext {
  public:
    PowerAtomContext(PowerContext *ctx);

    AtomContext *atom();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PowerAtomPowerFactorContext : public PowerContext {
  public:
    PowerAtomPowerFactorContext(PowerContext *ctx);

    AtomContext *atom();
    antlr4::tree::TerminalNode *POWER_OP();
    FactorContext *factor();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PowerContext* power();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AtomIDContext : public AtomContext {
  public:
    AtomIDContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomExpContext : public AtomContext {
  public:
    AtomExpContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *EXP();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomNumberContext : public AtomContext {
  public:
    AtomNumberContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomPowerFuncContext : public AtomContext {
  public:
    AtomPowerFuncContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *POWERFUNC();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomSinContext : public AtomContext {
  public:
    AtomSinContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *SIN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomCosContext : public AtomContext {
  public:
    AtomCosContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *COS();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomLnContext : public AtomContext {
  public:
    AtomLnContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *LN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomLog10Context : public AtomContext {
  public:
    AtomLog10Context(AtomContext *ctx);

    antlr4::tree::TerminalNode *LOG10();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomParenthesisContext : public AtomContext {
  public:
    AtomParenthesisContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

