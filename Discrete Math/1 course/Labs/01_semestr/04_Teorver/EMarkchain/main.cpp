#define TASKNAME "markchain"
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

const int maxsize = 110;

struct matrix
{
  int n;
  double a[maxsize][maxsize];

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

  inline matrix operator * (const matrix &b)
  {
    matrix c(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          c.a[i][j] += a[i][k] * b.a[k][j];
    return c;
  }

  inline void out()
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        printf("%.5lf%c", a[i][j], " \n"[j == n - 1]);
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
  if (p == 1)
     return a;
  if (p & 1ll)
    return power(a, p - 1) * a;
  matrix tmp = power(a, p >> 1ll);
  return tmp * tmp;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  matrix m(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%lf", &m.a[i][j]);
  matrix ans = power(m, 100);
  //ans.out();
  for (int i = 0; i < n; i++)
    printf("%.10lf\n", ans.a[0][i]);
  return 0;
}

