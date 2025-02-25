#ifndef LEXER
#define LEXER

#include <optional>
#include <string>
#include <vector>

namespace itp {

  enum class TOKEN_TYPES { DIGIT, VARIABLE, FUNCTION, OPERATOR, SYMBOL };

  enum class FUNCTION_TOKEN { SIN, COS, TAN, LOG, LN, SQRT, POW, EXP, ARCSIN, ARCCOS, ARCTAN };
  enum class OPERATOR_TOKEN { PLUS, MINUS, MULT, DIV, MODULO, EXP };
  enum class SYMBOL_TOKEN { LPAREN, RPAREN };

  const std::string operators = "+-*/%^";
  const std::string symbols = "()";

  struct Token {
    std::string value;
    TOKEN_TYPES t_type;
    std::optional<FUNCTION_TOKEN> func_token;
    std::optional<OPERATOR_TOKEN> oper_token;
    std::optional<SYMBOL_TOKEN> sym_token;
  };

  std::vector<Token> tokenize(std::string &input);
} // namespace itp

#endif