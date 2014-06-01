#define TASKNAME "crypto"
 
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
 
int r;
vi E(4, 0);
 
struct ST {
  vector <vi> t;
  int n;
 
  inline void operation(vi &c, vi &a, vi &b) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        c[(i << 1) + j] = 0;
        for (int k = 0; k < 2; k++)
          c[(i << 1) + j] += (a[(i << 1) + k] * b[(k << 1) + j]);
        c[(i << 1) + j] %= r;
      }        
  }
 
  ST() {t.clear(), n = 0;}
  ST(vector <vi> &a) {
    int _n = sz(a);
    n = 1;
    while (n < _n)
      n <<= 1;
    t.resize(n << 1);
    for (int i = 0; i < (n << 1); i++)
      t[i] = E;
    for (int i = 0; i < _n; i++)
      t[i + n] = a[i];
    for (int i = n - 1; i > 0; i--)
      operation(t[i], t[i << 1], t[(i << 1) + 1]);
  }
 
  inline void update(int v, vi &x) {
    v += n;
    t[v] = x;
    v >>= 1;
    while (v)
      operation(t[v], t[v << 1], t[(v << 1) + 1]), v >>= 1;
  }
 
  inline vi get(int v, int a, int b, int l, int r) {
    if (l > b || a > r)
      return E;
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    vi ans(4);
    vi L = get(v << 1, a, m, l, r);
    vi R = get((v << 1) + 1, m + 1, b, l, r);
    operation(ans, L, R);
    return ans;
  }
 
  inline vi get(int l, int r) {
    return get(1, n, (n << 1) - 1, l + n, r + n);
  }
};
 
char c;
 
inline void read_num(int &x) {
  while ((c = getchar()) != EOF) {
    if (c == 32 || c == 13 || c == 10)
      continue;
    break;
  }
  x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}         
 
inline void print_num(int x) {
  if (!x) {
    putchar('0');
    putchar(' ');
    return;
  }
  int digits[5];
  int c = 0;
  while (x)
    digits[c++] = x % 10, x /= 10;
  for (int i = c - 1; i >= 0; i--)
    putchar(digits[i] + '0');
  putchar(' ');
}
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen("stress.out", "w", stdout);
  scanf("%d", &r);
  E[0] = E[3] = 1 % r;
  int n, m;
  scanf("%d%d", &n, &m);
  vector <vi> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(4);
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++)
        read_num(a[i][(j << 1) + k]);
    }
  }
 
  ST tree = ST(a);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    vi ans = tree.get(l, r);
    for (int x = 0; x < 2; x++, putchar('\n'))
      for (int y = 0; y < 2; y++)
        print_num(ans[(x << 1) + y]);
    putchar('\n');
  }
  return 0;
}