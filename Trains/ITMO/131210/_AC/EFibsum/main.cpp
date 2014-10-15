#define TASKNAME "fibsum"
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

const int maxsize = 15;

ll l, r;
int k, mod;
vi F;
vi sum;

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

inline matrix power(matrix a, ll p)
{
  if (!p)
     return E(k + 1);
  if (p & 1ll)
    return power(a, p - 1) * a;
  matrix tmp = power(a, p >> 1ll);
  return tmp * tmp;
}

inline vi multiply(vi &a, matrix m)
{
  vi b(sz(a), 0);
  for (int i = 0; i < sz(a); i++)
    for (int j = 0; j < sz(a); j++)
    {
      b[i] += mmod((ll)a[j] * m.a[j][i]);
      if (b[i] >= mod)
        b[i] -= mod;
    }
  return b;
}

inline int pref(matrix &P, vi &M, ll x)
{
  if (x < k)
    return sum[x];
  return multiply(M, power(P, x - k + 1))[k];
}

inline int get(matrix &P, vi &M, ll l, ll r)
{
  if (!l)
    return pref(P, M, r);
  return mmod(pref(P, M, r) - pref(P, M, l - 1));
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int test_cases;
  scanf("%d", &test_cases);
  while (test_cases --> 0)
  {
    scanf("%d", &k);
    F.resize(k);
    for (int i = 0; i < k; i++)
      scanf("%d", &F[i]);
    scanf("%I64d%I64d%d", &l, &r, &mod);
    //mod = 10000000;
    for (int i = 0; i < k; i++)
      F[i] = mmod(F[i]);
    matrix P(k + 1);
    for (int i = 1; i < k; i++)
      P.a[i][i - 1] = 1;
    for (int i = 0; i < k; i++)
      P.a[i][k - 1] = 1;
    for (int i = 0; i < k + 1; i++)
      P.a[i][k] = 1;
    //P.out();
    vi M(k + 1);
    int s = 0;
    sum.resize(k);
    for (int i = 0; i < k; i++)
    {
      M[i] = F[i];
      s += F[i];
      if (s >= mod)
        s -= mod;
      sum[i] = s;
    }
    M[k] = s;
    //for (int i = 0; i <= k; i++)
    //  printf("%d%c", M[i], " \n"[i == k]);
    //printf("%d\n", pref(P, M, l));
    //printf("%d\n", pref(P, M, r));
    printf("%d\n", get(P, M, l, r));
  }
  return 0;
}


