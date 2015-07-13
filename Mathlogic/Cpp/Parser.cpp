#include "Parser.h"

#include <cctype>

using Expressions::Expression;
using Expressions::Implication;
using Expressions::And;
using Expressions::Or;
using Expressions::Not;

Expression* Parser::parse_and() {
    if (index >= expression.size()) {
        throw ParserError("Unexpected end of expression");
    }
    if (expression[index] == '!') {
        index++;
        return new Not(parse_and());
    }
    if (isalpha(expression[index]) && toupper(expression[index]) == expression[index]) {
        std::string name = "";
        while (index < expression.size() && isalpha(expression[index])) {
            name += expression[index++];
        }
        if (index < expression.size()) {
            while (index < expression.size() && isdigit(expression[index])) {
                name += expression[index++];
            }
        }
        return new Variable(name);
    }
    if (expression[index] == '(') {
        index++;
        Expression *result = parse_expression();
        if (index >= expression.size() || expression[index] != ')') {
            throw ParserError("No pair for open parenthesis");
        }
        index++;
        return result;
    }
    throw ParserError(std::string("Unexpected symbol in expression: expected '!', '(' or ['A'..'Z'], but found ") + expression[index] + " (index = " + std::to_string(index + 1) + ")");
}

Expression* Parser::parse_or() {
    Expression *result = parse_and();
    while (index < expression.size() && expression[index] == '&') {
        index++;
        result = new And(result, parse_and());
    }
    return result;
}

Expression* Parser::parse_implication() {
    Expression *result = parse_or();
    while (index < expression.size() && expression[index] == '|') {
        index++;
        result = new Or(result, parse_or());
    }
    return result;
}

Expression* Parser::parse_expression() {
    Expression *result = parse_implication();
    while (index < expression.size() - 1 && expression.substr(index, 2) == "->") {
        index += 2;
        result = new Implication(result, parse_implication());
    }
    return result;
}

Expression* Parser::parse(const std::string &expression) {
    std::string expression_no_spaces = "";
    for (size_t i = 0; i < expression.size(); i++) {
        if (!Utils::is_whitespace(expression[i])) {
            expression_no_spaces += expression[i];
        }
    }
    this->expression = expression_no_spaces;
    this->index = 0;
    Expression* result = parse_expression();
    if (index != expression_no_spaces.size()) {
        throw ParserError("Extra information at the end of expression");
    }
    return result;
}