#define TASKNAME "logo2"
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

const int maxn = 2e3 + 10;

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
int type[maxn], x[maxn];
pt now, v;
char s[100];

inline bool read_num(int &x)
{
  gets(s);
  if (s[0] == '?')
    return 0;
  int len = strlen(s);
  x = 0;
  for (int i = 0; i < len; i++)
    x = x * 10 + s[i] - '0';
  return 1;
}

inline int Round(ld x)
{
  int c = int(ceil(x));
  if (fabs(x - c) <= 0.5)
    return c;
  return c - 1;
}

inline void process()
{
  now = pt(0.0, 0.0), v = pt(0.0, 1.0);
  for (int i = 0; i < n; i++)
  {
    int X = x[i];
    if (type[i] > 1)
    {
      X = (X % 360 + 360) % 360;
      ld angle = X * M_PI / 180.0;
      if (type[i] == 3)
        angle = -angle;
      ld vx = v.x * cos(angle) - v.y * sin(angle);
      ld vy = v.x * sin(angle) + v.y * cos(angle);
      v = pt(vx, vy);
      //eprintf("V: %.5lf %.5lf\n", vx, vy);
    }
    else
    {
      if (type[i] == 1)
        X = -X;
      now.x += v.x * X;
      now.y += v.y * X;
      //eprintf("%.20lf %.20lf\n", now.x, now.y);
    }
  }
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++)
  {
    scanf("%d\n", &n);
    int id = -1;
    for (int i = 0; i < n; i++)
    {
      char c1, c2;
      int X = 0;
      scanf("%c%c ", &c1, &c2);
      assert(c2 == 't' || c2 == 'd' || c2 == 'k');
      bool ttt = read_num(X);
      //eprintf("%c%c %d\n", c1, c2, X);
      x[i] = X;
      if (c1 == 'f')
        type[i] = 0;
      else
      if (c1 == 'b')
        type[i] = 1;
      else
      if (c1 == 'l')
        type[i] = 2;
      else
      if (c1 == 'r')
        type[i] = 3;
      else
        assert(0);
      if (!ttt)
        id = i;
    }
    assert(id != -1);
    if (type[id] <= 1)
    {
      process();
      int ans = Round(now.len());
      for (int i = 0; i < 2; i++)
      {
        x[id] = ans * (!i ? -1 : 1);
        process();
        if (fabs(now.len()) <= EPS)
        {
          printf("%d\n", x[id]);
          break;
        }
      }
    }
    else
    {
      for (int i = 0; i < 360; i++)
      {
        x[id] = i;
        process();
        if (fabs(now.len()) <= EPS)
        {
          printf("%d\n", i);
          break;
        }
      }
    }        
  }
  return 0;
}

