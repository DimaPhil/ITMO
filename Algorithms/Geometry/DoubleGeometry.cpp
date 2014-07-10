#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

/* Start copying from here */

double sign(double x) {
    return x > EPS ? 1 : (fabs(x) <= EPS ? 0 : -1);
}

/* struct for Point */

struct Point {
    double x, y;
    Point() {x = y = 0.0;}
    Point(double x, double y) : x(x), y(y) {}

    /* reading and printing */

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    void print() {
        printf("%.10lf %.10lf\n", x, y);
    }                

    void eprint() {
        fprintf(stderr, "%.5lf %.5lf\n", x, y);
    }

    /* Length, operators */

    double len2() {
        return x * x + y * y;
    }

    double len() {
        return sqrt(len2());
    }

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

    /* some useful functions */

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

/* operators */

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

/* useful functions */

Point normalize(Point p) {
    return p.normalize();
}

Point rotate(Point p, double sinus, double cosinus) {
    return p.rotate(sinus, cosinus);
}

Point rotate(Point p, double alpha) {
    return p.rotate(alpha);
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

/* cross and dot products */

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

/* some useful functions */

void swap(Point &a, Point &b) {
    swap(a.x, b.x);
    swap(a.y, b.y);
}

/* struct for Line */

struct Line {
    double a, b, c;
    Line() {a = b = c = 0.0;}
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
    Line(Point const& p1, Point const& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
    }

    /* printing line */

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

    /* some useful functions */

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

    bool parallel(Line const& l) {
        return fabs(a * l.b - b * l.a) <= EPS;
    }

    bool equal(Line const& l) {
        return parallel(l) && fabs(a * l.c - b * l.a) <= EPS;
    }

    bool intersect(Line const& l) {
        return !parallel(l) && !equal(l);
    }

    double distance(Point const& p) {
        return fabs(substitute(p)) / sqrt(a * a + b * b);
    }

    double distance(Line l) {
        if (!parallel(l))
            return 0.0;
        Line thisLine = *this;
        thisLine.normalize();
        l.normalize();
        return thisLine.c - l.c;
    }
};

Line normalize(Line l) {
    return l.normalize();
}

double substitute(Line l, Point const& p) {
    return l.substitute(p);
}

bool contains(Line l, Point const& p) {
    return l.contains(p);
}

bool equal(Line l1, Line const& l2) {
    return l1.equal(l2);
}

bool parallel(Line l1, Line const& l2) {
    return l1.parallel(l2);
}

bool intersect(Line l1, Line const& l2) {
    return l1.intersect(l2);
}

double distance(Line l, Point const& p) {
    return l.distance(p);
}

double distance(Line l1, Line l2) {
    return l1.distance(l2);
}

/* struct for Segment */

struct Segment {
    Point l, r;
    Segment() {}
    Segment(Point const& l, Point const& r) : l(l), r(r) {}

    /* ends correction */

    void endsCorrection() {
        if (l > r)
          swap(l, r);
    }                     

    /* reading and printing */

    void read() {
        l.read();
        r.read();
        endsCorrection();
    }

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

    /* some useful functions */

    bool parallel(Segment const& s) {
        return Line(l, r).parallel(Line(s.l, s.r));
    }

    bool intersect(Line const& otherLine) {
        return sign(substitute(otherLine, l)) != sign(substitute(otherLine, r));
    }

    bool intersect(Segment const& s) {
        Line thisLine = Line(l, r);
        Line otherLine = Line(s.l, s.r);
        if (thisLine.parallel(otherLine))
            return thisLine.equal(otherLine) && max(l, s.l) <= min(r, s.r);
        return sign(thisLine.substitute(s.l)) != sign(thisLine.substitute(s.r)) &&
               sign(otherLine.substitute(l)) != sign(otherLine.substitute(r));
    }

    bool contains(Point const& p) {
        return fabs((p - l) & (r - l)) <= EPS && (p - l) * (r - l) >= -EPS && (p - r) * (l - r) >= -EPS;
    }

    bool contains(Segment const& s) {
        return contains(s.l) && contains(s.r);
    }
};

bool parallel(Segment s1, Segment const& s2) {
    return s1.parallel(s2);
}

bool intersect(Segment s, Line const& l) {
    return s.intersect(l);
}

bool intersect(Segment s1, Segment const& s2) {
    return s1.intersect(s2);
}

bool contains(Line l, Segment const& s) {
    return l.contains(s.l) && l.contains(s.r);
}