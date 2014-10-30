#define TASKNAME "chinese"

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
const int INF = 2e9;
const ll INFLONG = (ll)1e18;

struct edge {
    int from, to, w;
    edge() { from = to = w = 0; }
    edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

bool operator < (const edge &e1, const edge &e2) 
{ 
    return e1.w < e2.w || 
          (e1.w == e2.w && e1.from < e2.from) || 
          (e1.w == e2.w && e1.from == e2.from && e1.to < e2.to);
}

void tryGo(int v, vvi &graph, vb &was) {
    was[v] = true;
    for (auto &u : graph[v])
        if (!was[u])
            tryGo(u, graph, was);
}

void getList(vector <edge> &edges, int n, vvi &graph) {
    graph.resize(n);
    for (auto &e : edges) {
        graph[e.from].pb(e.to);
    } 
}

bool canGo(int v, int n, vector <edge> &edges) {
    vvi graph;
    getList(edges, n, graph);
    vb was(n, false);
    tryGo(v, graph, was);
    for (int i = 0; i < n; i++)
        if (!was[i])
            return false;
    return true;
}

void getReversedGraph(vvi &graph, vvi &graphRev) {
    int n = sz(graph);
    graphRev.resize(n);
    for (int i = 0; i < n; i++)
        for (auto &u : graph[i])
            graphRev[u].pb(i);
}

void dfs(int v, vvi &graph, vi &order, vb &was) {
    was[v] = true;
    for (auto &u : graph[v])
        if (!was[u])
            dfs(u, graph, order, was);
    order.pb(v);
}

void dfsRev(int v, vvi &graph, vb &was, vi &getComponent, int component) {
    was[v] = true;
    getComponent[v] = component;
    for (auto &u : graph[v])
        if (!was[u])
            dfsRev(u, graph, was, getComponent, component);
}        

int condense(vector <edge> &edges, vi &getComponent) {
    int n = sz(getComponent);
    vvi graph, graphRev;
    getList(edges, n, graph);
    getReversedGraph(graph, graphRev);

    vb was(n, false);
    vi order;
    for (int i = 0; i < n; i++)
        if (!was[i])
            dfs(i, graph, order, was);
    reverse(all(order));
    assert(sz(order) == n);
    for (int i = 0; i < n; i++)
        was[i] = false;
    int component = 0;
    for (int i = 0; i < n; i++)
        if (!was[order[i]])
            dfsRev(order[i], graphRev, was, getComponent, component), component++;
    return component;
}

ll go(int v, int n, vector <edge> &edges) {
    ll ans = 0;
    vi minEdge(n, INF);
    for (auto &e : edges)
        minEdge[e.to] = min(minEdge[e.to], e.w);

    for (edge &e : edges)
        e.w -= minEdge[e.to];
    vector <edge> es;
    for (auto &e : edges) {
        if (e.w == 0)
            es.pb(edge(e.from, e.to, 0));
    }
    for (int i = 0; i < n; i++)
        if (i != v)
            ans += minEdge[i];
    if (canGo(v, n, es))
        return ans;

    vi getComponent(n);
    int componentsCount = condense(es, getComponent);
    vector <edge> newEdges;
    for (auto &e : edges) {
        if (getComponent[e.from] != getComponent[e.to]) {
            newEdges.pb(edge(getComponent[e.from], getComponent[e.to], e.w));
        }
    }
                            
    ans += go(getComponent[v], componentsCount, newEdges);
    return ans;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  vector <edge> edges;
  for (int i = 0; i < m; i++) {
      int v, u, w;
      scanf("%d%d%d", &v, &u, &w);
      --v, --u;
      edges.pb(edge(v, u, w));
  }
  if (!canGo(0, n, edges)) {
      printf("NO\n");
  } else {
      printf("YES\n");
      printf("%I64d\n", go(0, n, edges));
  }
  return 0;
}
