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

const int MaxInt = 2147483647;
const ll MaxLong = 9223372036854775807LL;

/* Start copying from here */

int sign(int x) {
    return x > 0 ? 1 : (!x ? 0 : -1);
}

ll sign(ll x) {
    return x > 0 ? 1 : (!x ? 0 : -1);
}

ll sqr(int x) {
    return 1LL * x * x;
}

ll sqr(ll x) {
    return x * x;
}

/* Forward declaration */
struct Line;
bool parallel(Line const& l1, Line const& l2);

/* Point */

struct Point {
    int x, y;
    Point() {x = y = 0;}
    Point(int x, int y) : x(x), y(y) {}

    /* Reading */

    void read() {
        scanf("%d%d", &x, &y);
    }

    /* Printing */

    void print() {
        printf("%d %d\n", x, y);
    }                

    void eprint() {
        fprintf(stderr, "%d %d\n", x, y);
    }

    /* Length */

    ll len2() {
        return sqr(x) + sqr(y);
    }

    double len() {
        return sqrt(len2() + 0.0);
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
} pNone = Point(MaxInt, MaxInt);

/* Operators */

Point operator + (Point a, Point const& b) {
    return a += b;
}     

Point operator - (Point a, Point const& b) {
    return a -= b;
}

Point operator * (Point a, ll const& b) {
    return a *= b;
}

/* Equate operators */

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

/* Cross and dot products */

ll operator * (Point const& a, Point const& b) {
    return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

ll operator & (Point const& a, Point const& b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

ll dotProduct(Point const& a, Point const& b) {
    return a * b;
}

ll crossProduct(Point const& a, Point const& b) {
    return a & b;
}

/* Useful functions */

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
        printf("%d %d %d %d\n", l.x, l.y, r.x, r.y);
    }

    void eprint() {
        endsCorrection();
        fprintf(stderr, "%d %d %d %d\n", l.x, l.y, r.x, r.y);
    }

    /* Length */

    ll len2() {
        return (r - l).len2();
    }

    double len() {
        return (r - l).len();
    }

    /* Useful functions */

    bool contains(Point const& p) {
        return !((p - l) & (r - l)) && (p - l) * (r - l) >= 0 && (p - r) * (l - r) >= 0;
    }

    bool contains(Segment const& s) {
        return contains(s.l) && contains(s.r);
    }
} sNone = Segment(pNone, pNone);

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
    ll a, b, c;
    Line() {a = b = c = 0;}
    Line(ll a, ll b, ll c) : a(a), b(b), c(c) {}
    Line(Point const& p1, Point const& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -1LL * a * p1.x - 1LL * b * p1.y;
    }
    Line(Segment const& s) {
        *this = Line(s.l, s.r);
    }

    /* Reading */

    void read() {
        scanf(LLD""LLD""LLD, &a, &b, &c);
    }

    /* Printing */

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

    /* Useful functions */

    ll substitute(Point const& p) {
        return a * p.x + b * p.y + c;
    }

    bool contains(Point const& p) {
        return !substitute(p);
    }

    bool contains(Segment const& s) {
        return contains(s.l) && contains(s.r);
    }
};

/* Equate operators */

bool operator == (Line const& l1, Line const& l2) {
    return parallel(l1, l2) && l1.a * l2.c == l1.c * l2.a;
}

bool operator != (Line const& l1, Line const& l2) {
    return !(l1 == l2);
}

/* Useful functions */

ll substitute(Line l, Point const& p) {
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
    return l1.a * l2.b == l1.b * l2.a;
}

bool intersect(Line const& l, Segment const& s) {
    if (parallel(l, s))
        return l == Line(s);
    return sign(substitute(l, s.l)) != sign(substitute(l, s.r));
}

bool parallel(Line const& l, Segment const& s) {
    return parallel(l, Line(s));
}