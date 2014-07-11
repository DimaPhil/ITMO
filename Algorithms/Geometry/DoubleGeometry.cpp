#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

/* Start copying from here */

double sign(double x) {
    return x > EPS ? 1 : (fabs(x) <= EPS ? 0 : -1);
}

double sqr(double x) {
    return x * x;
}

/* Forward declaration */
struct Point;
struct Line;
bool parallel(Line const& l1, Line const& l2);
double distanceTo(Line const& l, Point const& p);

/* Point */

struct Point {
    double x, y;
    Point() {x = y = 0.0;}
    Point(double x, double y) : x(x), y(y) {}

    /* Reading */

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    /* Printing */

    void print() {
        printf("%.10lf %.10lf\n", x, y);
    }                

    void eprint() {
        fprintf(stderr, "%.5lf %.5lf\n", x, y);
    }

    /* Length */

    double len2() {
        return sqr(x) + sqr(y);
    }

    double len() {
        return sqrt(len2());
    }

    /* Operators */

    Point& operator += (Point const& p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point& operator -= (Point const& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Point& operator *= (double p) {
        x *= p;
        y *= p;
        return *this;
    }

    Point& operator /= (double p) {
        x /= p;
        y /= p;
        return *this;
    }

    Point operator - () const {
        Point p = *this;
        p.x = -p.x;
        p.y = -p.y;
        return p;
    }

    /* Useful functions */

    Point& normalize() {
        double length = len();
        x /= length;
        y /= length;
        return *this;
    }

    Point& rotate(double sinus, double cosinus) {
        double newx = x * cosinus - y * sinus;
        double newy = y * cosinus + x * sinus;
        x = newx;
        y = newy;
        return *this;
    }

    Point& rotate(double alpha) {
        return rotate(sin(alpha), cos(alpha));
    }
} pNone = Point(1e18, 1e18);

/* Operators */

Point operator + (Point a, Point const& b) {
    return a += b;
}     

Point operator - (Point a, Point const& b) {
    return a -= b;
}

Point operator * (Point a, double const& b) {
    return a *= b;
}

Point operator / (Point a, double const& b) {
    return a /= b;
}

/* Equate operators */

bool operator < (Point const& a, Point const& b) {
    return a.x < b.x - EPS || (fabs(a.x - b.x) <= EPS && a.y < b.y - EPS);
}

bool operator == (Point const& a, Point const& b) {
    return fabs(a.x - b.x) <= EPS && fabs(a.y - b.y) <= EPS;
}

bool operator > (Point const& a, Point const& b) {
    return a.x > b.x + EPS || (fabs(a.x - b.x) <= EPS && a.y > b.y + EPS);
}

bool operator <= (Point const& a, Point const& b) {
    return !(a > b);
}

bool operator >= (Point const& a, Point const& b) {
    return !(a < b);
}

/* Cross and dot products */

double operator * (Point const& a, Point const& b) {
    return a.x * b.x + a.y * b.y;
}

double operator & (Point const& a, Point const& b) {
    return a.x * b.y - a.y * b.x;
}

double dotProduct(Point const& a, Point const& b) {
    return a * b;
}

double crossProduct(Point const& a, Point const& b) {
    return a & b;
}

/* Useful functions */

Point normalize(Point p) {
    return p.normalize();
}

Point rotate(Point p, double sinus, double cosinus) {
    return p.rotate(sinus, cosinus);
}

Point rotate(Point p, double alpha) {
    return p.rotate(alpha);
}

void swap(Point &a, Point &b) {
    swap(a.x, b.x);
    swap(a.y, b.y);
}

/* Segment */

struct Segment {
    Point l, r;
    Segment() {}
    Segment(Point const& l, Point const& r) : l(l), r(r) {}

    /* Ends correction */

    void endsCorrection() {
        if (l > r)
          swap(l, r);
    }                     

    /* Reading */

    void read() {
        l.read();
        r.read();
        endsCorrection();
    }

    /* Printing */

    void print() {
        endsCorrection();
        printf("%.10lf %.10lf %.10lf %.10lf\n", l.x, l.y, r.x, r.y);
    }

    void eprint() {
        endsCorrection();
        fprintf(stderr, "%.5lf %.5lf %.5lf %.5lf\n", l.x, l.y, r.x, r.y);
    }

    /* Length */

    double len2() {
        return (r - l).len2();
    }

    double len() {
        return (r - l).len();
    }

    /* Useful functions */

    bool contains(Point const& p) {
        return fabs((p - l) & (r - l)) <= EPS && (p - l) * (r - l) >= -EPS && (p - r) * (l - r) >= -EPS;
    }

    bool contains(Segment const& s) {
        return contains(s.l) && contains(s.r);
    }
};

/* Equate operators */

bool operator == (Segment const& s1, Segment const& s2) {
    return s1.l == s2.l && s1.r == s2.r;
}

bool operator != (Segment const& s1, Segment const& s2) {
    return !(s1 == s2);
}

/* Useful functions */

bool contains(Segment s, Point const& p) {
    return s.contains(p);
}

bool contains(Segment s1, Segment const& s2) {
    return s1.contains(s2);
}

/* Line */

struct Line {
    double a, b, c;
    Line() {a = b = c = 0.0;}
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
    Line(Point const& p1, Point const& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
    }
    Line(Segment const& s) {
        *this = Line(s.l, s.r);
    }

    /* Reading */

    void read() {
        scanf("%lf%lf%lf", &a, &b, &c);
    }                                

    /* Printing */

    void print() {
        printf("%.10lf %.10lf %.10lf\n", a, b, c);
    }

    void eprint() {
        fprintf(stderr, "%.5lf %.5lf %.5lf\n", a, b, c);
    }

    void printNormalized() {
        assert(fabs(a) > EPS || fabs(b) > EPS);
        double d = sqrt(a * a + b + b);
        printf("%.10lf %.10lf %.10lf\n", a / d, b / d, c / d);
    }

    void eprintNormalized() {
        assert(fabs(a) > EPS || fabs(b) > EPS);
        double d = sqrt(a * a + b + b + 0.0);
        fprintf(stderr, "%.5lf %.5lf %.5lf\n", a / d, b / d, c / d);
    }

    /* Useful functions */

    Line& normalize() {
        assert(fabs(a) >= EPS || fabs(b) >= EPS);
        double d = sqrt(a * a + b * b);
        a /= d;
        b /= d;
        c /= d;
        return *this;
    }

    double substitute(Point const& p) {
        return a * p.x + b * p.y + c;
    }

    bool contains(Point const& p) {
        return fabs(substitute(p)) <= EPS;
    }

    bool contains(Segment const& s) {
        return contains(s.l) && contains(s.r);
    }
};

/* Equate operators */

bool operator == (Line const& l1, Line const& l2) {
    return parallel(l1, l2) && fabs(l1.a * l2.c - l1.c * l2.a) <= EPS;
}

bool operator != (Line const& l1, Line const& l2) {
    return !(l1 == l2);
}

/* Useful functions */

Line normalize(Line l) {
    return l.normalize();
}

double substitute(Line l, Point const& p) {
    return l.substitute(p);
}

bool contains(Line l, Point const& p) {
    return l.contains(p);
}

bool contains(Line l, Segment const& s) {
    return l.contains(s);
}

/* Intersections, parallels and so on */

bool intersect(Segment const& s1, Segment const& s2) {
    Line thisLine = Line(s1);
    Line otherLine = Line(s2);
    if (parallel(thisLine, otherLine))
        return thisLine == otherLine && max(s1.l, s2.l) <= min(s1.r, s2.r);
    return sign(thisLine.substitute(s2.l)) != sign(thisLine.substitute(s2.r)) &&
           sign(otherLine.substitute(s1.l)) != sign(otherLine.substitute(s1.r));
}

bool parallel(Segment const& s1, Segment const& s2) {
    return parallel(Line(s1), Line(s2));
}

bool intersect(Line const& l1, Line const& l2) {  //lines must be non-equal
    assert(l1 != l2);
    return !parallel(l1, l2);
}

bool parallel(Line const& l1, Line const& l2) {
    return fabs(l1.a * l2.b - l1.b * l2.a) <= EPS;
}

bool intersect(Line const& l, Segment const& s) {
    if (parallel(l, s))
        return l == Line(s);
    return sign(substitute(l, s.l)) != sign(substitute(l, s.r));
}

bool parallel(Line const& l, Segment const& s) {
    return parallel(l, Line(s));
}

/* Distances */

double distanceTo(Point const& p1, Point const& p2) {
    return (p2 - p1).len();
}

double distanceTo(Segment const& s, Point const& p) {
    if ((p - s.l) * (s.r - s.l) >= -EPS && (p - s.r) * (s.l - s.r) >= -EPS)
        return distanceTo(Line(s), p);
    return min(distanceTo(s.l, p), distanceTo(s.r, p));
}

double distanceTo(Segment const& s1, Segment const& s2) {
    if (intersect(s1, s2))
        return 0.0;
    double minFirst = min(distanceTo(s2, s1.l), distanceTo(s2, s1.r));
    double minSecond = min(distanceTo(s1, s2.l), distanceTo(s1, s2.r));
    return min(minFirst, minSecond);
}

double distanceTo(Line const& l, Point const& p) {
    return fabs(substitute(l, p)) / sqrt(sqr(l.a) + sqr(l.b));
}

double distanceTo(Line const& l, Segment const& s) {
    if (intersect(l, s))
        return 0;
    return min(distanceTo(l, s.l), distanceTo(l, s.r));
}

double distanceTo(Line l1, Line l2) {
    if (!parallel(l1, l2))
        return 0.0;
    l1.normalize();
    l2.normalize();
    return fabs(l1.c - l2.c);
}