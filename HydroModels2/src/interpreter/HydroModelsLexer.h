
// Generated from HydroModels.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  HydroModelsLexer : public antlr4::Lexer {
public:
  enum {
    MODEL = 1, VARIABLES = 2, PARAMETERS = 3, EQUATIONS = 4, DEFAULT = 5, 
    LOWER = 6, UPPER = 7, INPUT = 8, OUTPUT = 9, END = 10, LN = 11, LOG10 = 12, 
    POWERFUNC = 13, EXP = 14, COS = 15, SIN = 16, LEFT_PAREN = 17, RIGHT_PAREN = 18, 
    LEFT_BRACE = 19, RIGHT_BRACE = 20, COMMA = 21, MINUS = 22, PLUS = 23, 
    SEMICOLON = 24, SLASH = 25, STAR = 26, EQUAL = 27, POWER_OP = 28, IDENTIFIER = 29, 
    STRING = 30, NUMBER = 31, COMMENTS = 32, BLOCKCOMMENT = 33, WS = 34
  };

  HydroModelsLexer(antlr4::CharStream *input);
  ~HydroModelsLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

