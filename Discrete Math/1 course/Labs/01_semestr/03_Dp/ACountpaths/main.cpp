#define TASKNAME "countpaths"
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

const int mod = 1e9 + 7;

int n, m;
vvi gr, gr_rev;
vi vs;
vb was;

void dfs(int v)
{
  was[v] = 1;
  for (int i = 0; i < sz(gr[v]); i++)
    if (!was[gr[v][i]])
      dfs(gr[v][i]);
  vs.pb(v);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  gr.resize(n);
  gr_rev.resize(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    gr[a].pb(b);
    gr_rev[b].pb(a);
  }
  vs.clear();
  was.resize(n);
  dfs(0);
  reverse(all(vs));
  vi dp(n, 0);
  dp[0] = 1;
  for (int i = 0; i < sz(vs); i++)
  {
    int v = vs[i];
    for (int j = 0; j < sz(gr_rev[v]); j++)
      dp[v] += dp[gr_rev[v][j]], dp[v] %= mod;
  }
  printf("%d\n", dp[n - 1]);
  return 0;
}

