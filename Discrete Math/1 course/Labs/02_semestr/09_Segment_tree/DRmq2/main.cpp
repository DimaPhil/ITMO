#define TASKNAME "rmq2"
 
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
#define INFLONG (long long)(2e18)
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
  vll updAdd, updSet;
  int n;
 
  ST() {t.clear(), updAdd.clear(), updSet.clear(), n = 0;}
  ST(vll &a) {
    int _n = sz(a);
    n = 1;
    while (n < _n)
      n <<= 1;
    t.resize(n << 1);
    updAdd.resize(n << 1);
    updSet.resize(n << 1);
    for (int i = 0; i < (n << 1); i++)
      t[i] = INFLONG, updAdd[i] = 0, updSet[i] = INFLONG;
    for (int i = 0; i < _n; i++)
      t[i + n] = a[i];
    for (int i = n - 1; i > 0; i--)
      t[i] = min(t[i << 1], t[(i << 1) + 1]);
  }
 
  inline void push(int v, int len) {
    //assert(!(updAdd[v] != 0 && updSet[v] != INFLONG));
    if (updSet[v] != INFLONG) {
      t[v] = updSet[v];
      if (v < n) {
        updAdd[v << 1] = updAdd[(v << 1) + 1] = 0;
        updSet[v << 1] = updSet[v];
        updSet[(v << 1) + 1] = updSet[v];
      }
      updSet[v] = INFLONG;
    }
    if (updAdd[v] != 0) {
      t[v] += updAdd[v];
      if (v < n) {
        updAdd[v << 1] += updAdd[v];
        updAdd[(v << 1) + 1] += updAdd[v];
      }    
      updAdd[v] = 0;
    }
  }
 
  inline void update(int v, int a, int b, int l, int r, ll x, int type) {
    push(v, b - a + 1);
    if (l > b || a > r)
      return;
    if (l <= a && b <= r) {
      if (!type)
        updAdd[v] += x;
      else
        updSet[v] = x;
      push(v, b - a + 1);
      return;
    }
    int m = (a + b) >> 1;
    update(v << 1, a, m, l, r, x, type);
    update((v << 1) + 1, m + 1, b, l, r, x, type);
    t[v] = min(t[v << 1], t[(v << 1) + 1]);
  }
 
  inline void update(int l, int r, ll x, int type) {
    update(1, n, (n << 1) - 1, l + n, r + n, x, type);
  }
 
  inline ll get(int v, int a, int b, int l, int r) {
    push(v, b - a + 1);
    if (l > b || a > r)
      return INFLONG;
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    return min(get(v << 1, a, m, l, r), get((v << 1) + 1, m + 1, b, l, r));
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
  vll a(n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &a[i]);
  ST tree = ST(a);
  char s[5];
  while (scanf("%s", s) >= 1) {
    if (s[0] == 'a') {
      int l, r;
      ll val;
      scanf("%d%d%I64d", &l, &r, &val);
      --l, --r;
      tree.update(l, r, val, 0); 
    } else if (s[0] == 's') {
      int l, r;
      ll val;
      scanf("%d%d%I64d", &l, &r, &val);
      --l, --r;
      tree.update(l, r, val, 1);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      --l, --r;
      printf("%I64d\n", tree.get(l, r));
    }
  }
  return 0;
}