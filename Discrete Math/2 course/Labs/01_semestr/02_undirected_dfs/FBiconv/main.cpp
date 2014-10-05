#define TASKNAME "biconv"

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
vector <vpii> gr;     
vb was;
vi tin, f;
int timer;
vi color;

void dfs(int v, int p = -1) {
    was[v] = true;
    tin[v] = f[v] = timer++;
    for (auto &it : gr[v]) {
        int u = it.fst;
        if (u == p)
            continue;
        if (was[u]) {
            f[v] = min(f[v], tin[u]);
        } else {
            dfs(u, v);
            f[v] = min(f[v], f[u]);
        }                
    }
}

int maxc;

void findComponents(int v, int p, int nowc) {
    was[v] = 1;
    for (auto &it : gr[v]) {
        int u = it.fst;
        int e = it.snd;
        if (u == p)
            continue;
        if (was[u]) {
            if (tin[v] >= tin[u])
                color[e] = nowc;
        } else {
            if (f[u] >= tin[v]) {
                color[e] = maxc++;
                findComponents(u, v, maxc - 1);
            } else {
                color[e] = nowc;
                findComponents(u, v, nowc);
            }
        }
    }
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
      gr[a].pb(mp(b, i));
      gr[b].pb(mp(a, i));
  }           
  was.resize(n);
  tin.resize(n);
  f.resize(n);
  for (int i = 0; i < n; i++)
      if (!was[i])
          dfs(i);
  color.resize(m);
  for (int i = 0; i < n; i++)
      was[i] = 0;
  maxc = 0;
  for (int i = 0; i < n; i++)
      if (!was[i])
          findComponents(i, -1, ++maxc);
  printf("%d\n", maxc - 1);
  for (int i = 0; i < m; i++)
      printf("%d%c", color[i], " \n"[i == m - 1]);
  return 0;
}
                   