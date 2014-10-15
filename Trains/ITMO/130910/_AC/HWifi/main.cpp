#define TASKNAME "wifi"
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

const int maxn = 1e5 + 10;

int m, n, t;
int x[maxn];

inline bool check(double M)
{
  int p = 0, cnt = 0;
  double lastc = -1e18;
  while (p < n)
  {
    ++cnt;
    lastc = x[p] + M;
    ++p;
    while (p < n && abs(x[p] - lastc) <= M)
      ++p;
  }
  return cnt <= m;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++)
  {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &x[i]);
    sort(x, x + n);
    double l = 0, r = 1e18;
    for (int it = 0; it < 100; it++)
    {
      double m = (l + r) / 2;
      if (!check(m))
        l = m;
      else
        r = m; 
    }
    printf("%.1lf\n", (l + r) / 2);
  }
  return 0;
}

