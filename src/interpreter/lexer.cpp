#include "lexer.hpp"
#include <cctype>

namespace itp {

  bool isoperator(char c) { return operators.find_first_of(c) != std::string::npos; }

  bool issymbol(char c) { return symbols.find_first_of(c) != std::string::npos; }

  // TOKEN_TYPE, int skip steps
  std::pair<TOKEN_TYPES, int> find_type(const char *ref) {

    if (isdigit(*ref) || *ref == '.') {
      return {TOKEN_TYPES::DIGIT, 1};
    }
    if (std::isalpha(*ref)) {
      std::pair<TOKEN_TYPES, int> ret{TOKEN_TYPES::FUNCTION, 1};
      switch (*ref) {
      case 's':
        if (std::string(ref, ref + 3) == "sin")
          ret.second = 3;

        if (std::string(ref, ref + 4) == "sqrt")
          ret.second = 4;
        break;
      case 'a':
        if (std::string_view(ref, ref + 6) == "arcsin" || std::string_view(ref, ref + 6) == "arccos" ||
            std::string_view(ref, ref + 6) == "arctan")
          ret.second = 6;
        break;
      case 'e':
        if (std::string(ref, ref + 3) == "exp")
          ret.second = 3;
        break;
      case 'c':
        if (std::string(ref, ref + 3) == "cos")
          ret.second = 3;
        break;
      case 'p':
        if (std::string(ref, ref + 3) == "pow")
          ret.second = 3;
        break;
      case 'l':
        if (std::string(ref, ref + 2) == "ln")
          ret.second = 2;
        if (std::string(ref, ref + 3) == "log")
          ret.second = 3;
        break;
      case 't':
        if (std::string(ref, ref + 3) == "tan")
          ret.second = 3;
        break;
      default:
        ret = {TOKEN_TYPES::VARIABLE, 1};
      }
      return ret;
    }
    if (isoperator(*ref)) {
      return {TOKEN_TYPES::OPERATOR, 1};
    }
    if (issymbol(*ref)) {
      return {TOKEN_TYPES::SYMBOL, 1};
    }

    return {TOKEN_TYPES::DIGIT, -1};
  }

  std::vector<Token> tokenize(std::string &input) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

    auto token_collection = std::vector<Token>{};

    auto t = find_type(&input[0]);
    token_collection.push_back(Token{std::string(input.substr(0, t.second)), t.first});

    for (size_t i = t.second; i < input.length(); ++i) {
      t = find_type(&input[i]);

      TOKEN_TYPES type = t.first;
      auto l_index = token_collection.size() - 1;

      if (token_collection[l_index].t_type == type && type != TOKEN_TYPES::SYMBOL) {
        token_collection[l_index].value += input.substr(i, t.second);

      } else {
        token_collection.push_back(Token{input.substr(i, t.second), t.first});
      }
      i += t.second - 1;
    }

    return token_collection;
  }

} // namespace itp