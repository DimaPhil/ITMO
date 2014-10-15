#define TASKNAME "dominos"
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

int n, m;
vi gr[maxn];
int deg[maxn];
bool was[maxn];

inline bool Less(int a, int b)
{
  return deg[a] < deg[b];
}

inline void dfs(int v)
{
  was[v] = 1;
  for (int i = 0; i < sz(gr[v]); i++)
  {
    int u = gr[v][i];
    if (!was[u])
      dfs(u);
  }
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++)
  {
    scanf("%d%d", &n, &m);
    vi p(n);
    for (int i = 0; i < n; i++)
      gr[i].clear(), was[i] = 0, deg[i] = 0, p[i] = i;
    for (int i = 0; i < m; i++)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      gr[a].pb(b);
      ++deg[b];
    }
    sort(all(p), Less);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (!was[p[i]])
        ++ans, dfs(p[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

