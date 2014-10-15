#define TASKNAME "cranes"
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

#ifdef WIN32
  #define I64d "%I64d"
#else
  #define I64d "%lld"
#endif
 
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

const int maxn = 100;

int n;
int x[maxn], y[maxn], r[maxn];

inline bool bit(int msk, int i)
{
  return msk & (1 << i);
}

inline bool intersec(int i, int j)
{
  return (ll)(x[i] - x[j]) * (x[i] - x[j]) + (ll)(y[i] - y[j]) * (y[i] - y[j]) <= (ll)(r[i] + r[j]) * (r[i] + r[j]);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++)
  {
    scanf("%d", &n);
    ll mx = 0;
    for (int i = 0; i < n; i++)
      scanf("%d%d%d", &x[i], &y[i], &r[i]);
    for (int msk = 0; msk < (1 << n); msk++)
    {
      bool ok = 1;
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
          if (bit(msk, i) && bit(msk, j) && intersec(i, j))
            ok = 0;
      if (ok)
      {
        ll val = 0;
        for (int i = 0; i < n; i++)
          if (bit(msk, i))
            val += (ll)r[i] * r[i];
        if (mx < val)
          mx = val;
      }
    }
    printf(I64d"\n", mx);
  }
  return 0;
}

