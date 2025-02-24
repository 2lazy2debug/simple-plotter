#include "lexer.hpp"
#include <cctype>

namespace itp {

  bool isoperator(char c) { return false; }

  bool issymbol(char c) { return false; }

  TOKEN_TYPES find_type(char *ref) {

    if (isdigit(*ref) || *ref == '.') {
      return TOKEN_TYPES::DIGIT;
    }
    if (std::isalpha(*ref)) {
      // here we will play with *ref position to check if we are having a function. ex s -> si -> sin .
    }
    if (isoperator(*ref)) {
      return TOKEN_TYPES::OPERATOR;
    }
    if (issymbol(*ref)) {
      // check if it's a parenthesis. other symbols will follow when i think about them LOL
      // assign token type
    }

    return TOKEN_TYPES::DIGIT;
  }

  std::vector<Token> tokenize(std::string &input) {
    auto token_collection = std::vector<Token>{};

    token_collection.push_back(Token{std::string(1, input[0]), find_type(&input[0])});

    for (size_t i = 1; i < input.length(); ++i) {
      char *ref = &input[i];
      TOKEN_TYPES type = find_type(ref);
      auto l_index = token_collection.size() - 1;

      if (token_collection[l_index].t_type == type) {
        token_collection[l_index].value += *ref;

      } else {
        token_collection.push_back(Token{std::string(1, *ref), type});
      }
    }

    return token_collection;
  }

} // namespace itp