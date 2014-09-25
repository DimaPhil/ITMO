#define TASKNAME "shortpath"

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

const int maxn = 3e5 + 10;

struct edge {
    int v, w;
    edge() {}                                          
    edge(int v, int w) : v(v), w(w) {}
};
                  
vi topsort;
bool was[maxn];
vector <edge> graph[maxn];
int dp[maxn];

void dfs(int v) {
    was[v] = 1;
    for (int i = 0; i < sz(graph[v]); i++) {
        int u = graph[v][i].v;
        if (!was[u])
            dfs(u);
    }
    topsort.push_back(v);
}            

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  --s, --t;  
  for (int i = 0; i < m; i++) {
     int v, u, w;
     scanf("%d%d%d", &v, &u, &w);
     --v, --u;
     graph[v].push_back(edge(u, w));
  }
  dfs(s);
  reverse(all(topsort));

  for (int i = 0; i < n; i++)
      dp[i] = INF;
  vi pos(n, -1);
  for (int i = 0; i < sz(topsort); i++)
      pos[topsort[i]] = i;
  dp[pos[s]] = 0; 
  for (int i = pos[s]; i < sz(topsort); i++) {
      if (dp[i] == INF)
          continue;
      int v = topsort[i];
      for (int j = 0; j < sz(graph[v]); j++)
          dp[pos[graph[v][j].v]] = min(dp[pos[graph[v][j].v]], dp[i] + graph[v][j].w);
  }
  if (pos[t] == -1 || dp[pos[t]] == INF) {
      printf("Unreachable\n");
      return 0;
  }
  printf("%d\n", dp[pos[t]]);
  return 0;         
}
                                                                       