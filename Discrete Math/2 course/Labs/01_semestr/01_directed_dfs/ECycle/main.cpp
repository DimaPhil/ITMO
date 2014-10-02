#define TASKNAME "cycle"

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

const int maxn = 2e5 + 10;

int n, m;
vi graph[maxn];
int vs[maxn], h = 0;
int was[maxn];

void dfs(int v) {
    was[v] = 1;
    vs[h++] = v;
    for (int i = 0; i < sz(graph[v]); i++) {
        int u = graph[v][i];
        if (was[u] == 1) {
            int pos = find(vs, vs + h, u) - vs;
            printf("YES\n");
            for (int j = pos; j < h; j++)
                printf("%d%c", vs[j] + 1, " \n"[j == h - 1]);
            exit(0);
        }
        if (!was[u]) 
            dfs(u);
    }
    was[v] = 2;
}            

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      graph[a].pb(b);
  }  
  for (int i = 0; i < n; i++)
      if (!was[i])
          dfs(i);
  printf("NO\n");
  return 0;
}
                           