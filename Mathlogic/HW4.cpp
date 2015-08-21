#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

#include "expressions/Expressions.h"
#include "expressions/Parser.h"
#include "ProofChecker.h"

using namespace Expressions;

struct HW4 {
    HW4() { }

    void run(const char *input, const char *output) {
        assert(freopen(input, "r", stdin));
        assert(freopen(output, "w", stdout));
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        /*std::vector<Expression *> axioms;
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
                BinaryOperation *binary_expression = reinterpret_cast<BinaryOperation *>(expression);
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
                        result.push_back(
                                "(" + alpha + "->" + delta_j + ")->((" + alpha + "->((" + delta_j + ")->" + delta_i +
                                "))->" +
                                "(" + alpha + "->" + delta_i + "))");
                        result.push_back(
                                "((" + alpha + "->((" + delta_j + ")->" + delta_i + "))->(" + alpha + "->" + delta_i +
                                "))");
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
        }*/
    }

    void run() {
        run("tests/input.txt", "tests/output.txt");
    }
};