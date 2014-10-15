#define TASKNAME "logo"
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
  ld x, y;
  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}

  inline ld len2()
  {
    return x * x + y * y;
  }

  inline ld len()
  {
    return sqrt(len2());
  }
};

int t, n;

inline int Round(ld x)
{
  int c = int(ceil(x));
  if (fabs(x - c) <= 0.5)
    return c;
  return c - 1;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++)
  {
    scanf("%d\n", &n);
    pt now = pt(0.0, 0.0), v = pt(0.0, 1.0);
    for (int i = 0; i < n; i++)
    {
      char c1, c2;
      int x;
      scanf("%c%c%d\n", &c1, &c2, &x);
      if (c2 == 't')
      {
        x = (x % 360 + 360) % 360;
        ld angle = x * M_PI / 180.0;
        if (c1 == 'r')
          angle = -angle;
        ld vx = v.x * cos(angle) - v.y * sin(angle);
        ld vy = v.x * sin(angle) + v.y * cos(angle);
        v = pt(vx, vy);
        //eprintf("V: %.5lf %.5lf\n", vx, vy);
      }
      else
      {
        if (c1 == 'b')
          x = -x;
        now.x += v.x * x;
        now.y += v.y * x;
        //eprintf("%.20lf %.20lf\n", now.x, now.y);
      }
    }
    printf("%d\n", Round(now.len()));
  }
  return 0;
}

