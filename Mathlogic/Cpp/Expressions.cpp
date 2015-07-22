#include <stdexcept>
#include <functional>
#include <algorithm>
#include <map>

#include "Expressions.h"

using Expressions::Expression;
using Expressions::UnaryOperation;
using Expressions::BinaryOperation;

template <class Base, class Derived>
bool check_class_inherity(Derived &derived) {
    try {
        dynamic_cast<Base&>(derived);
        return true;
    } catch (const std::bad_cast&) {
        return false;
    }
}

Expression::~Expression() {
}

Expressions::Variable::Variable(const char *name) {
    this->name = std::string(name);
}

Expressions::Variable::Variable(const std::string &name) {
    this->name = name;
}

bool Expressions::Variable::equals(Expression *expression) {
    if (!check_class_inherity<Variable>(*expression)) {
        return false;
    }
    Variable *variable_expression = reinterpret_cast<Variable*>(expression);
    return name == variable_expression->name;
}

std::string Expressions::Variable::to_string() {
    return name;
}

size_t Expressions::Variable::hash() {
    std::hash<std::string> hash_str;
    return hash_str(name);
}

std::vector<std::string> Expressions::Variable::get_variables() {
    return {name};
}

bool Expressions::Variable::calculate(const std::map<std::string, bool> &variables_values) {
    return variables_values.find(name)->second;
}

Expressions::UnaryOperation::UnaryOperation() {}

Expressions::UnaryOperation::UnaryOperation(const char operation, Expression *operand)  {
    this->operation = operation;
    this->operand = operand;
}

bool Expressions::UnaryOperation::equals(Expression *expression)  {
    if (!check_class_inherity<UnaryOperation>(*expression)) {
        return false;
    }
    UnaryOperation *unary_expression = reinterpret_cast<UnaryOperation*>(expression);
    return operation == unary_expression->operation && operand->equals(unary_expression->operand);
}

std::string UnaryOperation::to_string() {
    return operation + "(" + operand->to_string() + ')';
}

size_t UnaryOperation::hash() {
    std::hash<std::string> hash_str;
    return hash_str(to_string());
}

std::vector<std::string> Expressions::UnaryOperation::get_variables() {
    return operand->get_variables();
}

Expressions::BinaryOperation::BinaryOperation() {}

Expressions::BinaryOperation::BinaryOperation(const char operation, Expression *left, Expression *right)  {
    this->operation = operation;
    this->left = left;
    this->right = right;
}

bool Expressions::BinaryOperation::equals(Expression *expression)  {
    if (!check_class_inherity<BinaryOperation>(*expression)) {
        return false;
    }
    BinaryOperation *binary_expression = reinterpret_cast<BinaryOperation*>(expression);
    return operation == binary_expression->operation &&
           left->equals(binary_expression->left) &&
           right->equals(binary_expression->right);
}

std::string Expressions::BinaryOperation::to_string() {
    return '(' + left->to_string() + ')' + operation + '(' + right->to_string() + ')';
}

size_t BinaryOperation::hash() {
    std::hash<std::string> hash_str;
    return hash_str(to_string());
}

std::vector<std::string> BinaryOperation::get_variables() {
    std::vector<std::string> result_left = left->get_variables();
    std::vector<std::string> result_right = right->get_variables();
    result_left.insert(result_left.end(), result_right.begin(), result_right.end());
    std::sort(result_left.begin(), result_left.end());
    result_left.erase(std::unique(result_left.begin(), result_left.end()), result_left.end());
    return result_left;
}