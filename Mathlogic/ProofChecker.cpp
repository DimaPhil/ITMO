#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>

#include "expressions/Expressions.h"
#include "expressions/Parser.h"
#include "ProofChecker.h"

using namespace Expressions;

std::vector<Expression*> ProofChecker::axioms;
std::vector<Expression*> ProofChecker::arithmetic_axioms;
std::map<std::string, Expression*> ProofChecker::variables;

Expression* ProofChecker::parse_expression(const std::string &const_expression) {
    std::string expression = const_expression;
    expression = Utils::replace(expression, ' ');
    expression = Utils::replace(expression, '\t');
    expression = Utils::replace(expression, "->", ">");

    Parser parser;
    try {
        return parser.parse(expression);
    } catch (const Parser::ParserError &e) {
        std::cerr << "Error in parsing expression\nExpression: " << expression << "\nError: " << e.what() <<
        '\n';
        return nullptr;
    }
}

void ProofChecker::add_expression(std::vector<Expression *> &expressions, const std::string &expression) {
    expressions.emplace_back(parse_expression(expression));
}

void ProofChecker::add_axioms(std::vector<Expression *> &axioms, std::vector<Expression *> &arithmetic_axioms) {
    add_expression(axioms, "A->B->A");
    add_expression(axioms, "(A->B)->(A->B->C)->(A->C)");
    add_expression(axioms, "A&B->A");
    add_expression(axioms, "A&B->B");
    add_expression(axioms, "A->B->A&B");
    add_expression(axioms, "A->A|B");
    add_expression(axioms, "B->A|B");
    add_expression(axioms, "(A->Q)->(B->Q)->(A|B->Q)");
    add_expression(axioms, "(A->B)->(A->!B)->!A");
    add_expression(axioms, "!!A->A");

    add_expression(arithmetic_axioms, "a=b->a'=b'");
    add_expression(arithmetic_axioms, "a=b->a=c->b=c");
    add_expression(arithmetic_axioms, "a'=b'->a=b");
    add_expression(arithmetic_axioms, "!(a'=0)");
    add_expression(arithmetic_axioms, "a+b'=(a+b)'");
    add_expression(arithmetic_axioms, "a+0=a");
    add_expression(arithmetic_axioms, "a*0=0");
    add_expression(arithmetic_axioms, "a*b'=a*b+a");
}

ProofChecker::ProofChecker() {
    add_axioms(axioms, arithmetic_axioms);
}

void ProofChecker::clear() {
    expressions.clear();
    expression_hashes.clear();
    variables.clear();
}

//bad function, but don't know, how to do it better
//if new classes were added, modify this function
ProofChecker::EXPRESSION_TYPE ProofChecker::get_expression_type(Expression *expression) {
    if (check_class_inherity<Variable>(*expression)) {
        return VARIABLE;
    }
    if (check_class_inherity<UnaryOperation>(*expression)) {
        return UNARY_OPERATION;
    }
    if (check_class_inherity<BinaryOperation>(*expression)) {
        return BINARY_OPERATION;
    }
    if (check_class_inherity<Quantifier>(*expression)) {
        return QUANTIFIER;
    }
    if (check_class_inherity<ArgumentsHandler>(*expression)) {
        return ARGUMENTS_HANDLER;
    }
    if (check_class_inherity<Zero>(*expression)) {
        return ZERO;
    }
    if (check_class_inherity<Stroke>(*expression)) {
        return STROKE;
    }
    return UNKNOWN_TYPE;
}

