#define TASKNAME "rsq"
 
#include <cstdio>
#include <iostream>
 
#include <cmath>
#include <algorithm>
#include <functional>
 
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
 
#include <ctime>
#include <cassert>
 
#include <map>
#include <set>
#include <vector>
  
#define EPS (1e-9)
#define INF int(1e9)
#define INFLONG (long long)(1e18)
#define sqr(a) ((a) * (a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
#ifdef WIN32
  #define LLD "%I64d"
#else
  #define LLD "%lld"
#endif
  
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <ll> vll;
typedef vector <vll> vvll; 
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;
 
struct ST {
  vll t;
  int n;
 
  ST() {t.clear(), n = 0;}
  ST(vi &a) {
    int _n = sz(a);
    n = 1;
    while (n < _n)
      n <<= 1;
    t.resize(n << 1);
    for (int i = 0; i < n; i++)
      t[i] = 0;
    for (int i = 0; i < _n; i++)
      t[i + n] = a[i];
    for (int i = n - 1; i > 0; i--)
      t[i] = t[i << 1] + t[(i << 1) + 1];
  }
 
  inline void update(int v, int x) {
    v += n;
    t[v] = x;
    v >>= 1;
    while (v)
      t[v] = t[v << 1] + t[(v << 1) + 1], v >>= 1;
  }
 
  inline ll get(int v, int a, int b, int l, int r) {
    if (l > b || a > r)
      return 0;
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    return get(v << 1, a, m, l, r) + get((v << 1) + 1, m + 1, b, l, r);
  }
 
  inline ll get(int l, int r) {
    return get(1, n, (n << 1) - 1, l + n, r + n);
  }
};
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vi a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  ST tree = ST(a);
  char s[5];
  while (scanf("%s", s) >= 1) {
    if (s[1] == 'e') {
      int x, val;
      scanf("%d%d", &x, &val);
      --x;
      tree.update(x, val); 
    } 
    else {
      int x, y;
      scanf("%d%d", &x, &y);
      --x, --y;
      printf("%I64d\n", tree.get(x, y));
    }
  }
  return 0;
}