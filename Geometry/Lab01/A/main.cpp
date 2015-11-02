#include "tests.h"

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <gmpxx.h>

int main() {
	int test_number;
	std::cin >> test_number;
	std::pair<std::string, std::string> input = genTest(test_number);
	mpz_t a, b;
	mpz_init_set_str(a, input.first.c_str(), 10);
	mpz_init_set_str(b, input.second.c_str(), 10);
	mpz_add(a, a, b);
	std::cout << mpz_get_str(NULL, 10, a) << '\n';
	mpz_clear(a);
	mpz_clear(b);
}
