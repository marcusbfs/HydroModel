
// Generated from HydroModels.g4 by ANTLR 4.7.2


#include "HydroModelsVisitor.h"

#include "HydroModelsParser.h"


using namespace antlrcpp;
using namespace antlr4;

HydroModelsParser::HydroModelsParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

HydroModelsParser::~HydroModelsParser() {
  delete _interpreter;
}

std::string HydroModelsParser::getGrammarFileName() const {
  return "HydroModels.g4";
}

const std::vector<std::string>& HydroModelsParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& HydroModelsParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

HydroModelsParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HydroModelsParser::VariablesStmtContext* HydroModelsParser::ProgramContext::variablesStmt() {
  return getRuleContext<HydroModelsParser::VariablesStmtContext>(0);
}

HydroModelsParser::InputStmtContext* HydroModelsParser::ProgramContext::inputStmt() {
  return getRuleContext<HydroModelsParser::InputStmtContext>(0);
}

tree::TerminalNode* HydroModelsParser::ProgramContext::END() {
  return getToken(HydroModelsParser::END, 0);
}

tree::TerminalNode* HydroModelsParser::ProgramContext::EOF() {
  return getToken(HydroModelsParser::EOF, 0);
}

HydroModelsParser::OutputStmtContext* HydroModelsParser::ProgramContext::outputStmt() {
  return getRuleContext<HydroModelsParser::OutputStmtContext>(0);
}

std::vector<HydroModelsParser::ModelStmtContext *> HydroModelsParser::ProgramContext::modelStmt() {
  return getRuleContexts<HydroModelsParser::ModelStmtContext>();
}

HydroModelsParser::ModelStmtContext* HydroModelsParser::ProgramContext::modelStmt(size_t i) {
  return getRuleContext<HydroModelsParser::ModelStmtContext>(i);
}


size_t HydroModelsParser::ProgramContext::getRuleIndex() const {
  return HydroModelsParser::RuleProgram;
}


