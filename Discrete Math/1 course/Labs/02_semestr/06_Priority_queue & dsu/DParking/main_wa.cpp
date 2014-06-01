#define TASKNAME "parking"
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

struct ST {
  vpii t;
  int n;

  ST() {t.clear(), n = 0;}
  ST(int _n) {
    n = 1;
    while (n < _n)
      n <<= 1;
    t.resize(n << 1);
    for (int i = 0; i < (n << 1); i++)
      t[i] = mp(0, INF);
  }

  inline void update(int v, int x) {
    v += n;
    t[v] = mp(x, v - n);
    v >>= 1;
    while (v)
      t[v] = min(t[v << 1], t[(v << 1) + 1]), v >>= 1;
  }

  inline pii get(int v, int a, int b, int l, int r) {
    if (l > b || a > r)
      return mp(INF, INF);
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    return min(get(v << 1, a, m, l, r), get((v << 1) + 1, m + 1, b, l, r));
  }

  inline pii get(int l, int r) {
    return get(1, n, (n << 1) - 1, l + n, r + n);
  }                                            
} tree;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  char s[10];
  scanf("%d%d", &n, &m);
  tree = ST(n);
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%s%d", s, &x);
    --x;
    if (s[1] == 'n') {
      pii t = tree.get(x, n);
      if (t.snd)
        t = tree.get(0, x);
      printf("%d\n", t.snd + 1);
    } else {
      tree.update(x, 0);
    }
  }
  return 0;
}

