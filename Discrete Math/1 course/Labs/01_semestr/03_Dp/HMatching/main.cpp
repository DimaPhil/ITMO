#define TASKNAME "matching"
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

const int maxn = 1e5 + 100;

int n;
vpii gr[maxn];
ll dp[maxn][2];

inline void dfs(int v, int type, int pr)
{
  dp[v][0] = 0;
  for (int i = 0; i < sz(gr[v]); i++)
  {
    int u = gr[v][i].fst;
    if (u == pr)
      continue;
    dfs(u, 1, v);
    dp[v][0] += dp[u][1];
  }

  if (type == 1)
  {
    dp[v][1] = dp[v][0];  
    ll s = 0;
    for (int i = 0; i < sz(gr[v]); i++)
    {
      int u = gr[v][i].fst;
      if (u == pr)
        continue;
      s += dp[u][1];
    }
    for (int i = 0; i < sz(gr[v]); i++)
    {
      int u = gr[v][i].fst;
      if (u == pr)
        continue;
      dp[v][1] = max(dp[v][1], s - dp[u][1] + dp[u][0] + gr[v][i].snd);
    }
  }                   
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    --a, --b;
    gr[a].pb(mp(b, w));
    gr[b].pb(mp(a, w));
  }
  dfs(0, 1, -1);
  printf("%I64d\n", dp[0][1]);
  return 0;
}

                                                     