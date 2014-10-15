#define TASKNAME "spy"
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
 
#define EPS (1e-9)
#define INF (int(1e9))
#define INFLONG (long long)(1e18)
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
#define next dlkjdslfkdj
#define prev dsdflksdfjl
#define hash lkdfjldskfj
#define pi 3.1415926535897932384626433832795
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

struct pt
{
  double x, y;
  pt() {x = y = 0;}
  pt(double x, double y) : x(x), y(y) {}
};

inline bool operator == (const pt &a, const pt &b) {return fabs(a.x - b.x) <= EPS && fabs(a.y - b.y) <= EPS;}
                                                     
struct line
{
  double a, b, c;
  line() {a = b = c = 0;}
  line(pt p1, pt p2)
  {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -a * p1.x - b * p1.y;
  }
};

inline pair <pt, pt> intersec(line l, double r)
{
  double x0 = -l.a * l.c / (l.a * l.a + l.b * l.b);
  double y0 = -l.b * l.c / (l.a * l.a + l.b * l.b);
  double d = sqrt(r * r - l.c * l.c / (l.a * l.a + l.b * l.b));
  double mult = sqrt(d * d / (l.a * l.a + l.b * l.b));
  double ax = x0 + l.b * mult;
  double ay = y0 - l.a * mult;
  double bx = x0 - l.b * mult;
  double by = y0 + l.a * mult;
  return mp(pt(ax, ay), pt(bx, by));
}

inline double len2(pt a, pt b)
{
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  double r;
  pt a, b;
  cin >> r;
  cin >> a.x >> a.y >> b.x >> b.y;
  line l = line(a, b);
  pair <pt, pt> ps = intersec(l, r);
  if (ps.fst == a)
    printf(len2(ps.snd, b) >= len2(ps.fst, b) ? "YES" : "NO");
  else
    printf(len2(ps.fst, b) >= len2(ps.snd, b) ? "YES" : "NO");
  return 0;
}

