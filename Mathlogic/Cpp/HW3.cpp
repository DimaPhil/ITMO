#include <cassert>
#include <iostream>
#include <map>
#include <set>

#include "Expressions.h"
#include "Parser.h"

using Expressions::BinaryOperation;
using Expressions::UnaryOperation;
using Expressions::Variable;

struct HW3 {
    const int NO_AXIOM = -1;
    enum EXPRESSION_TYPE {VARIABLE, UNARY_OPERATION, BINARY_OPERATION, UNKNOWN_TYPE};

    template <class Base, class Derived>
    bool check_class_inherity(Derived &derived) {
        try {
            dynamic_cast<Base&>(derived);
            return true;
        } catch (const std::bad_cast&) {
            return false;
        }
    }

    HW3() {}

    Expression* parse_expression(const std::string &const_expression) {
        std::string expression = const_expression;
        expression = Utils::replace(expression, ' ');
        expression = Utils::replace(expression, '\t');
        expression = Utils::replace(expression, "->", ">");

        Parser parser;
        return parser.parse(expression);
    }

    void add_expression(std::vector<Expression*> &expressions, const std::string &expression) {
        expressions.push_back(parse_expression(expression));
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
        throw std::runtime_error("An error occurred in HW1::expression_matches()");
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

    struct Result {
        bool is_always_true;
        std::map<std::string, bool> variables_values;

        Result() {}
        Result(bool is_always_true) {
            this->is_always_true = is_always_true;
            variables_values.clear();
        }
        Result(bool is_always_true, size_t mask, const std::vector<std::string> &variables) {
            this->is_always_true = is_always_true;
            variables_values = mask_to_map(mask, variables);
        }
    };

    template<typename T>
    static std::map<T, bool> mask_to_map(size_t mask, const std::vector<T> &elements) {
        std::map<T, bool> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result[elements[i]] = (mask & (1 << i)) != 0;
        }
        return result;
    }

    Result check_always_true(Expression *expression) {
        std::map<std::string, bool> variables_values;
        std::vector<std::string> variables = expression->get_variables();
        for (size_t mask = 0; mask < (1U << variables.size()); mask++) {
            if (!expression->calculate(mask_to_map(mask, variables))) {
                return Result(false, mask, variables);
            }
        }
        return Result(true);
    }

    void run(const char *input, const char *output) {
        assert(freopen(input, "r", stdin));
        assert(freopen(output, "w", stdout));
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        std::vector<Expression*> axioms;
        add_axioms(axioms);

        std::string expression_to_check_string;
        std::cin >> expression_to_check_string;
        Expression *expression_to_check = parse_expression(expression_to_check_string);
        Result result = check_always_true(expression_to_check);
        if (!result.is_always_true) {
            std::cout << "Высказывание ложно при ";
            for (auto it = result.variables_values.begin(); it != result.variables_values.end();) {
                std::cout << it->first << "=" << (it->second ? "И" : "Л");
                ++it;
                if (it != result.variables_values.end()) {
                    std::cout << ", ";
                }
            }
        } else {
            std::cout << "Всегда верно";
            //proof
        }
    }

    void run() {
        run("tests/input.txt", "tests/output.txt");
    }
};