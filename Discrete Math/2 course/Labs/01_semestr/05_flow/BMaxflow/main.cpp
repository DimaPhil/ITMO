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

    void print() {
        fprintf(stderr, "%d %d %d\n", to + 1, flow, capacity);
    }
};

struct Graph {
    int n, m;
    vector < vector <edge> > graph;
    vi startPos;
    vi d, q;
    long long maxFlowValue;

    Graph() {
        n = m = 0;
        graph.clear();
        startPos.clear();
        d.clear();
        q.clear();
        maxFlowValue = 0;
    }

    Graph(int n, int m) : n(n), m(m) {
        graph.resize(n);
        startPos.resize(n);
        d.resize(n);
        q.resize(n);
    }

    void adde(int v, int u, int capacity) {
        edge e1 = edge(u, 0, capacity, graph[u].size());
        edge e2 = edge(v, 0, 0, graph[v].size());
        graph[v].push_back(e1);
        graph[u].push_back(e2);
    }

    void read() {
        int n, m;
        scanf("%d%d", &n, &m);
        *this = Graph(n, m);
        for (int i = 0; i < m; i++) {
            int v, u, capacity;
            scanf("%d%d%d", &v, &u, &capacity);
            --v, --u;
            adde(v, u, capacity);
        }
    }

    bool bfs(int start, int finish, int flow) {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        assert(0 <= start && start < n);
        d[start] = 0;
        int qh = 0, qt = 0;        
        q[qt++] = start;
        while (qh != qt) {
            int v = q[qh++];
            if (qh == n)
                qh = 0;
            for (size_t it = 0; it < graph[v].size(); it++) {
                edge &e = graph[v][it];
                if (e.capacity >= e.flow + flow && d[e.to] > d[v] + 1) {
                    d[e.to] = d[v] + 1;
                    q[qt++] = e.to;
                    if (qt == n)
                        qt = 0;
                }
            }
        }
        return d[finish] != INF;
    }

    bool dfs(int v, int finish, int flow) {
        if (v == finish) {
            maxFlowValue += flow;
            return true;
        }
        for (size_t i = startPos[v]; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if (d[e.to] == d[v] + 1 && e.capacity >= e.flow + flow && dfs(e.to, finish, flow)) {
                e.flow += flow;
                graph[e.to][e.backEdge].flow -= flow;
                return true;
            }
            startPos[v]++;
        }
        return false;
    }

    long long maxFlow() {
        int start = 0, finish = n - 1;
        maxFlowValue = 0;
        for (int pushFlow = (1 << 30); pushFlow > 0; pushFlow >>= 1) {
            while (bfs(start, finish, pushFlow)) {
                for (int i = 0; i < n; i++)
                    startPos[i] = 0;
                while (dfs(start, finish, pushFlow));
            }
        }
        return maxFlowValue;
    }
};

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  Graph graph;
  graph.read();
  printf("%I64d\n", graph.maxFlow());                                         
  return 0;
}
