#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

struct point {
	int x;
	int y;

	point() : x(0), y(0) {}
	point(int x, int y) : x(x), y(y) {}

	void read() {
		scanf("%d%d", &x, &y);
	}

	void fprint() {
		fprintf(stderr, "%d %d\n", x, y);
	}

	void print() {
		printf("%d %d\n", x, y);
	}

	void swap(point &other) {
		std::swap(x, other.x);
		std::swap(y, other.y);
	}

	long long len2() {
		return x * 1LL * x + y * 1LL * y;
	}

	double len() {
		return sqrt(len2() + 0.0);
	}

	point& operator += (const point &other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	point& operator -= (const point &other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	bool operator < (const point &other) const {
		return x < other.x || (x == other.x && y < other.y);
	}

 	bool operator == (const point &other) const {
		return x == other.x && y == other.y;
	}

	long long operator % (const point &other) const {
		return x * 1LL * other.y - y * 1LL * other.x;
	}
};

point operator - (point a, const point &b) {
	return a -= b;
}

inline bool less_angle(point a, point b) {
	long long cross_product = a % b;
	return cross_product > 0 || (cross_product == 0 && a.len2() < b.len2());
}

int main() {
	int n;
	scanf("%d", &n);
	std::vector<point> p(n);
	for (int i = 0; i < n; i++) {
		p[i].read();
	}
	int min_index = -1;
	for (int i = 0; i < n; i++) {
		if (min_index == -1 || p[i] < p[min_index]) {
			min_index = i;
		}
	}
	assert(min_index != -1);
	p[0].swap(p[min_index]);
	point r = p[0];
	for (int i = 0; i < n; i++) {
		p[i] -= r;
	}
	std::sort(p.begin() + 1, p.end(), less_angle);
	p.erase(std::unique(p.begin(), p.end()), p.end());

	std::vector<point> stack;
	stack.push_back(p[0]);
	for (int i = 1; i < p.size(); i++) {
		while (stack.size() >= 2 && (stack.back() - stack[stack.size() - 2]) % (p[i] - stack.back()) <= 0) {
			stack.pop_back();
		}
		stack.push_back(p[i]);
	}
	printf("%d\n", (int)stack.size());
	for (size_t i = 0; i < stack.size(); i++) {
		stack[i] += r;
		stack[i].print();
	}
	return 0;
}
