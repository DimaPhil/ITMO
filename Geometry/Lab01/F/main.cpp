#include <bits/stdc++.h>

struct point {
    double x, y;

    point() : x(0.), y(0.) {}
    point(double x, double y) : x(x), y(y) {}

    point& operator -= (const point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    double square_length() const {
        return x * x + y * y;
    }

    double length() const {
        return sqrt(square_length());
    }
};

point operator - (point a, const point &b) {
    return a -= b;
}

bool operator < (const point &a, const point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

struct segment {
    point l, r;

    segment() : l(), r() {}
    segment(point _l, point _r) : l(std::min(_l, _r)), r(std::max(_l, _r)) {}

    double square_length() const {
        return (l - r).square_length();
    }

    double length() const {
        return sqrt(square_length());
    }
};

double cross_product(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

double dot_product(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

double distance(const point &a, const point &b) {
    return (a - b).length();
}

double distance(const segment &s, const point &p) {
    if (dot_product(p - s.l, s.r - s.l) >= 0 && dot_product(p - s.r, s.l - s.r) >= 0) {
        return std::abs(cross_product(s.l - p, s.r - p) / s.length());
    }
    return std::min(distance(p, s.l), distance(p, s.r));
}

double distance(const segment &s1, const segment &s2) {
    return std::min({distance(s1, s2.l), distance(s1, s2.r), distance(s2, s1.l), distance(s2, s1.r)});
}

double distance(const std::vector<point> &p, const std::vector<point> &q, int i, int j) {
    return distance(segment(p[i], p[i + 1]), segment(q[j], q[j + 1]));
}

int next(int i, int n) {
    if (++i == n) {
        i = 0;
    }
    return i;
}

int prev(int i, int n) {
    if (--i < 0) {
        i = n - 1;
    }
    return i;
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<point> p((size_t)n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    p[n] = p[0];
    int m;
    scanf("%d", &m);
    std::vector<point> q((size_t)m + 1);
    for (int i = 0; i < m; i++) {
        scanf("%lf%lf", &q[i].x, &q[i].y);
    }
    q[m] = q[0];

    double answer = 1e18;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < m; i++) {
        if (distance(p, q, p1, p2) > distance(p, q, p1, i)) {
            p2 = i;
        }
    }
    while (true) {
        answer = std::min(answer, distance(p, q, p1++, p2));
        if (p1 == n) {
            break;
        }
        while (distance(p, q, p1, p2) > distance(p, q, p1, next(p2, m))) {
            p2 = next(p2, m);
        }
        while (distance(p, q, p1, p2) > distance(p, q, p1, prev(p2, m))) {
            p2 = prev(p2, m);
        }
    }
    printf("%.20f\n", answer);
    return 0;
}