bool ProofChecker::expression_matches(Expression *needle, Expression *haystack,
                                      std::map<std::string, Expression *> &variables) {
    EXPRESSION_TYPE needle_type = get_expression_type(needle);
    EXPRESSION_TYPE haystack_type = get_expression_type(haystack);
    assert(needle_type != UNKNOWN_TYPE);
    assert(haystack_type != UNKNOWN_TYPE);
    if (needle_type != haystack_type && needle_type != VARIABLE) {
        return false;
    }
    if (needle_type == VARIABLE) {
        Variable *needle_variable = reinterpret_cast<Variable *>(needle);
        if (variables.find(needle_variable->to_string()) != variables.end()) {
            return variables[needle_variable->to_string()]->equals(haystack);
        }
        variables[needle_variable->to_string()] = haystack;
        return true;
    }
    if (needle_type == UNARY_OPERATION) {
        UnaryOperation *unary_needle = reinterpret_cast<UnaryOperation *>(needle);
        UnaryOperation *unary_haystack = reinterpret_cast<UnaryOperation *>(haystack);
        return unary_needle->operation == unary_haystack->operation &&
               expression_matches(unary_needle->operand, unary_haystack->operand, variables);
    }
    if (needle_type == BINARY_OPERATION) {
        BinaryOperation *binary_needle = reinterpret_cast<BinaryOperation *>(needle);
        BinaryOperation *binary_haystack = reinterpret_cast<BinaryOperation *>(haystack);
        return binary_needle->operation == binary_haystack->operation &&
               expression_matches(binary_needle->left, binary_haystack->left, variables) &&
               expression_matches(binary_needle->right, binary_haystack->right, variables);
    }
    if (needle_type == QUANTIFIER) {
        Quantifier *quantifier_needle = reinterpret_cast<Quantifier *>(needle);
        Quantifier *quantifier_haystack = reinterpret_cast<Quantifier *>(haystack);
        return expression_matches(quantifier_needle->next, quantifier_haystack->next, variables);
    }
    if (needle_type == ARGUMENTS_HANDLER) {
        ArgumentsHandler *arguments_needle = reinterpret_cast<ArgumentsHandler *>(needle);
        ArgumentsHandler *arguments_haystack = reinterpret_cast<ArgumentsHandler *>(haystack);
        bool equals = arguments_needle->name == arguments_haystack->name &&
                      arguments_needle->terms.size() == arguments_haystack->terms.size();
        for (size_t i = 0; i < arguments_needle->terms.size(); i++) {
            equals &= expression_matches(arguments_needle->terms[i], arguments_haystack->terms[i], variables);
        }
        return equals;
    }
    if (needle_type == ZERO) {
        return true;
    }
    if (needle_type == STROKE) {
        Stroke *stroke_needle = reinterpret_cast<Stroke *>(needle);
        Stroke *stroke_haystack = reinterpret_cast<Stroke *>(haystack);
        return expression_matches(stroke_needle->operand, stroke_haystack->operand, variables);
    }
    throw std::runtime_error("An error occurred in HW4::expression_matches()");
}

bool ProofChecker::expression_matches(Expression *needle, Expression *haystack) {
    std::map<std::string, Expression *> variables;
    return expression_matches(needle, haystack, variables);
}

bool ProofChecker::is_axiom(Expression *axiom, Expression *expression) {
    return expression_matches(axiom, expression);
}

int ProofChecker::get_axiom(const std::vector<Expression *> &axioms, Expression *expression) {
    for (size_t i = 0; i < axioms.size(); i++) {
        Expression *axiom = axioms[i];
        if (is_axiom(axiom, expression)) {
            return (int) i + 1;
        }
    }
    return NO_AXIOM;
}

int ProofChecker::find_expression(Expression *expression) {
    auto it = expression_hashes.find(expression->hash());
    if (it == expression_hashes.end()) {
        return -1;
    }
    return it->second;
}

PredicateResult ProofChecker::get_predicate_rule(Expression *expression) {
    using Expressions::Implication;
    using Expressions::ExistsQuantifier;
    using Expressions::ForallQuantifier;

    PredicateResult result;
    if (!check_class_inherity<Implication>(*expression)) {
        return result;
    }
    Implication *implication_expression = reinterpret_cast<Implication *>(expression);
    if (check_class_inherity<ExistsQuantifier>(*(implication_expression->left))) {
        ExistsQuantifier *exists_left = reinterpret_cast<ExistsQuantifier *>(implication_expression->left);
        Expression *current = new Implication(exists_left->next, implication_expression->right);
        result.index = find_expression(current);
        if (result.index != -1) {
            std::vector<std::string> free_variables = implication_expression->left->get_variables();
            result.variable_name = exists_left->variable->to_string();
            if (std::find(free_variables.begin(), free_variables.end(), result.variable_name) !=
                free_variables.end()) {
                result.error_occurred = true;
                result.formula = implication_expression->right;
                return result;
            }
            return result;
        }
    }
    if (check_class_inherity<ForallQuantifier>(*(implication_expression->right))) {
        ForallQuantifier *forall_right = reinterpret_cast<ForallQuantifier *>(implication_expression->right);
        Expression *current = new Implication(implication_expression->left, forall_right->next);
        result.index = find_expression(current);
        if (result.index != -1) {
            std::vector<std::string> free_variables = implication_expression->left->get_variables();
            result.variable_name = forall_right->variable->to_string();
            if (std::find(free_variables.begin(), free_variables.end(), result.variable_name) !=
                free_variables.end()) {
                result.error_occurred = true;
                result.formula = implication_expression->left;
                return result;
            }
            return result;
        }
    }
    return result;
}

