#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

#include "expressions/Expressions.h"
#include "expressions/Parser.h"

using Expressions::Variable;
using Expressions::UnaryOperation;
using Expressions::BinaryOperation;
using Expressions::Quantifier;
using Expressions::ArgumentsHandler;
using Expressions::Zero;
using Expressions::Stroke;

struct HW4 {
    const int NO_AXIOM = -1;
    enum EXPRESSION_TYPE {VARIABLE, UNARY_OPERATION, BINARY_OPERATION,
        QUANTIFIER, ARGUMENTS_HANDLER, ZERO, STROKE, UNKNOWN_TYPE};

    template <class Base, class Derived>
    bool check_class_inherity(Derived &derived) {
        try {
            dynamic_cast<Base&>(derived);
            return true;
        } catch (const std::bad_cast&) {
            return false;
        }
    }

    HW4() {}

    Expression* parse_expression(const std::string &const_expression) {
        std::string expression = const_expression;
        expression = Utils::replace(expression, ' ');
        expression = Utils::replace(expression, '\t');
        expression = Utils::replace(expression, "->", ">");

        Parser parser;
        try {
            return parser.parse(expression);
        } catch (const Parser::ParserError &e) {
            std::cerr << "Error in parsing expression\nExpression: " << expression << "\nError: " << e.what() << '\n';
            return nullptr;
        }
    }

    void add_expression(std::vector<Expression*> &expressions, const std::string &expression) {
        expressions.emplace_back(parse_expression(expression));
    }

    void add_axioms(std::vector<Expression*> &axioms) {
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

        add_expression(axioms, "a=b->a'=b'");
        add_expression(axioms, "a=b->a=c->b=c");
        add_expression(axioms, "a'=b'->a=b");
        add_expression(axioms, "!(a'=0)");
        add_expression(axioms, "a+b'=(a+b)'");
        add_expression(axioms, "a+0=a");
        add_expression(axioms, "a*0=0");
        add_expression(axioms, "a*b'=a*b+a");
    }

