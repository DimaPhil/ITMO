#define TASKNAME "points"

#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
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

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

template <typename T>
T sqr(T x) {
    return x * x;
}

template <typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

int n, m;
vvi gr;
vb was;
vi tin, f;
set <int> cutPoints;
int timer;

void dfs(int v, int p = -1) {
    was[v] = true;
    tin[v] = f[v] = timer++;
    int children = 0;
    for (auto &it : gr[v]) {
        int u = it;
        if (u == p)
            continue;
        if (was[u]) {
            f[v] = min(f[v], tin[u]);
        } else {
            dfs(u, v);
            f[v] = min(f[v], f[u]);
            if (f[u] >= tin[v] && p != -1)
                cutPoints.insert(v);
            ++children;
        }                
    }
    if (p == -1 && children > 1)
        cutPoints.insert(v);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  gr.resize(n);
  for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      gr[a].pb(b);
      gr[b].pb(a);
  }
  was.resize(n);
  tin.resize(n);
  f.resize(n);
  for (int i = 0; i < n; i++)
      if (!was[i])
          dfs(i);
  printf("%d\n", sz(cutPoints));
  for (auto &point : cutPoints)
      printf("%d\n", point + 1);
  return 0;
}
