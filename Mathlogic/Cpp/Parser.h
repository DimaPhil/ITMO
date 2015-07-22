#ifndef CLIONPROJECTS_PARSER_H
#define CLIONPROJECTS_PARSER_H

#include "Expressions.h"
#include "Utils.h"

#include <string>
#include <cstring>

using Expressions::Expression;

class Parser {
private:
    class ParserError {
    private:
        const char *message;
    public:
        ParserError(const char *message) {
           this->message = strdup(message);
        }

        ParserError(const std::string &message) : ParserError(message.c_str()) {
        }

        std::string what() const {
            return std::string(message);
        }
    };

    std::string expression;
    size_t index;

    Expression* parse_and();
    Expression* parse_or();
    Expression* parse_implication();
    Expression* parse_expression();
public:
    Parser();
    Expression* parse(const std::string &expression);
};

#endif //CLIONPROJECTS_PARSER_H