    //bad function, but don't know, how to do it better
    //if new classes were added, modify this function
    EXPRESSION_TYPE get_expression_type(Expression *expression) {
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

    bool expression_matches(Expression *needle, Expression *haystack, std::map<std::string, Expression*> &variables) {
        EXPRESSION_TYPE needle_type = get_expression_type(needle);
        EXPRESSION_TYPE haystack_type = get_expression_type(haystack);
        assert(needle_type != UNKNOWN_TYPE);
        assert(haystack_type != UNKNOWN_TYPE);
        if (needle_type != haystack_type && needle_type != VARIABLE) {
            return false;
        }
        if (needle_type == VARIABLE) {
            Variable *needle_variable = reinterpret_cast<Variable*>(needle);
            if (variables.find(needle_variable->to_string()) != variables.end()) {
                return variables[needle_variable->to_string()]->equals(haystack);
            }
            variables[needle_variable->to_string()] = haystack;
            return true;
        }
        if (needle_type == UNARY_OPERATION) {
            UnaryOperation *unary_needle = reinterpret_cast<UnaryOperation*>(needle);
            UnaryOperation *unary_haystack = reinterpret_cast<UnaryOperation*>(haystack);
            return unary_needle->operation == unary_haystack->operation &&
                   expression_matches(unary_needle->operand, unary_haystack->operand, variables);
        }
        if (needle_type == BINARY_OPERATION) {
            BinaryOperation *binary_needle = reinterpret_cast<BinaryOperation*>(needle);
            BinaryOperation *binary_haystack = reinterpret_cast<BinaryOperation*>(haystack);
            return binary_needle->operation == binary_haystack->operation &&
                   expression_matches(binary_needle->left, binary_haystack->left, variables) &&
                   expression_matches(binary_needle->right, binary_haystack->right, variables);
        }
        if (needle_type == QUANTIFIER) {
            Quantifier *quantifier_needle = reinterpret_cast<Quantifier*>(needle);
            Quantifier *quantifier_haystack = reinterpret_cast<Quantifier*>(haystack);
            return expression_matches(quantifier_needle->next, quantifier_haystack->next, variables);
        }
        if (needle_type == ARGUMENTS_HANDLER) {
            ArgumentsHandler *arguments_needle = reinterpret_cast<ArgumentsHandler*>(needle);
            ArgumentsHandler *arguments_haystack = reinterpret_cast<ArgumentsHandler*>(haystack);
            bool equals = arguments_needle->name == arguments_haystack->name &&
                    arguments_needle->terms.size() == arguments_haystack->terms.size();
            for (size_t i = 0; i < arguments_needle->terms; i++) {
                equals &= expression_matches(arguments_needle->terms[i], arguments_haystack->terms[i]);
            }
            return equals;
        }
        if (needle_type == ZERO) {
            return true;
        }
        if (needle_type == STROKE) {
            Stroke *stroke_needle = reinterpret_cast<Stroke*>(needle);
            Stroke *stroke_haystack = reinterpret_cast<Stroke*>(haystack);
            return expression_matches(stroke_needle->operand, stroke_haystack->operand);
        }
        throw std::runtime_error("An error occurred in HW4::expression_matches()");
    }

    bool expression_matches(Expression *needle, Expression *haystack) {
        std::map<std::string, Expression*> variables;
        return expression_matches(needle, haystack, variables);
    }

    bool is_axiom(Expression *axiom, Expression *expression) {
        return expression_matches(axiom, expression);
    }

    int get_axiom(const std::vector<Expression*> &axioms, Expression *expression) {
        for (size_t i = 0; i < axioms.size(); i++) {
            Expression *axiom = axioms[i];
            if (is_axiom(axiom, expression)) {
                return (int)i + 1;
            }
        }
        return NO_AXIOM;
    }

    void add_self_proof(std::vector<std::string> &result, const std::string &alpha) {
        result.push_back(alpha + "->(" + alpha + "->" + alpha + ")");
        result.push_back("(" + alpha + "->(" + alpha + "->" + alpha + "))->" +
                         "(" + alpha + "->((" + alpha + "->" + alpha + ")->" + alpha + "))->" +
                         "(" + alpha + "->" + alpha + ")");
        result.push_back("(" + alpha + "->((" + alpha + "->" + alpha + ")->" + alpha + "))->(" + alpha + "->" + alpha + ")");
        result.push_back("(" + alpha + "->((" + alpha + "->" + alpha + ")" + "->" + alpha + "))");
    }

    struct PredicateResult {
        Expression *not_free_term;
        Expression *formula;
        std::string variable_name;
        bool error_occurred;
        int index;

        PredicateResult() {
            error_occurred = false;
            index = -1;
        }
    };

    std::map<size_t, size_t> expression_hashes;
    std::map<std::string, Expression*> variables;

    int find_expression(Expression *expression) {
        auto it = expression_hashes.find(expression->hash());
        if (it == expression_hashes.end()) {
            return -1;
        }
        return it->second;
    }

    PredicateResult get_predicate_rule(Expression *expression) {
        using Expressions::Implication;
        using Expressions::ExistsQuantifier;
        using Expressions::ForallQuantifier;

        PredicateResult result;
        if (!check_class_inherity<Implication>(*expression)) {
            return result;
        }
        Implication *implication_expression = reinterpret_cast<Implication*>(expression);
        if (check_class_inherity<ExistsQuantifier>(*(implication_expression->left))) {
            ExistsQuantifier *exists_left = reinterpret_cast<ExistsQuantifier*>(implication_expression->left);
            Expression *current = new Implication(exists_left->next, implication_expression->right);
            result.index = find_expression(current);
            if (result.index != -1) {
                std::vector<std::string> free_variables = implication_expression->left->get_variables();
                result.variable_name = exists_left->variable->to_string();
                if (std::find(free_variables.begin(), free_variables.end(), result.variable_name) != free_variables.end()) {
                    result.error_occurred = true;
                    result.formula = implication_expression->right;
                    return result;
                }
                return result;
            }
        }
        if (check_class_inherity<ForallQuantifier>(*(implication_expression->right))) {
            ForallQuantifier *forall_right = reinterpret_cast<ForallQuantifier*>(implication_expression->right);
            Expression *current = new Implication(implication_expression->left, forall_right->next);
            result.index = find_expression(current);
            if (result.index != -1) {
                std::vector<std::string> free_variables = implication_expression->left->get_variables();
                result.variable_name = forall_right->variable->to_string();
                if (std::find(free_variables.begin(), free_variables.end(), result.variable_name) != free_variables.end()) {
                    result.error_occurred = true;
                    result.formula = implication_expression->left;
                    return result;
                }
                return result;
            }
        }
        return result;
    }

    PredicateResult is_predicate_axiom(Expression *expression) {
        using Expressions::Implication;
        using Expressions::ExistsQuantifier;
        using Expressions::ForallQuantifier;

        PredicateResult result;
        if (!check_class_inherity<Implication>(*expression)) {
            return result;
        }
        Implication *implication_expression = reinterpret_cast<Implication*>(expression);
        if (check_class_inherity<ForallQuantifier>(*(implication_expression->left))) {
            variables.clear();
            ForallQuantifier *forall_quantifier = reinterpret_cast<ForallQuantifier*>(implication_expression->left);
            std::string variable_name = forall_quantifier->variable->to_string();
            if (forall_quantifier->next->is_substitute(implication_expression->right)) {

            }
        }
        return result;
    }

    void run(const char *input, const char *output) {
        assert(freopen(input, "r", stdin));
        assert(freopen(output, "w", stdout));
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        std::vector<Expression*> axioms;
        add_axioms(axioms);

        std::string first_line;
        std::getline(std::cin, first_line);
        first_line = Utils::replace(first_line, ' ');

        std::vector<std::string> split_line = Utils::split(first_line, "|-");
        assert(split_line.size() == 2);

        std::string needle = split_line[1];
        std::vector<std::string> assumptions_strings = Utils::split(split_line[0], ',');
        std::string alpha = assumptions_strings.back();
        Expression *alpha_expression = parse_expression(alpha);
        if (check_class_inherity<BinaryOperation>(*alpha_expression)) {
            alpha = "(" + alpha + ")";
        }
        assumptions_strings.pop_back();

        std::set<size_t> assumptions;
        for (size_t i = 0; i < assumptions_strings.size(); i++) {
            assumptions.insert(parse_expression(assumptions_strings[i])->hash());
        }

        std::string delta;
        std::vector<std::string> deltas;
        std::vector<std::string> result;
        std::map<size_t, std::vector<std::pair<size_t, size_t>>> parts;
        std::map<size_t, size_t> all_hashes;
        size_t line_number = 0;
        while (std::getline(std::cin, delta)) {
            ++line_number;
            deltas.push_back(delta);

            Expression *expression = parse_expression(delta);
            if (check_class_inherity<BinaryOperation>(*expression)) {
                BinaryOperation *binary_expression = reinterpret_cast<BinaryOperation*>(expression);
                if (binary_expression->operation == '>') {
                    parts[binary_expression->right->hash()].push_back(
                            std::make_pair(binary_expression->left->hash(), line_number));
                }
            }
            if (get_axiom(axioms, expression) != NO_AXIOM ||
                assumptions.find(expression->hash()) != assumptions.end()) {
                result.push_back(delta);
                result.push_back("(" + delta + ")->(" + alpha + "->" + delta + ")");
            } else if (expression->equals(alpha_expression)) {
                add_self_proof(result, alpha);
            } else {
                std::vector<std::pair<size_t, size_t>> &part = parts[expression->hash()];
                for (size_t i = 0; i < part.size(); i++) {
                    auto it = all_hashes.find(part[i].first);
                    if (it != all_hashes.end()) {
                        std::string delta_i = delta;
                        std::string delta_j = deltas[it->second - 1];
                        result.push_back("(" + alpha + "->" + delta_j + ")->((" + alpha + "->((" + delta_j + ")->" + delta_i + "))->" +
                                         "(" + alpha + "->" + delta_i + "))");
                        result.push_back("((" + alpha + "->((" + delta_j + ")->" + delta_i + "))->(" + alpha + "->" + delta_i + "))");
                        break;
                    }
                }
            }
            all_hashes[expression->hash()] = line_number;
            result.push_back(alpha + "->" + delta);
        }

        for (size_t i = 0; i < assumptions_strings.size(); i++) {
            std::cout << assumptions_strings[i];
            if (i + 1 < assumptions_strings.size()) {
                std::cout << ",";
            }
        }
        std::cout << "|-";
        std::cout << alpha << "->" << needle << '\n';
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i] << '\n';
        }
    }

    void run() {
        run("tests/input.txt", "tests/output.txt");
    }
};