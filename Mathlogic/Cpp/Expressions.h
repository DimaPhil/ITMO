#ifndef CLIONPROJECTS_EXPRESSION_H
#define CLIONPROJECTS_EXPRESSION_H

#include "Utils.h"

#include <string>
#include <vector>
#include <typeinfo>
#include <map>

namespace Expressions {
    struct Expression {
        virtual bool equals(Expression *expression) = 0;
        virtual std::string to_string() = 0;
        virtual size_t hash() = 0;
        virtual std::vector<std::string> get_variables() = 0;
        virtual bool calculate(const std::map<std::string, bool> &variables_values) = 0;

        virtual ~Expression();
    };

    struct Variable : public Expression {
        std::string name;

        Variable(const char* name);
        Variable(const std::string &name);

        bool equals(Expression *expression);
        std::string to_string();
        size_t hash();
        std::vector<std::string> get_variables();
        bool calculate(const std::map<std::string, bool> &variables_values);
    };

    struct UnaryOperation : public Expression {
        char operation;
        Expression *operand;

        UnaryOperation();
        UnaryOperation(const char operation, Expression *operand);

        bool equals(Expression *expression);
        std::string to_string();
        size_t hash();
        std::vector<std::string> get_variables();
    };

    struct BinaryOperation : public Expression {
        char operation;
        Expression *left;
        Expression *right;

        BinaryOperation();
        BinaryOperation(const char operation, Expression *left, Expression *right);

        bool equals(Expression *expression);
        std::string to_string();
        size_t hash();
        std::vector<std::string> get_variables();
    };

    struct Implication : public BinaryOperation {
        Implication(Expression *left, Expression *right) : BinaryOperation('>', left, right) {
        }

        bool calculate(const std::map<std::string, bool> &variables_values) {
            return !left->calculate(variables_values) | right->calculate(variables_values);
        }
    };

    struct And : public BinaryOperation {
        And(Expression *left, Expression *right) : BinaryOperation('&', left, right) {
        }

        bool calculate(const std::map<std::string, bool> &variables_values) {
            return left->calculate(variables_values) & right->calculate(variables_values);
        }
    };

    struct Or : public BinaryOperation {
        Or(Expression *left, Expression *right) : BinaryOperation('|', left, right) {
        }

        bool calculate(const std::map<std::string, bool> &variables_values) {
            return left->calculate(variables_values) | right->calculate(variables_values);
        }
    };

    struct Not : public UnaryOperation {
        Not(Expression *operand) : UnaryOperation('!', operand) {
        }

        bool calculate(const std::map<std::string, bool> &variables_values) {
            return !operand->calculate(variables_values);
        }
    };
}

#endif //CLIONPROJECTS_EXPRESSION_H