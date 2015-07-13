#include "Expressions.h"

Expressions::UnaryOperation::UnaryOperation() {}

Expressions::UnaryOperation::UnaryOperation(const std::string &operation, Expression *operand)  {
    this->operation = operation;
    this->operand = operand;
}

bool Expressions::UnaryOperation::check(Expression *expression)  {
    if (!Utils::check_class_inherity<UnaryOperation>(expression)) {
        throw std::bad_cast("Error in UnaryOperation::check(Expression*): can't cast Expression* to UnaryOperation*");
    }
    return false;
}

Expressions::BinaryOperation::BinaryOperation() {}

Expressions::BinaryOperation::BinaryOperation(const std::string &operation, Expression *left, Expression *right)  {
    this->operation = operation;
    this->left = left;
    this->right = right;
}

bool Expressions::BinaryOperation::check(Expression *expression)  {
    if (!Utils::check_class_inherity<BinaryOperation>(expression)) {
        throw std::bad_cast("Error in BinaryOperation::check(Expression*): can't cast Expression* to BinaryOperation*");
    }
    return false;
}
