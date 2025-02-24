#ifndef LEXER
#define LEXER

#include <string>
#include <vector>

namespace itp {

  enum class TOKEN_TYPES { DIGIT, VARIABLE, FUNCTION, OPERATOR, SYMBOL };

  enum class FUNCTION_TOKEN { SIN, COS, TAN, LOG, LN, SQRT, POW, EXP, ARCSIN, ARCCOS, ARCTAN };
  enum class OPERATOR_TOKEN { PLUS, MINUS, MULT, DIV, MODULO, EXP };
  enum class SYMBOL_TOKEN { LPAREN, RPAREN };

  struct Token {
    std::string value;
    TOKEN_TYPES t_type;
  };

  std::vector<Token> tokenize(std::string &input);
} // namespace itp

#endif