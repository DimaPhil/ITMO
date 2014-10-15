#define TASKNAME "matrix"
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

const int maxsize = 1 << 7;

int n, mod;
char a[3][3];
bool goodmsk[1 << 9];

inline int mmod(int x)
{
  return (x % mod + mod) % mod;
}

inline int mmod(ll x)
{
  return (x % (ll)mod + mod) % mod;
}

struct matrix
{
  int n;
  int a[maxsize][maxsize];

  inline void init()
  {
    for (int i = 0; i < maxsize; i++)
      for (int j = 0; j < maxsize; j++)
        a[i][j] = 0;
  }

  inline void init_E()
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        a[i][j] = (i == j ? 1 : 0);
  }

  matrix() 
  {
    n = 0;
    init();
  }
  matrix(int n) : n(n) {init();}

  inline matrix operator + (const matrix &b)
  {
    matrix c(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        c.a[i][j] = mmod(a[i][j] + b.a[i][j]);
    return c;
  }

  inline matrix operator - (const matrix &b)
  {
    matrix c(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        c.a[i][j] = mmod(a[i][j] - b.a[i][j]);
    return c;
  }

  inline matrix operator * (const matrix &b)
  {
    matrix c(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
        {
          c.a[i][j] += mmod((ll)a[i][k] * b.a[k][j]);
          if (c.a[i][j] >= mod)
            c.a[i][j] -= mod;
        }
    return c;
  }

  inline void out()
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        printf("%d%c", a[i][j], " \n"[j == n - 1]);
  }                                
};

inline matrix E(int n)
{
  matrix m(n);
  m.init_E();
  return m;
}

inline matrix power(matrix a, int p)
{
  if (!p)
     return E(1 << 6);
  if (p & 1)
    return power(a, p - 1) * a;
  matrix tmp = power(a, p >> 1);
  return tmp * tmp;
}

inline bool bit(int msk, int b)
{
  return msk & (1 << b);
}

inline bool good(int msk1, int msk2)
{
  bool ok = bit(msk1, 0) == bit(msk2, 3) && bit(msk1, 1) == bit(msk2, 4) && bit(msk1, 2) == bit(msk2, 5);
  int m = (msk2 << 3) + (msk1 >> 3);
  int mask = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      int b = j * 3 + i;
      mask += (1 << b) * bit(m, b);
    }
  ok &= goodmsk[mask];
  return ok;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &mod);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      scanf(" %c", &a[i][j]);
  for (int msk = 0; msk < (1 << 9); msk++)
  {
    bool ok = 1;
    for (int b = 0; b < 9; b++)
    {
      int i = b / 3;
      int j = b % 3;
      if (a[i][j] == 'X' || a[i][j] - '0' == bit(msk, b))
        continue;
      ok = 0;
    }
    goodmsk[msk] = !ok;
  }

  matrix P(1 << 6);
  for (int i = 0; i < (1 << 6); i++)
    for (int j = 0; j < (1 << 6); j++)
      if (good(i, j))
        P.a[j][i] = 1;
  //P.out();
  //vi A(1 << 6, 1);
  matrix A(1 << 6);
  for (int i = 0; i < (1 << 6); i++)
    A.a[0][i] = 1;
  matrix B = A * power(P, n - 2);
  int ans = 0;
  for (int i = 0; i < (1 << 6); i++)
  {
    ans += B.a[0][i];
    ans %= mod;
  } 
  printf("%d\n", ans);
  return 0;            
}

