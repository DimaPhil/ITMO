#define TASKNAME "cubes"
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

const int maxn = 210;

int n, s;
int d[maxn][maxn];
int a[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  s = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), s += a[i];
  int need = s / n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &d[i][j]);
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int cost = 0;
  vb was(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (a[i] < need)
      continue;
    was[i] = 1;
    vpii v;
    int have = a[i] - need;
    for (int j = 0; j < n; j++)
      if (a[j] < need && !was[j])
        v.pb(mp(d[i][j], j));
    sort(all(v));
    int idx = 0;
    while (have && idx < sz(v))
    {
      if (a[v[idx].snd] == need)
        ++idx;
      cost += v[idx].fst;
      ++a[v[idx].snd];
      --have;
    } 
  }
  printf("%d\n", cost);
  return 0;                                   
}