PredicateResult ProofChecker::is_predicate_axiom(Expression *expression) {
    using Expressions::Implication;
    using Expressions::ExistsQuantifier;
    using Expressions::ForallQuantifier;

    PredicateResult result;
    if (!check_class_inherity<Implication>(*expression)) {
        return result;
    }
    Implication *implication_expression = reinterpret_cast<Implication *>(expression);
    if (check_class_inherity<ForallQuantifier>(*(implication_expression->left))) {
        variables.clear();
        ForallQuantifier *forall_quantifier = reinterpret_cast<ForallQuantifier *>(implication_expression->left);
        std::string variable_name = forall_quantifier->variable->to_string();
        if (forall_quantifier->next->is_substitute(implication_expression->right)) {
            Expression *current_term = ProofChecker::variables[variable_name];
            result.variable_name = variable_name;
            result.index = 0;
            if (forall_quantifier->next->is_free_to_substitute(variable_name,
                                                               current_term->get_variables()).successuful) {
                result.index = 1;
            } else {
                result.error_occurred = true;
                result.not_free_term = current_term;
                result.formula = implication_expression->right;
            }
            return result;
        }
    }
    if (check_class_inherity<ExistsQuantifier>(*(implication_expression->right))) {
        ProofChecker::variables.clear();
        ExistsQuantifier *exists_quantifier = reinterpret_cast<ExistsQuantifier *>(implication_expression->right);
        if (exists_quantifier->next->is_substitute(implication_expression->left)) {
            std::string variable_name = exists_quantifier->variable->to_string();
            Expression *current_term = ProofChecker::variables[variable_name];
            result.index = 0;
            if (exists_quantifier->next->is_free_to_substitute(variable_name,
                                                               current_term->get_variables()).successuful) {
                result.index = 2;
            } else {
                result.error_occurred = true;
                result.not_free_term = current_term;
                result.formula = implication_expression->right;
            }
            return result;
        }
    }
    return result;
}

int ProofChecker::get_arithmetic_axiom(Expression *expression) {
    using Expressions::Implication;
    using Expressions::And;
    using Expressions::ForallQuantifier;
    using Expressions::Stroke;

    for (size_t i = 0; i < arithmetic_axioms.size(); i++) {
        ProofChecker::variables.clear();
        if (arithmetic_axioms[i]->is_substitute(expression)) {
            return (int) i;
        }
    }
    if (!check_class_inherity<Implication>(*expression)) {
        return -1;
    }
    Implication *implication_expression = reinterpret_cast<Implication *>(expression);
    Expression *implication_right = implication_expression->right;
    if (!check_class_inherity<And>(*(implication_expression->left))) {
        return -1;
    }
    And *and_left_implication = reinterpret_cast<And *>(implication_expression->left);
    if (!check_class_inherity<ForallQuantifier>(*(and_left_implication->right))) {
        return -1;
    }
    ForallQuantifier *forall_quantifier = reinterpret_cast<ForallQuantifier *>(and_left_implication->right);
    std::string variable_name = forall_quantifier->variable->to_string();
    if (!check_class_inherity<Implication>(*(forall_quantifier->next))) {
        return -1;
    }
    Implication *implication_forall = reinterpret_cast<Implication *>(forall_quantifier->next);
    if (!implication_right->equals(implication_forall->left)) {
        return -1;
    }
    Expression *mulled = new Stroke(forall_quantifier->variable);
    std::map<std::string, Expression *> changes_to_apply;
    changes_to_apply[variable_name] = mulled;
    if (!implication_forall->right->equals(implication_right->substitute(changes_to_apply))) {
        return -1;
    }
    changes_to_apply[variable_name] = new Zero();
    if (!and_left_implication->left->equals(implication_right->substitute(changes_to_apply))) {
        return -1;
    }
    return (int) arithmetic_axioms.size();
}
