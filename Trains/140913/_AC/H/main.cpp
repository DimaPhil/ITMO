#define TASKNAME "text"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
 
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

struct pt {
    double x, y;
    pt() {x = y = 0;}
    pt(double x, double y) : x(x), y(y) {}

    double len2() {
        return x * x + y * y;
    }

    double len() {
        return sqrt(len2());
    }

    void norm() {
        double length = len();
        x /= length;
        y /= length;
    }

    void read() {
        cin >> x >> y;
    }

    void print() {
        cout.precision(20);
        cout << x << " " << y << '\n';
    }
};        

pt operator - (const pt &a, const pt &b) {return pt(a.x - b.x, a.y - b.y);}
pt operator + (const pt &a, const pt &b) {return pt(a.x + b.x, a.y + b.y);}
pt operator / (const pt &a, double b) {return pt(a.x / b, a.y / b);}
pt operator * (const pt &a, double b) {return pt(a.x * b, a.y * b);}

pt p[4];

pt turn(pt p, double sinus, double cosinus) {
    pt ans;
    ans.x = p.x * cosinus - p.y * sinus;
    ans.y = p.y * cosinus + p.x * sinus;
    return ans;
}

void buildSquare(pt p1, pt p2) {
    double sinus = sqrt(2) / 2;
    double cosinus = sqrt(2) / 2;
    pt P = turn((p2 - p1) / sqrt(2), sinus, cosinus) + p1;
    pt Q = turn((p2 - p1) / sqrt(2), -sinus, cosinus) + p1;
    p[0] = p1;
    p[1] = P;
    p[2] = p2;
    p[3] = Q;
}

double scal(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

pt minDist(pt p, pt a, pt b) {
    if (scal(p - a, b - a) >= EPS && scal(p - b, a - b) >= EPS) {
        double A = b.y - a.y;
        double B = a.x - b.x;
        double C = -A * a.x - B * a.y;
        double dist = fabs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
        double d = sqrt((p - a).len2() - dist * dist);
        pt tmp = (b - a);
        tmp.norm();
        return a + tmp * d;
    }
    double dist = min((p - a).len2(), (p - b).len2());
    if (fabs(dist - (p - a).len2()) <= EPS)
        return a;
    return b;
}

pt minDist(pt p, pt *sq) {
    double mn = 1e18;
    pt ans = pt(1e18, 1e18);
    for (int i = 0; i < 4; i++) {
        pt x = sq[i];
        pt y = sq[(i + 1) % 4];
        pt np = minDist(p, x, y);
        if ((np - p).len() < mn - EPS)
            mn = (np - p).len(), ans = np;
    }
    return ans;           
}

int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  int r;
  cin >> r;
  pt a, b;
  a.read();
  b.read();

  buildSquare(a, b);
  pt pp = minDist(pt(0, 0), p);
  double d = pp.len();
  d -= r;
  d /= 2;
  d += r;
  pt ans = pp;
  pp.norm();
  pp = pp * d;
  pp.print();

  pt q = pt(1.35355339059327, 1.35355339059327);
  cout << q.len() - 1 << '\n';
  cout << (minDist(q, p) - q).len();
  return 0;
}
