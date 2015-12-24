#include <bits/stdc++.h>

const int maxn = (int)1e6 + 100;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double x, double y) : x(x), y(y) {}

    double len() {
        return sqrt(x * x + y * y);
    }
};

point operator + (point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

point operator / (point a, double b) {
    return point(a.x / b, a.y / b);
}

struct circle {
    double x, y;
    double r;

    circle() {}
    circle(double x, double y, double r) : x(x), y(y), r(r) {}
    circle(point p, double r) : x(p.x), y(p.y), r(r) {}
};

bool inside(circle c, point p) {
    return (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y) <= c.r * c.r;
}

circle circumcircle(point a, point b, point c) {
    point mab = (a + b) / 2.0;
    point mac = (a + c) / 2.0;
    double a1 = b.y - a.y;
    double b1 = a.x - b.x;
    double A1 = -b1;
    double B1 = a1;
    double C1 = (-A1 * mab.x - B1 * mab.y);

    double a2 = c.y - a.y;
    double b2 = a.x - c.x;
    double A2 = -b2;
    double B2 = a2;
    double C2 = (-A2 * mac.x - B2 * mac.y);

    double X = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);
    double Y = (C2 * A1 - C1 * A2) / (B1 * A2 - B2 * A1);
    point p = point(X, Y);
    return circle(X, Y, (p - a).len());
}

circle min_circle_with_two_points(std::vector<point>& s, point p, point q) {
    circle current = circle((q + p) / 2.0, (q - p).len() / 2.0);
    for (size_t i = 0; i < s.size(); i++) {
        if (inside(current, s[i])) {
            continue;
        }
        current = circumcircle(s[i], p, q);
    }
    return current;

}

circle min_circle_with_point(std::vector<point>& s, point p) {
    std::random_shuffle(s.begin(), s.end());
    circle current = circle((s[0] + p) / 2.0, (s[0] - p).len() / 2.0);
    for (size_t i = 1; i < s.size(); i++) {
        if (inside(current, s[i])) {
            continue;
        }
        std::vector<point> newS(s.begin(), s.begin() + i);
        current = min_circle_with_two_points(newS, s[i], p);
    }
    return current;
}

circle min_circle(std::vector<point>& s) {
    std::random_shuffle(s.begin(), s.end());
    circle current = circle((s[0] + s[1]) / 2.0, (s[0] - s[1]).len() / 2.0);
    for (size_t i = 2; i < s.size(); i++) {
        if (inside(current, s[i])) {
            continue;
        }
        std::vector<point> newS(s.begin(), s.begin() + i);
        current = min_circle_with_point(newS, s[i]);
    }
    return current;
}

int main() {
    //freopen("tower.in", "r", stdin);
    //freopen("tower.out", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<point> p(n);
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    if (n == 1) {
        printf("0\n%.15f %.15f\n", p[0].x, p[0].y);
        return 0;
    }
    circle ans = min_circle(p);
    printf("%.15f\n", ans.r);
    printf("%.15f %.15f\n", ans.x, ans.y);
    return 0;
}