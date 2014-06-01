#define TASKNAME "salesman"
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
#define INF (int(2e9))
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

const int maxn = 20;
const int maxc = 1 << maxn;

int n, m;
vpii gr[maxn];
int dp[maxc][maxn];

inline bool bit(int msk, int i)
{
  return msk & (1 << i);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    gr[a].pb(mp(b, c));
    gr[b].pb(mp(a, c));
  }

  for (int msk = 0; msk < (1 << n); msk++)
    for (int p = 0; p < n; p++)
    {
      if (!bit(msk, p))
        continue;
      dp[msk][p] = INF;
      if (msk == (1 << p))
      {
        dp[msk][p] = 0;
        continue;
      }
      for (int i = 0; i < sz(gr[p]); i++)
      {
        int v = gr[p][i].fst;
        if (!bit(msk, v))
          continue;
        dp[msk][p] = min(dp[msk][p], dp[msk ^ (1 << p)][v] + gr[p][i].snd);
      }       
    }
  int mx = INF;
  for (int i = 0; i < n; i++)
    mx = min(mx, dp[(1 << n) - 1][i]);
  printf("%d\n", mx == INF ? -1 : mx);
  return 0;
}

