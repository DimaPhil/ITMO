#include "tests.h"

#include <cstddef>
#include <gmpxx.h>
#include <boost/numeric/interval.hpp>
#include <boost/optional.hpp>

#include <cmath>
#include <vector>

const double EPS = std::numeric_limits<double>::epsilon();

struct point {
	double x, y;
	
	point() { x = y = 0; }
	point(double x, double y) : x(x), y(y) {}

	point& operator -= (const point &other) {
		x -= other.x;
		y -= other.y;
	}

	void print() {
		std::cout << x << ' ' << y << '\n';
	}	
};

point operator - (point a, const point &b) {
	return a -= b;
}

bool operator == (const point &a, const point &b) {
	return a.x == b.x && a.y == b.y;
}

bool operator < (const point &a, const point &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator <= (const point &a, const point &b) {
	return a < b || (a == b);
}

ostream& operator << (ostream &out, const point &p) {
	return out << p.x << ' ' << p.y;
}

enum orientation_t {
	RIGHT = -1,
	FORWARD = 0,
	LEFT = 1
};

struct orientation_double {
	boost::optional<orientation_t> operator() (const point &a, const point &b, const point &c) const {
		double l = (b.x - a.x) * (c.y - a.y);
		double r = (b.y - a.y) * (c.x - a.x);
		double cross_product = l - r;
		double eps = (fabs(l) + fabs(r)) * 8 * EPS;
		return cross_product > eps ? LEFT : (cross_product < -eps ? RIGHT : boost::optional<orientation_t>(boost::none));
	}
};

struct orientation_interval {
	boost::optional<orientation_t> operator() (const point &a, const point &b, const point &c) const {
		typedef boost::numeric::interval_lib::unprotect<boost::numeric::interval<double>>::type interval;
		interval result = (interval(b.x) - a.x) * (interval(c.y) - a.y) - 
				(interval(b.y) - a.y) * (interval(c.x) - a.x);
		return result.lower() > 0 ? LEFT : (result.upper() < 0 ? RIGHT : (result.lower() == result.upper() ? FORWARD : boost::optional<orientation_t>(boost::none)));
	}
};

struct orientation_gmp {
	boost::optional<orientation_t> operator() (const point &a, const point &b, const point &c) const {
		mpq_class long_result = (mpq_class(b.x) - a.x) * (mpq_class(c.y) - a.y) -
						   (mpq_class(b.y) - a.y) * (mpq_class(c.x) - a.x);
		int result = cmp(long_result, 0);
		return result > 0 ? LEFT : (result < 0 ? RIGHT : FORWARD);	
	}
};

orientation_t find_orientation(const point &a, const point &b, const point &c) {
	boost::optional<orientation_t> result;
   
	result = orientation_double()(a, b, c);
	if (result) {
		return *result;
	}
	
	result = orientation_interval()(a, b, c);
	if (result) {
		return *result;
	}

	result = orientation_gmp()(a, b, c);
	return *result;
}

bool bounding_box(double a, double b, double c, double d) {
	if (a > b) {
		std::swap(a, b);
	}
	if (c > d) {
		std::swap(c, d);
	}
	return max(a, c) <= min(b, d);
}

int main() {
	int test_number;
	std::cin >> test_number;
	std::vector<double> input = genTest(test_number);
	size_t tests_count = input.size() / 8;
	for (size_t test_id = 0; test_id < tests_count; ++test_id) {
		point a(input[test_id * 8 + 0], input[test_id * 8 + 1]);
		point b(input[test_id * 8 + 2], input[test_id * 8 + 3]);
		point c(input[test_id * 8 + 4], input[test_id * 8 + 5]);
		point d(input[test_id * 8 + 6], input[test_id * 8 + 7]);
		
		bool ok = bounding_box(a.x, b.x, c.x, d.x) && bounding_box(a.y, b.y, c.y, d.y);
		putchar((ok && find_orientation(c, a, b) * find_orientation(d, a, b) <= 0 && find_orientation(a, c, d) * find_orientation(b, c, d) <= 0) ? 'Y' : 'N');
	}
	putchar('\n');
	return 0;
}
