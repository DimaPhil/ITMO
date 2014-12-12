#define TASKNAME "maxflow"

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

struct edge {
    int to, flow, capacity;
    size_t backEdge;

    edge() {
        to = flow = capacity = backEdge = 0;
    }

    edge(int to, int flow, int capacity, size_t backEdge) : to(to), flow(flow), capacity(capacity), backEdge(backEdge) {
    }
};

const int maxn = 1e5 + 10;
long long ans = 0;

vector <edge> graph[maxn];
bool used[maxn];

void adde(int v, int u, int c) {
    edge e1 = edge(u, 0, c, graph[u].size());
    edge e2 = edge(v, 0, 0, graph[v].size());
    graph[v].push_back(e1);
    graph[u].push_back(e2);
}

int dfs(int v, int finish, int minFlow) {
    if (v == finish) {
        ans += minFlow;
        return minFlow;
    }
    used[v] = true;
    for (size_t i = 0; i < graph[v].size(); i++) {
        edge &e = graph[v][i];
        if (!used[e.to] && e.capacity > e.flow) {
            int flow = dfs(e.to, finish, min(minFlow, e.capacity - e.flow));
            if (flow == 0)
                continue;
            e.flow += flow;
            graph[e.to][e.backEdge].flow -= flow;
            return flow;
        }
    }
    return 0;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
      int v, u, c;
      scanf("%d%d%d", &v, &u, &c);
      --v, --u;
      adde(v, u, c);
  }
  ans = 0;
  for (int i = 0; i < n; i++)
      used[i] = false;
  while (dfs(0, n - 1, INF)) {
      for (int i = 0; i < n; i++)
          used[i] = false;
  }
  cout << ans << '\n';
  return 0;
}
