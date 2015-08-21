#include <iostream>
#include <algorithm>

#include "ProofDeduction.h"
#include "expressions/ParserFormalArithmetic.h"

Expression* parse_expression(const std::string &const_expression) {
    std::string expression = const_expression;
    expression = Utils::replace(expression, ' ');
    expression = Utils::replace(expression, '\t');
    expression = Utils::replace(expression, "->", ">");

    ParserFormalArithmetic parser;
    try {
        return parser.parse(expression);
    } catch (const ParserFormalArithmetic::ParserError &e) {
        std::cerr << "Error in parsing expression\nExpression: " << expression << "\nError: " << e.what() <<
        '\n';
        return nullptr;
    }
}

int ProofDeduction::get_assumption(Expression *expression) {
    for (size_t i = 0; i < assumptions.size(); i++) {
        if (assumptions[i]->equals(expression)) {
            return (int)i;
        }
    }
    return NO_ASSUMPTION;
}

void ProofDeduction::add_self_proof(std::vector<Expression *> &result) {
    result.push_back(parse_expression(proposal_string + "->(" + proposal_string + "->" + proposal_string + ")"));
    result.push_back(parse_expression("(" + proposal_string + "->(" + proposal_string + "->" + proposal_string + "))->" +
                                      "(" + proposal_string + "->((" + proposal_string + "->" + proposal_string + ")->" + proposal_string + "))->" +
                                      "(" + proposal_string + "->" + proposal_string + ")"));
    result.push_back(parse_expression(
            "(" + proposal_string + "->((" + proposal_string + "->" + proposal_string + ")->" +
            proposal_string + "))->(" + proposal_string + "->" + proposal_string + ")"));
    result.push_back(parse_expression("(" + proposal_string + "->((" + proposal_string + "->" + proposal_string + ")" + "->" + proposal_string + "))"));
}

void ProofDeduction::add_axiom_proof(Expression *expression, std::vector<Expression*> &result) {
    result.emplace_back(expression);
    result.emplace_back(parse_expression("(" + expression->to_string() + ")->((" + proposal_string + ")->(" + expression->to_string() + ")"));
}

void ProofDeduction::add_proof(Expression *expression, std::vector<Expression*> &result) {
    if (proof_checker.find_expression(expression) != -1) {
        return;
    }
    int axiom_index = proof_checker.get_axiom(expression);
    int arithmetic_axiom_index = proof_checker.get_arithmetic_axiom(expression);
    PredicateResult predicate_axiom_index = proof_checker.get_predicate_axiom(expression);
    int assumption_index = get_assumption(expression);
    PredicateResult predicate_rule_index = proof_checker.get_predicate_rule(expression);
    if (axiom_index != -1 || assumption_index != -1 || arithmetic_axiom_index != -1 || predicate_axiom_index.index != -1) {
        add_axiom_proof(expression, result);
    } else if (proposal->equals(expression)) {
        add_self_proof(result);
    } else if (proof_checker.get_modus_ponens(expression).second != static_cast<size_t>(-1)) {

    } else if (predicate_rule_index.index != -1) {

    }
    proof_checker.add_expression(expression);
    result.emplace_back(new Expressions::Implication(proposal, expression));
}