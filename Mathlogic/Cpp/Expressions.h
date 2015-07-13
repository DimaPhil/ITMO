#ifndef CLIONPROJECTS_EXPRESSION_H
#define CLIONPROJECTS_EXPRESSION_H

#include "Utils.h"

#include <string>
#include <vector>
#include <typeinfo>

namespace Expressions {
    struct Expression {
        virtual bool check(Expression *expression) = 0;
    };

    struct Variable : public Expression {
        std::string name;

        Variable(const char* name) {
            this->name = std::string(name);
        }

        Variable(const std::string &name) {
            this->name = name;
        }

        bool check(Expression *expression) {
            return true;
        }
    };

    struct UnaryOperation : public Expression {
        std::string operation;
        Expression *operand;

        UnaryOperation();
        UnaryOperation(const std::string &operation, Expression *operand);

        bool check(Expression *expression);
    };

    struct BinaryOperation : public Expression {
        std::string operation;
        Expression *left;
        Expression *right;

        BinaryOperation();
        BinaryOperation(const std::string &operation, Expression *left, Expression *right);

        bool check(Expression *expression);
    };

    struct Implication : public BinaryOperation {
        Implication(Expression *left, Expression *right) : BinaryOperation("->", left, right) {
        }
    };

    struct And : public BinaryOperation {
        And(Expression *left, Expression *right) : BinaryOperation("&", left, right) {
        }
    };

    struct Or : public BinaryOperation {
        Or(Expression *left, Expression *right) : BinaryOperation("|", left, right) {
        }
    };

    struct Not : public UnaryOperation {
        Not(Expression *operand) : UnaryOperation("!", operand) {
        }
    };
}

#endif //CLIONPROJECTS_EXPRESSION_H
