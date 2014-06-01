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

const int maxn = 2e5 + 10;
 
int r, n, m;
int E[4];
int a[maxn][4];
int vs[maxn];
int size = 0;
int t[maxn * 3][4];
int N;

void operation(int v, int vl, int vr) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      int ind = (i << 1) + j;
      t[v][ind] = 0;
      for (int k = 0; k < 2; k++)
        t[v][ind] += (t[vl][(i << 1) + k] * t[vr][(k << 1) + j]);
      t[v][ind] %= r;
    }        
}
 
void build(int _n) {
  N = 1;
  while (N < _n)
    N <<= 1;
  for (int i = 0; i < (N << 1); i++)
    for (int j = 0; j < 4; j++)
      t[i][j] = E[j];
  for (int i = 0; i < _n; i++)
    for (int j = 0; j < 4; j++)
      t[i + N][j] = a[i][j];
  for (int i = N - 1; i > 0; i--)
    operation(i, i << 1, (i << 1) + 1);
}
 
void get(int v, int a, int b, int l, int r) {
  if (l > b || a > r)
    return;
  if (l <= a && b <= r) {
    vs[size++] = v;
    return;
  }
  int m = (a + b) >> 1;
  get(v << 1, a, m, l, r);
  get((v << 1) + 1, m + 1, b, l, r);
}
 
void get(int l, int r) {
  get(1, N, (N << 1) - 1, l + N, r + N);
}
 
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

int ans[4], tans[4];
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &r);
  E[0] = E[3] = 1 % r;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++) {
      read_num(a[i][j]);
      a[i][j] = (a[i][j] % r + r) % r;
    }
 
  build(n);
  for (int it = 0; it < m; it++) {
    int L, R;
    scanf("%d%d", &L, &R);
    --L, --R;
    size = 0;
    get(L, R);
    ans[0] = ans[3] = 1 % r;
    ans[1] = ans[2] = 0;
    for (int j = 0; j < size; j++) {
      for (int I = 0; I < 2; I++)
        for (int J = 0; J < 2; J++) {
          int ind = (I << 1) + J;
          tans[ind] = 0;
          for (int K = 0; K < 2; K++)
            tans[ind] += (ans[(I << 1) + K] * t[vs[j]][(K << 1) + J]);
          tans[ind] %= r;
        }
      for (int I = 0; I < 4; I++)
        ans[I] = tans[I];
    }
    for (int x = 0; x < 2; x++, putchar('\n'))
      for (int y = 0; y < 2; y++)
        print_num(ans[(x << 1) + y]);
    putchar('\n');
  } 
  return 0;
}
