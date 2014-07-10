#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;

const ll MaxLong = 9223372036854775807LL;

/* Start copying from here */

int sign(int x) {
    return x > 0 ? 1 : (!x ? 0 : -1);
}

ll sign(ll x) {
    return x > 0 ? 1 : (!x ? 0 : -1);
}

/* struct for Point */

struct Point {
    ll x, y;
    Point() {x = y = 0;}
    Point(ll x, ll y) : x(x), y(y) {}

    /* reading and printing */

    void read() {
        scanf(LLD""LLD, &x, &y);
    }

    void print() {
        printf(LLD" "LLD"\n", x, y);
    }                

    void eprint() {
        fprintf(stderr, LLD" "LLD"\n", x, y);
    }

    /* Length, operators */

    ll len2() {
        return x * x + y * y;
    }

    double len() {
        return sqrt(len2() + 0.0);
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

    Point& operator *= (ll p) {
        x *= p;
        y *= p;
        return *this;
    }

    Point operator - () const {
        Point p = *this;
        p.x = -p.x;
        p.y = -p.y;
        return p;
    }
} pNone = Point(MaxLong, MaxLong);

Point operator + (Point a, Point const& b) {
    return a += b;
}     

Point operator - (Point a, Point const& b) {
    return a -= b;
}

Point operator * (Point a, ll const& b) {
    return a *= b;
}

bool operator < (Point const& a, Point const& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator == (Point const& a, Point const& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator > (Point const& a, Point const& b) {
    return a.x > b.x || (a.x == b.x && a.y > b.y);
}

bool operator <= (Point const& a, Point const& b) {
    return !(a > b);
}

bool operator >= (Point const& a, Point const& b) {
    return !(a < b);
}

/* cross and dot products */

ll operator * (Point const& a, Point const& b) {
    return a.x * b.x + a.y * b.y;
}

ll operator & (Point const& a, Point const& b) {
    return a.x * b.y - a.y * b.x;
}

ll dotProduct(Point const& a, Point const& b) {
    return a * b;
}

ll crossProduct(Point const& a, Point const& b) {
    return a & b;
}

/* some useful functions */

void swap(Point &a, Point &b) {
    swap(a.x, b.x);
    swap(a.y, b.y);
}

/* struct for Line */

struct Line {
    ll a, b, c;
    Line() {a = b = c = 0;}
    Line(ll a, ll b, ll c) : a(a), b(b), c(c) {}
    Line(Point const& p1, Point const& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
    }

    /* printing line */

    void print() {
        printf(LLD" "LLD" "LLD"\n", a, b, c);
    }

    void eprint() {
        fprintf(stderr, LLD" "LLD" "LLD"\n", a, b, c);
    }

    void printNormalized() {
        assert(a || b);
        double d = sqrt(a * a + b + b + 0.0);
        printf("%.10lf %.10lf %.10lf\n", a / d, b / d, c / d);
    }

    void eprintNormalized() {
        assert(a || b);
        double d = sqrt(a * a + b + b + 0.0);
        fprintf(stderr, "%.5lf %.5lf %.5lf\n", a / d, b / d, c / d);
    }

    /* some useful functions */

    ll substitute(Point const& p) {
        return a * p.x + b * p.y + c;
    }

    bool contains(Point const& p) {
        return !substitute(p);
    }

    bool parallel(Line const& l) {
        return a * l.b == b * l.a;
    }

    bool equal(Line const& l) {
        return parallel(l) && a * l.c == b * l.a;
    }

    bool intersect(Line const& l) {
        return !parallel(l) && !equal(l);
    }
};

ll substitute(Line l, Point const& p) {
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
        printf(LLD" "LLD" "LLD" "LLD"\n", l.x, l.y, r.x, r.y);
    }

    void eprint() {
        endsCorrection();
        fprintf(stderr, LLD" "LLD" "LLD" "LLD"\n", l.x, l.y, r.x, r.y);
    }

    /* Length */

    ll len2() {
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
        return !((p - l) & (r - l)) && (p - l) * (r - l) >= 0 && (p - r) * (l - r) >= 0;
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