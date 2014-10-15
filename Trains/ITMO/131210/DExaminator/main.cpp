#define TASKNAME "examinator"
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

struct ST
{
  vi t;
  int n;

  ST() {t.clear(), n = 0;}
  ST(int _n)
  {
    n = 1;
    while (n < _n)
      n <<= 1;
    t.resize(n << 1);
    for (int i = 0; i < (n << 1); i++)
      t[i] = 0;
  }

  inline void update(int v, int x)
  {
    v += n;
    t[v] += x;
    v >>= 1;
    while (v)
      t[v] = t[v << 1] + t[(v << 1) + 1], v >>= 1;
  }     

  inline int get(int v, int a, int b, int l, int r)
  {
    if (l > b || a > r)
      return 0;
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    return get(v << 1, a, m, l, r) + get((v << 1) + 1, m + 1, b, l, r);
  }

  inline int get(int l, int r)
  {
    if (l == -1 || r == -1)
      return 0;
    if ((l == -1 && r != -1) || (l != -1 && r == -1))
      assert(0);
    if (l > r)
      swap(l, r);
    return get(1, n, (n << 1) - 1, l + n, r + n);
  }
};

const int maxn = 2e5 + 100;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  int cnt = maxn - 1;
  ST tree = ST(maxn);
  vi place(maxn, -1);
  for (int it = 0; it < n; it++)
  {
    int type;
    scanf("%d", &type);
    if (!type)
    {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", tree.get(place[l], place[r]));
    }
    if (type == 1)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      if (!b)
      {
        assert(place[a] == -1);
        place[a] = cnt--;
        tree.update(place[a], 1);
      }
      else
      {
        assert(place[a] == -1);
        assert(place[b] != -1);
        place[a] = place[b];
        tree.update(place[a], 1);
      }
    }
    if (type == 2)
    {
      int a;
      scanf("%d", &a);
      if (place[a] != -1)
        tree.update(place[a], -1);
      place[a] = -1;
    }
  }          
  return 0;
}