antlrcpp::Any HydroModelsParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::ProgramContext* HydroModelsParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, HydroModelsParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    variablesStmt();
    setState(33);
    inputStmt();
    setState(35);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HydroModelsParser::OUTPUT) {
      setState(34);
      outputStmt();
    }
    setState(38); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(37);
      modelStmt();
      setState(40); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == HydroModelsParser::MODEL);
    setState(42);
    match(HydroModelsParser::END);
    setState(43);
    match(HydroModelsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InputStmtContext ------------------------------------------------------------------

HydroModelsParser::InputStmtContext::InputStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::InputStmtContext::INPUT() {
  return getToken(HydroModelsParser::INPUT, 0);
}

tree::TerminalNode* HydroModelsParser::InputStmtContext::LEFT_BRACE() {
  return getToken(HydroModelsParser::LEFT_BRACE, 0);
}

tree::TerminalNode* HydroModelsParser::InputStmtContext::RIGHT_BRACE() {
  return getToken(HydroModelsParser::RIGHT_BRACE, 0);
}

std::vector<HydroModelsParser::VarDeclContext *> HydroModelsParser::InputStmtContext::varDecl() {
  return getRuleContexts<HydroModelsParser::VarDeclContext>();
}

HydroModelsParser::VarDeclContext* HydroModelsParser::InputStmtContext::varDecl(size_t i) {
  return getRuleContext<HydroModelsParser::VarDeclContext>(i);
}


size_t HydroModelsParser::InputStmtContext::getRuleIndex() const {
  return HydroModelsParser::RuleInputStmt;
}


antlrcpp::Any HydroModelsParser::InputStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitInputStmt(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::InputStmtContext* HydroModelsParser::inputStmt() {
  InputStmtContext *_localctx = _tracker.createInstance<InputStmtContext>(_ctx, getState());
  enterRule(_localctx, 2, HydroModelsParser::RuleInputStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(HydroModelsParser::INPUT);
    setState(46);
    match(HydroModelsParser::LEFT_BRACE);
    setState(48); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(47);
      varDecl();
      setState(50); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == HydroModelsParser::IDENTIFIER);
    setState(52);
    match(HydroModelsParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

HydroModelsParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::VarDeclContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

tree::TerminalNode* HydroModelsParser::VarDeclContext::EQUAL() {
  return getToken(HydroModelsParser::EQUAL, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::VarDeclContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::VarDeclContext::SEMICOLON() {
  return getToken(HydroModelsParser::SEMICOLON, 0);
}


size_t HydroModelsParser::VarDeclContext::getRuleIndex() const {
  return HydroModelsParser::RuleVarDecl;
}


antlrcpp::Any HydroModelsParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::VarDeclContext* HydroModelsParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, HydroModelsParser::RuleVarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(HydroModelsParser::IDENTIFIER);
    setState(55);
    match(HydroModelsParser::EQUAL);
    setState(56);
    expression();
    setState(57);
    match(HydroModelsParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesStmtContext ------------------------------------------------------------------

HydroModelsParser::VariablesStmtContext::VariablesStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::VariablesStmtContext::VARIABLES() {
  return getToken(HydroModelsParser::VARIABLES, 0);
}

tree::TerminalNode* HydroModelsParser::VariablesStmtContext::LEFT_BRACE() {
  return getToken(HydroModelsParser::LEFT_BRACE, 0);
}

tree::TerminalNode* HydroModelsParser::VariablesStmtContext::RIGHT_BRACE() {
  return getToken(HydroModelsParser::RIGHT_BRACE, 0);
}

std::vector<HydroModelsParser::VarassignmentsContext *> HydroModelsParser::VariablesStmtContext::varassignments() {
  return getRuleContexts<HydroModelsParser::VarassignmentsContext>();
}

HydroModelsParser::VarassignmentsContext* HydroModelsParser::VariablesStmtContext::varassignments(size_t i) {
  return getRuleContext<HydroModelsParser::VarassignmentsContext>(i);
}

std::vector<tree::TerminalNode *> HydroModelsParser::VariablesStmtContext::SEMICOLON() {
  return getTokens(HydroModelsParser::SEMICOLON);
}

tree::TerminalNode* HydroModelsParser::VariablesStmtContext::SEMICOLON(size_t i) {
  return getToken(HydroModelsParser::SEMICOLON, i);
}


size_t HydroModelsParser::VariablesStmtContext::getRuleIndex() const {
  return HydroModelsParser::RuleVariablesStmt;
}


antlrcpp::Any HydroModelsParser::VariablesStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitVariablesStmt(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::VariablesStmtContext* HydroModelsParser::variablesStmt() {
  VariablesStmtContext *_localctx = _tracker.createInstance<VariablesStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, HydroModelsParser::RuleVariablesStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(HydroModelsParser::VARIABLES);
    setState(60);
    match(HydroModelsParser::LEFT_BRACE);
    setState(64); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(61);
      varassignments();
      setState(62);
      match(HydroModelsParser::SEMICOLON);
      setState(66); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == HydroModelsParser::IDENTIFIER);
    setState(68);
    match(HydroModelsParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModelStmtContext ------------------------------------------------------------------

HydroModelsParser::ModelStmtContext::ModelStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::ModelStmtContext::MODEL() {
  return getToken(HydroModelsParser::MODEL, 0);
}

tree::TerminalNode* HydroModelsParser::ModelStmtContext::STRING() {
  return getToken(HydroModelsParser::STRING, 0);
}

tree::TerminalNode* HydroModelsParser::ModelStmtContext::LEFT_BRACE() {
  return getToken(HydroModelsParser::LEFT_BRACE, 0);
}

HydroModelsParser::EquationsStmtContext* HydroModelsParser::ModelStmtContext::equationsStmt() {
  return getRuleContext<HydroModelsParser::EquationsStmtContext>(0);
}

tree::TerminalNode* HydroModelsParser::ModelStmtContext::RIGHT_BRACE() {
  return getToken(HydroModelsParser::RIGHT_BRACE, 0);
}

HydroModelsParser::ParametersStmtContext* HydroModelsParser::ModelStmtContext::parametersStmt() {
  return getRuleContext<HydroModelsParser::ParametersStmtContext>(0);
}

HydroModelsParser::OutputStmtContext* HydroModelsParser::ModelStmtContext::outputStmt() {
  return getRuleContext<HydroModelsParser::OutputStmtContext>(0);
}


size_t HydroModelsParser::ModelStmtContext::getRuleIndex() const {
  return HydroModelsParser::RuleModelStmt;
}


antlrcpp::Any HydroModelsParser::ModelStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitModelStmt(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::ModelStmtContext* HydroModelsParser::modelStmt() {
  ModelStmtContext *_localctx = _tracker.createInstance<ModelStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, HydroModelsParser::RuleModelStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(HydroModelsParser::MODEL);
    setState(71);
    match(HydroModelsParser::STRING);
    setState(72);
    match(HydroModelsParser::LEFT_BRACE);
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HydroModelsParser::PARAMETERS) {
      setState(73);
      parametersStmt();
    }
    setState(76);
    equationsStmt();
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HydroModelsParser::OUTPUT) {
      setState(77);
      outputStmt();
    }
    setState(80);
    match(HydroModelsParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersStmtContext ------------------------------------------------------------------

HydroModelsParser::ParametersStmtContext::ParametersStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::ParametersStmtContext::PARAMETERS() {
  return getToken(HydroModelsParser::PARAMETERS, 0);
}

tree::TerminalNode* HydroModelsParser::ParametersStmtContext::LEFT_BRACE() {
  return getToken(HydroModelsParser::LEFT_BRACE, 0);
}

tree::TerminalNode* HydroModelsParser::ParametersStmtContext::RIGHT_BRACE() {
  return getToken(HydroModelsParser::RIGHT_BRACE, 0);
}

std::vector<HydroModelsParser::VarDeclContext *> HydroModelsParser::ParametersStmtContext::varDecl() {
  return getRuleContexts<HydroModelsParser::VarDeclContext>();
}

HydroModelsParser::VarDeclContext* HydroModelsParser::ParametersStmtContext::varDecl(size_t i) {
  return getRuleContext<HydroModelsParser::VarDeclContext>(i);
}


size_t HydroModelsParser::ParametersStmtContext::getRuleIndex() const {
  return HydroModelsParser::RuleParametersStmt;
}


antlrcpp::Any HydroModelsParser::ParametersStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitParametersStmt(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::ParametersStmtContext* HydroModelsParser::parametersStmt() {
  ParametersStmtContext *_localctx = _tracker.createInstance<ParametersStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, HydroModelsParser::RuleParametersStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(HydroModelsParser::PARAMETERS);
    setState(83);
    match(HydroModelsParser::LEFT_BRACE);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HydroModelsParser::IDENTIFIER) {
      setState(84);
      varDecl();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(HydroModelsParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarassignmentsContext ------------------------------------------------------------------

HydroModelsParser::VarassignmentsContext::VarassignmentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::VarassignmentsContext::getRuleIndex() const {
  return HydroModelsParser::RuleVarassignments;
}

void HydroModelsParser::VarassignmentsContext::copyFrom(VarassignmentsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdWithDefaultContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::DEFAULT() {
  return getToken(HydroModelsParser::DEFAULT, 0);
}

std::vector<tree::TerminalNode *> HydroModelsParser::IdWithDefaultContext::EQUAL() {
  return getTokens(HydroModelsParser::EQUAL);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::EQUAL(size_t i) {
  return getToken(HydroModelsParser::EQUAL, i);
}

std::vector<HydroModelsParser::ExpressionContext *> HydroModelsParser::IdWithDefaultContext::expression() {
  return getRuleContexts<HydroModelsParser::ExpressionContext>();
}

HydroModelsParser::ExpressionContext* HydroModelsParser::IdWithDefaultContext::expression(size_t i) {
  return getRuleContext<HydroModelsParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> HydroModelsParser::IdWithDefaultContext::COMMA() {
  return getTokens(HydroModelsParser::COMMA);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::COMMA(size_t i) {
  return getToken(HydroModelsParser::COMMA, i);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::LOWER() {
  return getToken(HydroModelsParser::LOWER, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::UPPER() {
  return getToken(HydroModelsParser::UPPER, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithDefaultContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::IdWithDefaultContext::IdWithDefaultContext(VarassignmentsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::IdWithDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitIdWithDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdWithouDefaultContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::LOWER() {
  return getToken(HydroModelsParser::LOWER, 0);
}

std::vector<tree::TerminalNode *> HydroModelsParser::IdWithouDefaultContext::EQUAL() {
  return getTokens(HydroModelsParser::EQUAL);
}

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::EQUAL(size_t i) {
  return getToken(HydroModelsParser::EQUAL, i);
}

std::vector<HydroModelsParser::ExpressionContext *> HydroModelsParser::IdWithouDefaultContext::expression() {
  return getRuleContexts<HydroModelsParser::ExpressionContext>();
}

HydroModelsParser::ExpressionContext* HydroModelsParser::IdWithouDefaultContext::expression(size_t i) {
  return getRuleContext<HydroModelsParser::ExpressionContext>(i);
}

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::COMMA() {
  return getToken(HydroModelsParser::COMMA, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::UPPER() {
  return getToken(HydroModelsParser::UPPER, 0);
}

tree::TerminalNode* HydroModelsParser::IdWithouDefaultContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::IdWithouDefaultContext::IdWithouDefaultContext(VarassignmentsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::IdWithouDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitIdWithouDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdEqualsExprContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::IdEqualsExprContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

tree::TerminalNode* HydroModelsParser::IdEqualsExprContext::EQUAL() {
  return getToken(HydroModelsParser::EQUAL, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::IdEqualsExprContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

HydroModelsParser::IdEqualsExprContext::IdEqualsExprContext(VarassignmentsContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::IdEqualsExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitIdEqualsExpr(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::VarassignmentsContext* HydroModelsParser::varassignments() {
  VarassignmentsContext *_localctx = _tracker.createInstance<VarassignmentsContext>(_ctx, getState());
  enterRule(_localctx, 12, HydroModelsParser::RuleVarassignments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarassignmentsContext *>(_tracker.createInstance<HydroModelsParser::IdEqualsExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(92);
      match(HydroModelsParser::IDENTIFIER);
      setState(93);
      match(HydroModelsParser::EQUAL);
      setState(94);
      expression();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarassignmentsContext *>(_tracker.createInstance<HydroModelsParser::IdWithDefaultContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(95);
      match(HydroModelsParser::IDENTIFIER);
      setState(96);
      match(HydroModelsParser::LEFT_PAREN);
      setState(97);
      match(HydroModelsParser::DEFAULT);
      setState(98);
      match(HydroModelsParser::EQUAL);
      setState(99);
      expression();
      setState(100);
      match(HydroModelsParser::COMMA);
      setState(101);
      match(HydroModelsParser::LOWER);
      setState(102);
      match(HydroModelsParser::EQUAL);
      setState(103);
      expression();
      setState(104);
      match(HydroModelsParser::COMMA);
      setState(105);
      match(HydroModelsParser::UPPER);
      setState(106);
      match(HydroModelsParser::EQUAL);
      setState(107);
      expression();
      setState(108);
      match(HydroModelsParser::RIGHT_PAREN);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarassignmentsContext *>(_tracker.createInstance<HydroModelsParser::IdWithDefaultContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(110);
      match(HydroModelsParser::IDENTIFIER);
      setState(111);
      match(HydroModelsParser::LEFT_PAREN);
      setState(112);
      expression();
      setState(113);
      match(HydroModelsParser::COMMA);
      setState(114);
      expression();
      setState(115);
      match(HydroModelsParser::COMMA);
      setState(116);
      expression();
      setState(117);
      match(HydroModelsParser::RIGHT_PAREN);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<VarassignmentsContext *>(_tracker.createInstance<HydroModelsParser::IdWithouDefaultContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(119);
      match(HydroModelsParser::IDENTIFIER);
      setState(120);
      match(HydroModelsParser::LEFT_PAREN);
      setState(121);
      match(HydroModelsParser::LOWER);
      setState(122);
      match(HydroModelsParser::EQUAL);
      setState(123);
      expression();
      setState(124);
      match(HydroModelsParser::COMMA);
      setState(125);
      match(HydroModelsParser::UPPER);
      setState(126);
      match(HydroModelsParser::EQUAL);
      setState(127);
      expression();
      setState(128);
      match(HydroModelsParser::RIGHT_PAREN);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<VarassignmentsContext *>(_tracker.createInstance<HydroModelsParser::IdWithouDefaultContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(130);
      match(HydroModelsParser::IDENTIFIER);
      setState(131);
      match(HydroModelsParser::LEFT_PAREN);
      setState(132);
      expression();
      setState(133);
      match(HydroModelsParser::COMMA);
      setState(134);
      expression();
      setState(135);
      match(HydroModelsParser::RIGHT_PAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EquationsStmtContext ------------------------------------------------------------------

HydroModelsParser::EquationsStmtContext::EquationsStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::EquationsStmtContext::EQUATIONS() {
  return getToken(HydroModelsParser::EQUATIONS, 0);
}

tree::TerminalNode* HydroModelsParser::EquationsStmtContext::LEFT_BRACE() {
  return getToken(HydroModelsParser::LEFT_BRACE, 0);
}

tree::TerminalNode* HydroModelsParser::EquationsStmtContext::RIGHT_BRACE() {
  return getToken(HydroModelsParser::RIGHT_BRACE, 0);
}

std::vector<HydroModelsParser::EquationassignContext *> HydroModelsParser::EquationsStmtContext::equationassign() {
  return getRuleContexts<HydroModelsParser::EquationassignContext>();
}

HydroModelsParser::EquationassignContext* HydroModelsParser::EquationsStmtContext::equationassign(size_t i) {
  return getRuleContext<HydroModelsParser::EquationassignContext>(i);
}

std::vector<tree::TerminalNode *> HydroModelsParser::EquationsStmtContext::SEMICOLON() {
  return getTokens(HydroModelsParser::SEMICOLON);
}

tree::TerminalNode* HydroModelsParser::EquationsStmtContext::SEMICOLON(size_t i) {
  return getToken(HydroModelsParser::SEMICOLON, i);
}


size_t HydroModelsParser::EquationsStmtContext::getRuleIndex() const {
  return HydroModelsParser::RuleEquationsStmt;
}


antlrcpp::Any HydroModelsParser::EquationsStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitEquationsStmt(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::EquationsStmtContext* HydroModelsParser::equationsStmt() {
  EquationsStmtContext *_localctx = _tracker.createInstance<EquationsStmtContext>(_ctx, getState());
  enterRule(_localctx, 14, HydroModelsParser::RuleEquationsStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(HydroModelsParser::EQUATIONS);
    setState(140);
    match(HydroModelsParser::LEFT_BRACE);
    setState(144); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(141);
      equationassign();
      setState(142);
      match(HydroModelsParser::SEMICOLON);
      setState(146); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << HydroModelsParser::LN)
      | (1ULL << HydroModelsParser::LOG10)
      | (1ULL << HydroModelsParser::POWERFUNC)
      | (1ULL << HydroModelsParser::EXP)
      | (1ULL << HydroModelsParser::COS)
      | (1ULL << HydroModelsParser::SIN)
      | (1ULL << HydroModelsParser::LEFT_PAREN)
      | (1ULL << HydroModelsParser::MINUS)
      | (1ULL << HydroModelsParser::PLUS)
      | (1ULL << HydroModelsParser::IDENTIFIER)
      | (1ULL << HydroModelsParser::NUMBER))) != 0));
    setState(148);
    match(HydroModelsParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EquationassignContext ------------------------------------------------------------------

HydroModelsParser::EquationassignContext::EquationassignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::EquationassignContext::getRuleIndex() const {
  return HydroModelsParser::RuleEquationassign;
}

void HydroModelsParser::EquationassignContext::copyFrom(EquationassignContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EquationAssignOneExpressionContext ------------------------------------------------------------------

HydroModelsParser::ExpressionContext* HydroModelsParser::EquationAssignOneExpressionContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

HydroModelsParser::EquationAssignOneExpressionContext::EquationAssignOneExpressionContext(EquationassignContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::EquationAssignOneExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitEquationAssignOneExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EquationAssignEqualContext ------------------------------------------------------------------

std::vector<HydroModelsParser::ExpressionContext *> HydroModelsParser::EquationAssignEqualContext::expression() {
  return getRuleContexts<HydroModelsParser::ExpressionContext>();
}

HydroModelsParser::ExpressionContext* HydroModelsParser::EquationAssignEqualContext::expression(size_t i) {
  return getRuleContext<HydroModelsParser::ExpressionContext>(i);
}

tree::TerminalNode* HydroModelsParser::EquationAssignEqualContext::EQUAL() {
  return getToken(HydroModelsParser::EQUAL, 0);
}

HydroModelsParser::EquationAssignEqualContext::EquationAssignEqualContext(EquationassignContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::EquationAssignEqualContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitEquationAssignEqual(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::EquationassignContext* HydroModelsParser::equationassign() {
  EquationassignContext *_localctx = _tracker.createInstance<EquationassignContext>(_ctx, getState());
  enterRule(_localctx, 16, HydroModelsParser::RuleEquationassign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<EquationassignContext *>(_tracker.createInstance<HydroModelsParser::EquationAssignEqualContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(150);
      expression();
      setState(151);
      match(HydroModelsParser::EQUAL);
      setState(152);
      expression();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<EquationassignContext *>(_tracker.createInstance<HydroModelsParser::EquationAssignOneExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(154);
      expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputStmtContext ------------------------------------------------------------------

HydroModelsParser::OutputStmtContext::OutputStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HydroModelsParser::OutputStmtContext::OUTPUT() {
  return getToken(HydroModelsParser::OUTPUT, 0);
}

tree::TerminalNode* HydroModelsParser::OutputStmtContext::LEFT_BRACE() {
  return getToken(HydroModelsParser::LEFT_BRACE, 0);
}

tree::TerminalNode* HydroModelsParser::OutputStmtContext::RIGHT_BRACE() {
  return getToken(HydroModelsParser::RIGHT_BRACE, 0);
}

std::vector<HydroModelsParser::OutputDeclContext *> HydroModelsParser::OutputStmtContext::outputDecl() {
  return getRuleContexts<HydroModelsParser::OutputDeclContext>();
}

HydroModelsParser::OutputDeclContext* HydroModelsParser::OutputStmtContext::outputDecl(size_t i) {
  return getRuleContext<HydroModelsParser::OutputDeclContext>(i);
}


size_t HydroModelsParser::OutputStmtContext::getRuleIndex() const {
  return HydroModelsParser::RuleOutputStmt;
}


antlrcpp::Any HydroModelsParser::OutputStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitOutputStmt(this);
  else
    return visitor->visitChildren(this);
}

HydroModelsParser::OutputStmtContext* HydroModelsParser::outputStmt() {
  OutputStmtContext *_localctx = _tracker.createInstance<OutputStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, HydroModelsParser::RuleOutputStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(HydroModelsParser::OUTPUT);
    setState(158);
    match(HydroModelsParser::LEFT_BRACE);
    setState(160); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(159);
      outputDecl();
      setState(162); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == HydroModelsParser::STRING);
    setState(164);
    match(HydroModelsParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputDeclContext ------------------------------------------------------------------

HydroModelsParser::OutputDeclContext::OutputDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::OutputDeclContext::getRuleIndex() const {
  return HydroModelsParser::RuleOutputDecl;
}

void HydroModelsParser::OutputDeclContext::copyFrom(OutputDeclContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OutputDeclWithMulContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::OutputDeclWithMulContext::STRING() {
  return getToken(HydroModelsParser::STRING, 0);
}

std::vector<tree::TerminalNode *> HydroModelsParser::OutputDeclWithMulContext::COMMA() {
  return getTokens(HydroModelsParser::COMMA);
}

tree::TerminalNode* HydroModelsParser::OutputDeclWithMulContext::COMMA(size_t i) {
  return getToken(HydroModelsParser::COMMA, i);
}

tree::TerminalNode* HydroModelsParser::OutputDeclWithMulContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::OutputDeclWithMulContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::OutputDeclWithMulContext::SEMICOLON() {
  return getToken(HydroModelsParser::SEMICOLON, 0);
}

HydroModelsParser::OutputDeclWithMulContext::OutputDeclWithMulContext(OutputDeclContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::OutputDeclWithMulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitOutputDeclWithMul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OutputDeclWithoutMulContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::OutputDeclWithoutMulContext::STRING() {
  return getToken(HydroModelsParser::STRING, 0);
}

tree::TerminalNode* HydroModelsParser::OutputDeclWithoutMulContext::COMMA() {
  return getToken(HydroModelsParser::COMMA, 0);
}

tree::TerminalNode* HydroModelsParser::OutputDeclWithoutMulContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

tree::TerminalNode* HydroModelsParser::OutputDeclWithoutMulContext::SEMICOLON() {
  return getToken(HydroModelsParser::SEMICOLON, 0);
}

HydroModelsParser::OutputDeclWithoutMulContext::OutputDeclWithoutMulContext(OutputDeclContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::OutputDeclWithoutMulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitOutputDeclWithoutMul(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::OutputDeclContext* HydroModelsParser::outputDecl() {
  OutputDeclContext *_localctx = _tracker.createInstance<OutputDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, HydroModelsParser::RuleOutputDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<OutputDeclContext *>(_tracker.createInstance<HydroModelsParser::OutputDeclWithoutMulContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(166);
      match(HydroModelsParser::STRING);
      setState(167);
      match(HydroModelsParser::COMMA);
      setState(168);
      match(HydroModelsParser::IDENTIFIER);
      setState(169);
      match(HydroModelsParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<OutputDeclContext *>(_tracker.createInstance<HydroModelsParser::OutputDeclWithMulContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(170);
      match(HydroModelsParser::STRING);
      setState(171);
      match(HydroModelsParser::COMMA);
      setState(172);
      match(HydroModelsParser::IDENTIFIER);
      setState(173);
      match(HydroModelsParser::COMMA);
      setState(174);
      expression();
      setState(175);
      match(HydroModelsParser::SEMICOLON);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

HydroModelsParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::ExpressionContext::getRuleIndex() const {
  return HydroModelsParser::RuleExpression;
}

void HydroModelsParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprRecursiveContext ------------------------------------------------------------------

HydroModelsParser::TermContext* HydroModelsParser::ExprRecursiveContext::term() {
  return getRuleContext<HydroModelsParser::TermContext>(0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::ExprRecursiveContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::ExprRecursiveContext::PLUS() {
  return getToken(HydroModelsParser::PLUS, 0);
}

tree::TerminalNode* HydroModelsParser::ExprRecursiveContext::MINUS() {
  return getToken(HydroModelsParser::MINUS, 0);
}

HydroModelsParser::ExprRecursiveContext::ExprRecursiveContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::ExprRecursiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitExprRecursive(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTermContext ------------------------------------------------------------------

HydroModelsParser::TermContext* HydroModelsParser::ExprTermContext::term() {
  return getRuleContext<HydroModelsParser::TermContext>(0);
}

HydroModelsParser::ExprTermContext::ExprTermContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::ExprTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitExprTerm(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::ExpressionContext* HydroModelsParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 22, HydroModelsParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<HydroModelsParser::ExprRecursiveContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(179);
      term();
      setState(180);
      dynamic_cast<ExprRecursiveContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == HydroModelsParser::MINUS

      || _la == HydroModelsParser::PLUS)) {
        dynamic_cast<ExprRecursiveContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(181);
      expression();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<HydroModelsParser::ExprTermContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(183);
      term();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

HydroModelsParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::TermContext::getRuleIndex() const {
  return HydroModelsParser::RuleTerm;
}

void HydroModelsParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TermFactorSTARSLASHtermContext ------------------------------------------------------------------

HydroModelsParser::FactorContext* HydroModelsParser::TermFactorSTARSLASHtermContext::factor() {
  return getRuleContext<HydroModelsParser::FactorContext>(0);
}

HydroModelsParser::TermContext* HydroModelsParser::TermFactorSTARSLASHtermContext::term() {
  return getRuleContext<HydroModelsParser::TermContext>(0);
}

tree::TerminalNode* HydroModelsParser::TermFactorSTARSLASHtermContext::STAR() {
  return getToken(HydroModelsParser::STAR, 0);
}

tree::TerminalNode* HydroModelsParser::TermFactorSTARSLASHtermContext::SLASH() {
  return getToken(HydroModelsParser::SLASH, 0);
}

HydroModelsParser::TermFactorSTARSLASHtermContext::TermFactorSTARSLASHtermContext(TermContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::TermFactorSTARSLASHtermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitTermFactorSTARSLASHterm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TermFactorContext ------------------------------------------------------------------

HydroModelsParser::FactorContext* HydroModelsParser::TermFactorContext::factor() {
  return getRuleContext<HydroModelsParser::FactorContext>(0);
}

HydroModelsParser::TermFactorContext::TermFactorContext(TermContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::TermFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitTermFactor(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::TermContext* HydroModelsParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 24, HydroModelsParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<TermContext *>(_tracker.createInstance<HydroModelsParser::TermFactorSTARSLASHtermContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(186);
      factor();
      setState(187);
      dynamic_cast<TermFactorSTARSLASHtermContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == HydroModelsParser::SLASH

      || _la == HydroModelsParser::STAR)) {
        dynamic_cast<TermFactorSTARSLASHtermContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(188);
      term();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<TermContext *>(_tracker.createInstance<HydroModelsParser::TermFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(190);
      factor();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

HydroModelsParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::FactorContext::getRuleIndex() const {
  return HydroModelsParser::RuleFactor;
}

void HydroModelsParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryFactorContext ------------------------------------------------------------------

HydroModelsParser::FactorContext* HydroModelsParser::UnaryFactorContext::factor() {
  return getRuleContext<HydroModelsParser::FactorContext>(0);
}

tree::TerminalNode* HydroModelsParser::UnaryFactorContext::PLUS() {
  return getToken(HydroModelsParser::PLUS, 0);
}

tree::TerminalNode* HydroModelsParser::UnaryFactorContext::MINUS() {
  return getToken(HydroModelsParser::MINUS, 0);
}

HydroModelsParser::UnaryFactorContext::UnaryFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::UnaryFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitUnaryFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorEqualsPowerContext ------------------------------------------------------------------

HydroModelsParser::PowerContext* HydroModelsParser::FactorEqualsPowerContext::power() {
  return getRuleContext<HydroModelsParser::PowerContext>(0);
}

HydroModelsParser::FactorEqualsPowerContext::FactorEqualsPowerContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::FactorEqualsPowerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitFactorEqualsPower(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::FactorContext* HydroModelsParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 26, HydroModelsParser::RuleFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HydroModelsParser::MINUS:
      case HydroModelsParser::PLUS: {
        _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<HydroModelsParser::UnaryFactorContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(193);
        dynamic_cast<UnaryFactorContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == HydroModelsParser::MINUS

        || _la == HydroModelsParser::PLUS)) {
          dynamic_cast<UnaryFactorContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(194);
        factor();
        break;
      }

      case HydroModelsParser::LN:
      case HydroModelsParser::LOG10:
      case HydroModelsParser::POWERFUNC:
      case HydroModelsParser::EXP:
      case HydroModelsParser::COS:
      case HydroModelsParser::SIN:
      case HydroModelsParser::LEFT_PAREN:
      case HydroModelsParser::IDENTIFIER:
      case HydroModelsParser::NUMBER: {
        _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<HydroModelsParser::FactorEqualsPowerContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(195);
        power();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowerContext ------------------------------------------------------------------

HydroModelsParser::PowerContext::PowerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::PowerContext::getRuleIndex() const {
  return HydroModelsParser::RulePower;
}

void HydroModelsParser::PowerContext::copyFrom(PowerContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PowerAtomContext ------------------------------------------------------------------

HydroModelsParser::AtomContext* HydroModelsParser::PowerAtomContext::atom() {
  return getRuleContext<HydroModelsParser::AtomContext>(0);
}

HydroModelsParser::PowerAtomContext::PowerAtomContext(PowerContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::PowerAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitPowerAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerAtomPowerFactorContext ------------------------------------------------------------------

HydroModelsParser::AtomContext* HydroModelsParser::PowerAtomPowerFactorContext::atom() {
  return getRuleContext<HydroModelsParser::AtomContext>(0);
}

tree::TerminalNode* HydroModelsParser::PowerAtomPowerFactorContext::POWER_OP() {
  return getToken(HydroModelsParser::POWER_OP, 0);
}

HydroModelsParser::FactorContext* HydroModelsParser::PowerAtomPowerFactorContext::factor() {
  return getRuleContext<HydroModelsParser::FactorContext>(0);
}

HydroModelsParser::PowerAtomPowerFactorContext::PowerAtomPowerFactorContext(PowerContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::PowerAtomPowerFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitPowerAtomPowerFactor(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::PowerContext* HydroModelsParser::power() {
  PowerContext *_localctx = _tracker.createInstance<PowerContext>(_ctx, getState());
  enterRule(_localctx, 28, HydroModelsParser::RulePower);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PowerContext *>(_tracker.createInstance<HydroModelsParser::PowerAtomPowerFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(198);
      atom();
      setState(199);
      match(HydroModelsParser::POWER_OP);
      setState(200);
      factor();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PowerContext *>(_tracker.createInstance<HydroModelsParser::PowerAtomContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(202);
      atom();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

HydroModelsParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t HydroModelsParser::AtomContext::getRuleIndex() const {
  return HydroModelsParser::RuleAtom;
}

void HydroModelsParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AtomIDContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomIDContext::IDENTIFIER() {
  return getToken(HydroModelsParser::IDENTIFIER, 0);
}

HydroModelsParser::AtomIDContext::AtomIDContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomID(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomExpContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomExpContext::EXP() {
  return getToken(HydroModelsParser::EXP, 0);
}

tree::TerminalNode* HydroModelsParser::AtomExpContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomExpContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::AtomExpContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomExpContext::AtomExpContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomNumberContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomNumberContext::NUMBER() {
  return getToken(HydroModelsParser::NUMBER, 0);
}

HydroModelsParser::AtomNumberContext::AtomNumberContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomPowerFuncContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomPowerFuncContext::POWERFUNC() {
  return getToken(HydroModelsParser::POWERFUNC, 0);
}

tree::TerminalNode* HydroModelsParser::AtomPowerFuncContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

std::vector<HydroModelsParser::ExpressionContext *> HydroModelsParser::AtomPowerFuncContext::expression() {
  return getRuleContexts<HydroModelsParser::ExpressionContext>();
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomPowerFuncContext::expression(size_t i) {
  return getRuleContext<HydroModelsParser::ExpressionContext>(i);
}

tree::TerminalNode* HydroModelsParser::AtomPowerFuncContext::COMMA() {
  return getToken(HydroModelsParser::COMMA, 0);
}

tree::TerminalNode* HydroModelsParser::AtomPowerFuncContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomPowerFuncContext::AtomPowerFuncContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomPowerFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomPowerFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomSinContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomSinContext::SIN() {
  return getToken(HydroModelsParser::SIN, 0);
}

tree::TerminalNode* HydroModelsParser::AtomSinContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomSinContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::AtomSinContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomSinContext::AtomSinContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomSinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomSin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomCosContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomCosContext::COS() {
  return getToken(HydroModelsParser::COS, 0);
}

tree::TerminalNode* HydroModelsParser::AtomCosContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomCosContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::AtomCosContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomCosContext::AtomCosContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomCosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomCos(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomLnContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomLnContext::LN() {
  return getToken(HydroModelsParser::LN, 0);
}

tree::TerminalNode* HydroModelsParser::AtomLnContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomLnContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::AtomLnContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomLnContext::AtomLnContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomLnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomLn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomLog10Context ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomLog10Context::LOG10() {
  return getToken(HydroModelsParser::LOG10, 0);
}

tree::TerminalNode* HydroModelsParser::AtomLog10Context::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomLog10Context::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::AtomLog10Context::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomLog10Context::AtomLog10Context(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomLog10Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomLog10(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* HydroModelsParser::AtomParenthesisContext::LEFT_PAREN() {
  return getToken(HydroModelsParser::LEFT_PAREN, 0);
}

HydroModelsParser::ExpressionContext* HydroModelsParser::AtomParenthesisContext::expression() {
  return getRuleContext<HydroModelsParser::ExpressionContext>(0);
}

tree::TerminalNode* HydroModelsParser::AtomParenthesisContext::RIGHT_PAREN() {
  return getToken(HydroModelsParser::RIGHT_PAREN, 0);
}

HydroModelsParser::AtomParenthesisContext::AtomParenthesisContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any HydroModelsParser::AtomParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<HydroModelsVisitor*>(visitor))
    return parserVisitor->visitAtomParenthesis(this);
  else
    return visitor->visitChildren(this);
}
HydroModelsParser::AtomContext* HydroModelsParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 30, HydroModelsParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case HydroModelsParser::IDENTIFIER: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomIDContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(205);
        match(HydroModelsParser::IDENTIFIER);
        break;
      }

      case HydroModelsParser::NUMBER: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomNumberContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(206);
        match(HydroModelsParser::NUMBER);
        break;
      }

      case HydroModelsParser::COS: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomCosContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(207);
        match(HydroModelsParser::COS);
        setState(208);
        match(HydroModelsParser::LEFT_PAREN);
        setState(209);
        expression();
        setState(210);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

      case HydroModelsParser::SIN: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomSinContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(212);
        match(HydroModelsParser::SIN);
        setState(213);
        match(HydroModelsParser::LEFT_PAREN);
        setState(214);
        expression();
        setState(215);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

      case HydroModelsParser::EXP: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomExpContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(217);
        match(HydroModelsParser::EXP);
        setState(218);
        match(HydroModelsParser::LEFT_PAREN);
        setState(219);
        expression();
        setState(220);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

      case HydroModelsParser::LN: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomLnContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(222);
        match(HydroModelsParser::LN);
        setState(223);
        match(HydroModelsParser::LEFT_PAREN);
        setState(224);
        expression();
        setState(225);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

      case HydroModelsParser::LOG10: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomLog10Context>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(227);
        match(HydroModelsParser::LOG10);
        setState(228);
        match(HydroModelsParser::LEFT_PAREN);
        setState(229);
        expression();
        setState(230);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

      case HydroModelsParser::POWERFUNC: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomPowerFuncContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(232);
        match(HydroModelsParser::POWERFUNC);
        setState(233);
        match(HydroModelsParser::LEFT_PAREN);
        setState(234);
        expression();
        setState(235);
        match(HydroModelsParser::COMMA);
        setState(236);
        expression();
        setState(237);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

      case HydroModelsParser::LEFT_PAREN: {
        _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<HydroModelsParser::AtomParenthesisContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(239);
        match(HydroModelsParser::LEFT_PAREN);
        setState(240);
        expression();
        setState(241);
        match(HydroModelsParser::RIGHT_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> HydroModelsParser::_decisionToDFA;
atn::PredictionContextCache HydroModelsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN HydroModelsParser::_atn;
std::vector<uint16_t> HydroModelsParser::_serializedATN;

std::vector<std::string> HydroModelsParser::_ruleNames = {
  "program", "inputStmt", "varDecl", "variablesStmt", "modelStmt", "parametersStmt", 
  "varassignments", "equationsStmt", "equationassign", "outputStmt", "outputDecl", 
  "expression", "term", "factor", "power", "atom"
};

std::vector<std::string> HydroModelsParser::_literalNames = {
  "", "'MODEL'", "'VARIABLES'", "'PARAMETERS'", "'EQUATIONS'", "'DEFAULT'", 
  "'LOWER'", "'UPPER'", "'INPUT'", "'OUTPUT'", "'END'", "", "'log10'", "'pow'", 
  "'exp'", "'cos'", "'sin'", "'('", "')'", "'{'", "'}'", "','", "'-'", "'+'", 
  "';'", "'/'", "'*'", "'='", "'^'"
};

std::vector<std::string> HydroModelsParser::_symbolicNames = {
  "", "MODEL", "VARIABLES", "PARAMETERS", "EQUATIONS", "DEFAULT", "LOWER", 
  "UPPER", "INPUT", "OUTPUT", "END", "LN", "LOG10", "POWERFUNC", "EXP", 
  "COS", "SIN", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE", 
  "COMMA", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR", "EQUAL", "POWER_OP", 
  "IDENTIFIER", "STRING", "NUMBER", "COMMENTS", "BLOCKCOMMENT", "WS"
};

dfa::Vocabulary HydroModelsParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> HydroModelsParser::_tokenNames;

HydroModelsParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x24, 0xf8, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x26, 0xa, 0x2, 0x3, 0x2, 0x6, 0x2, 0x29, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x2a, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x33, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0x34, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x43, 
    0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x44, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4d, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x51, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0x58, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x5b, 0xb, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x8c, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x93, 0xa, 
    0x9, 0xd, 0x9, 0xe, 0x9, 0x94, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x9e, 0xa, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x6, 0xb, 0xa3, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xa4, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb4, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0xbb, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0xc2, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc7, 0xa, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0xce, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0xf6, 0xa, 0x11, 0x3, 0x11, 0x2, 0x2, 0x12, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x2, 0x4, 0x3, 0x2, 0x18, 0x19, 0x3, 0x2, 0x1b, 0x1c, 0x2, 0x102, 
    0x2, 0x22, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x54, 0x3, 0x2, 0x2, 0x2, 0xe, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x18, 0xba, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x23, 0x5, 0x8, 0x5, 0x2, 0x23, 0x25, 0x5, 0x4, 0x3, 
    0x2, 0x24, 0x26, 0x5, 0x14, 0xb, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x29, 0x5, 0xa, 0x6, 0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0xc, 
    0x2, 0x2, 0x2d, 0x2e, 0x7, 0x2, 0x2, 0x3, 0x2e, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x30, 0x7, 0xa, 0x2, 0x2, 0x30, 0x32, 0x7, 0x15, 0x2, 0x2, 
    0x31, 0x33, 0x5, 0x6, 0x4, 0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 
    0x16, 0x2, 0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x1f, 
    0x2, 0x2, 0x39, 0x3a, 0x7, 0x1d, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x18, 0xd, 
    0x2, 0x3b, 0x3c, 0x7, 0x1a, 0x2, 0x2, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x3d, 0x3e, 0x7, 0x4, 0x2, 0x2, 0x3e, 0x42, 0x7, 0x15, 0x2, 0x2, 0x3f, 
    0x40, 0x5, 0xe, 0x8, 0x2, 0x40, 0x41, 0x7, 0x1a, 0x2, 0x2, 0x41, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x16, 0x2, 
    0x2, 0x47, 0x9, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x3, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x20, 0x2, 0x2, 0x4a, 0x4c, 0x7, 0x15, 0x2, 0x2, 0x4b, 
    0x4d, 0x5, 0xc, 0x7, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x5, 
    0x10, 0x9, 0x2, 0x4f, 0x51, 0x5, 0x14, 0xb, 0x2, 0x50, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x53, 0x7, 0x16, 0x2, 0x2, 0x53, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x7, 0x5, 0x2, 0x2, 0x55, 0x59, 0x7, 0x15, 0x2, 0x2, 0x56, 
    0x58, 0x5, 0x6, 0x4, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x5d, 0x7, 0x16, 0x2, 0x2, 0x5d, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5f, 0x7, 0x1f, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x1d, 0x2, 0x2, 
    0x60, 0x8c, 0x5, 0x18, 0xd, 0x2, 0x61, 0x62, 0x7, 0x1f, 0x2, 0x2, 0x62, 
    0x63, 0x7, 0x13, 0x2, 0x2, 0x63, 0x64, 0x7, 0x7, 0x2, 0x2, 0x64, 0x65, 
    0x7, 0x1d, 0x2, 0x2, 0x65, 0x66, 0x5, 0x18, 0xd, 0x2, 0x66, 0x67, 0x7, 
    0x17, 0x2, 0x2, 0x67, 0x68, 0x7, 0x8, 0x2, 0x2, 0x68, 0x69, 0x7, 0x1d, 
    0x2, 0x2, 0x69, 0x6a, 0x5, 0x18, 0xd, 0x2, 0x6a, 0x6b, 0x7, 0x17, 0x2, 
    0x2, 0x6b, 0x6c, 0x7, 0x9, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x1d, 0x2, 0x2, 
    0x6d, 0x6e, 0x5, 0x18, 0xd, 0x2, 0x6e, 0x6f, 0x7, 0x14, 0x2, 0x2, 0x6f, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x1f, 0x2, 0x2, 0x71, 0x72, 
    0x7, 0x13, 0x2, 0x2, 0x72, 0x73, 0x5, 0x18, 0xd, 0x2, 0x73, 0x74, 0x7, 
    0x17, 0x2, 0x2, 0x74, 0x75, 0x5, 0x18, 0xd, 0x2, 0x75, 0x76, 0x7, 0x17, 
    0x2, 0x2, 0x76, 0x77, 0x5, 0x18, 0xd, 0x2, 0x77, 0x78, 0x7, 0x14, 0x2, 
    0x2, 0x78, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x1f, 0x2, 0x2, 
    0x7a, 0x7b, 0x7, 0x13, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x8, 0x2, 0x2, 0x7c, 
    0x7d, 0x7, 0x1d, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x18, 0xd, 0x2, 0x7e, 0x7f, 
    0x7, 0x17, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x9, 0x2, 0x2, 0x80, 0x81, 0x7, 
    0x1d, 0x2, 0x2, 0x81, 0x82, 0x5, 0x18, 0xd, 0x2, 0x82, 0x83, 0x7, 0x14, 
    0x2, 0x2, 0x83, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x1f, 0x2, 
    0x2, 0x85, 0x86, 0x7, 0x13, 0x2, 0x2, 0x86, 0x87, 0x5, 0x18, 0xd, 0x2, 
    0x87, 0x88, 0x7, 0x17, 0x2, 0x2, 0x88, 0x89, 0x5, 0x18, 0xd, 0x2, 0x89, 
    0x8a, 0x7, 0x14, 0x2, 0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x61, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x6, 0x2, 
    0x2, 0x8e, 0x92, 0x7, 0x15, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x12, 0xa, 0x2, 
    0x90, 0x91, 0x7, 0x1a, 0x2, 0x2, 0x91, 0x93, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x16, 0x2, 0x2, 0x97, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0x5, 0x18, 0xd, 0x2, 0x99, 0x9a, 0x7, 0x1d, 0x2, 
    0x2, 0x9a, 0x9b, 0x5, 0x18, 0xd, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9e, 0x5, 0x18, 0xd, 0x2, 0x9d, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 
    0x7, 0xb, 0x2, 0x2, 0xa0, 0xa2, 0x7, 0x15, 0x2, 0x2, 0xa1, 0xa3, 0x5, 
    0x16, 0xc, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x16, 0x2, 0x2, 
    0xa7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x20, 0x2, 0x2, 0xa9, 
    0xaa, 0x7, 0x17, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x1f, 0x2, 0x2, 0xab, 0xb4, 
    0x7, 0x1a, 0x2, 0x2, 0xac, 0xad, 0x7, 0x20, 0x2, 0x2, 0xad, 0xae, 0x7, 
    0x17, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x1f, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x17, 
    0x2, 0x2, 0xb0, 0xb1, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xb2, 0x7, 0x1a, 0x2, 
    0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb6, 0x5, 0x1a, 0xe, 0x2, 0xb6, 0xb7, 0x9, 0x2, 0x2, 0x2, 0xb7, 0xb8, 
    0x5, 0x18, 0xd, 0x2, 0xb8, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbb, 0x5, 
    0x1a, 0xe, 0x2, 0xba, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0x19, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x1c, 0xf, 
    0x2, 0xbd, 0xbe, 0x9, 0x3, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x1a, 0xe, 0x2, 
    0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x1c, 0xf, 0x2, 0xc1, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x9, 0x2, 0x2, 0x2, 0xc4, 0xc7, 0x5, 
    0x1c, 0xf, 0x2, 0xc5, 0xc7, 0x5, 0x1e, 0x10, 0x2, 0xc6, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xc8, 0xc9, 0x5, 0x20, 0x11, 0x2, 0xc9, 0xca, 0x7, 0x1e, 0x2, 0x2, 
    0xca, 0xcb, 0x5, 0x1c, 0xf, 0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xce, 0x5, 0x20, 0x11, 0x2, 0xcd, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xf6, 0x7, 
    0x1f, 0x2, 0x2, 0xd0, 0xf6, 0x7, 0x21, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x11, 
    0x2, 0x2, 0xd2, 0xd3, 0x7, 0x13, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x18, 0xd, 
    0x2, 0xd4, 0xd5, 0x7, 0x14, 0x2, 0x2, 0xd5, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd7, 0x7, 0x12, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x13, 0x2, 0x2, 0xd8, 
    0xd9, 0x5, 0x18, 0xd, 0x2, 0xd9, 0xda, 0x7, 0x14, 0x2, 0x2, 0xda, 0xf6, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x10, 0x2, 0x2, 0xdc, 0xdd, 0x7, 
    0x13, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x18, 0xd, 0x2, 0xde, 0xdf, 0x7, 0x14, 
    0x2, 0x2, 0xdf, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0xd, 0x2, 
    0x2, 0xe1, 0xe2, 0x7, 0x13, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x18, 0xd, 0x2, 
    0xe3, 0xe4, 0x7, 0x14, 0x2, 0x2, 0xe4, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0xe6, 0x7, 0xe, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x13, 0x2, 0x2, 0xe7, 0xe8, 
    0x5, 0x18, 0xd, 0x2, 0xe8, 0xe9, 0x7, 0x14, 0x2, 0x2, 0xe9, 0xf6, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0xf, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x13, 
    0x2, 0x2, 0xec, 0xed, 0x5, 0x18, 0xd, 0x2, 0xed, 0xee, 0x7, 0x17, 0x2, 
    0x2, 0xee, 0xef, 0x5, 0x18, 0xd, 0x2, 0xef, 0xf0, 0x7, 0x14, 0x2, 0x2, 
    0xf0, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x13, 0x2, 0x2, 0xf2, 
    0xf3, 0x5, 0x18, 0xd, 0x2, 0xf3, 0xf4, 0x7, 0x14, 0x2, 0x2, 0xf4, 0xf6, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xe0, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x21, 0x3, 0x2, 0x2, 0x2, 0x13, 
    0x25, 0x2a, 0x34, 0x44, 0x4c, 0x50, 0x59, 0x8b, 0x94, 0x9d, 0xa4, 0xb3, 
    0xba, 0xc1, 0xc6, 0xcd, 0xf5, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

HydroModelsParser::Initializer HydroModelsParser::_init;
