#define TASKNAME "assignment"

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

struct Graph {
    struct Edge {
        int from, to, flow, capacity, cost;
        size_t backEdge;

        Edge() {
            from = to = 0;
            flow = capacity = cost = 0;
            backEdge = 0;
        }

        Edge(int from, int to, int flow, int capacity, int cost, size_t backEdge) {
            this->from = from;
            this->to = to;
            this->flow = flow;
            this->capacity = capacity;
            this->cost = cost;
            this->backEdge = backEdge;
        }
    };

    int n, m;
    vector < vector <Edge> > graph;
    int start, finish;
    vector <int> distance, phi, pushedFlow;
    vector < pair <int, int> > previous;

    void addEdge(int v, int u, int capacity, int cost) {
        Edge e1 = Edge(v, u, 0, capacity, cost, graph[u].size());
        Edge e2 = Edge(u, v, 0, 0, -cost, graph[v].size());
        graph[v].push_back(e1);
        graph[u].push_back(e2);
    }

    void read() {
        scanf("%d", &n);
        m = 0;
        start = 0, finish = 2 * n + 1;
        graph.resize(2 * n + 2);

        for (int i = 0; i < n; i++)
            addEdge(start, i + 1, 1, 0);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            addEdge(i + 1, n + j + 1, INF, x);
        }
        for (int i = 0; i < n; i++)
            addEdge(n + i + 1, finish, 1, 0);
        n = 2 * n + 2;
    }

    int dijkstra() {
        distance.assign(n, INF);
        distance[start] = 0;
        previous.resize(n);
        for (int i = 0; i < n; i++)
            previous[i].first = previous[i].second = -1;
        pushedFlow.assign(n, 0);
        pushedFlow[start] = INF;

        set < pair <int, int> > q;
        for (int i = 0; i < n; i++)
            q.insert(make_pair(distance[i], i));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (size_t i = 0; i < graph[v].size(); i++) {
                Edge &e = graph[v][i];
                if (e.flow < e.capacity && distance[e.to] > distance[v] + e.cost + phi[v] - phi[e.to]) {
                    q.erase(make_pair(distance[e.to], e.to));
                    distance[e.to] = distance[v] + e.cost + phi[v] - phi[e.to];
                    q.insert(make_pair(distance[e.to], e.to));
                    previous[e.to] = make_pair(v, i);
                    pushedFlow[e.to] = min(pushedFlow[v], e.capacity - e.flow);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            phi[i] += distance[i];
            if (phi[i] > INF)
                phi[i] = INF;
        }
        return pushedFlow[finish];
    }

    pair <long long, vector < pair <int, int> > > findMinCostMaxFlow() {
        phi.assign(n, INF);
        phi[start] = 0;
        for (int it = 0; it <= 2 * n; it++) {
            for (int i = 0; i < n; i++)
                for (size_t j = 0; j < graph[i].size(); j++)
                    if (graph[i][j].flow < graph[i][j].capacity) {
                        phi[graph[i][j].to] = min(phi[graph[i][j].to], phi[i] + graph[i][j].cost);
                    }
        }
        
        long long cost = 0;

        while (true) {
            int flow = dijkstra();
            if (distance[finish] == INF)
                break;
            vector <Edge> path;
            int v = finish;

            while (v != start) {
                Edge &e = graph[previous[v].first][previous[v].second];
                graph[e.from][previous[v].second].flow += flow;
                cost += e.cost * 1LL * flow;
                graph[e.to][e.backEdge].flow -= flow;
                v = e.from;
            }
        }
        vector < pair <int, int> > ans;
        int _n = n / 2 - 1;
        for (int i = 1; i <= _n; i++)
            for (size_t it = 0; it < graph[i].size(); it++)
                if (_n + 1 <= graph[i][it].to && graph[i][it].to <= 2 * _n && graph[i][it].flow > 0)
                    ans.push_back(make_pair(i, graph[i][it].to - _n));
        return make_pair(cost, ans);
    }
};

int main()
{
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    Graph g;
    g.read();
    pair <long long, vector < pair <int, int> > > answer = g.findMinCostMaxFlow();
    cout << answer.first << '\n';
    for (size_t i = 0; i < answer.second.size(); i++)
        cout << answer.second[i].first << ' ' << answer.second[i].second << '\n';
    return 0;
}
