#define TASKNAME "hamiltonian"

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

vi topsort;
bool was[maxn];
vector <int> graph[maxn];
int dp[maxn];

void dfs(int v) {
    was[v] = 1;
    for (int i = 0; i < sz(graph[v]); i++) {
        int u = graph[v][i];
        if (!was[u])
            dfs(u);
    }
    topsort.push_back(v);
}            

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
     int v, u;
     scanf("%d%d", &v, &u);
     --v, --u;
     graph[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
      if (!was[i])
          dfs(i);
  reverse(all(topsort));

  bool ok = sz(topsort) == n;
  for (int i = 0; i < sz(topsort) - 1; i++)
      ok &= find(all(graph[topsort[i]]), topsort[i + 1]) != graph[topsort[i]].end();
  printf("%s\n", ok ? "YES" : "NO");
  return 0;         
}
                                                                       