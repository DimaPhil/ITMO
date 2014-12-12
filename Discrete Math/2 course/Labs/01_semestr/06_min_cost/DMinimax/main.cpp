#define TASKNAME "minimax"

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
    vector < vector < pair <int, int> > > graph;
    vector <int> getPair;
    vector <bool> used;

    void read() {
        scanf("%d", &n);
        graph.resize(n);
        getPair.resize(n);
        used.resize(n);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            graph[i].push_back(make_pair(j, x));
        }
    }

    bool dfs(int v, int minEdge) {
        if (used[v])
            return false;
        used[v] = true;
        for (size_t i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i].first;
            if (graph[v][i].second < minEdge)
                continue;
            if (getPair[to] == -1 || dfs(getPair[to], minEdge)) {
                getPair[to] = v;
                return true;
            }
        }
        return false;
    }

    int findMax(int minEdge) {
        for (int i = 0; i < n; i++)
            getPair[i] = -1;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                used[j] = false;
            dfs(i, minEdge);
            int newAns = 0;
            for (int j = 0; j < n; j++)
                if (getPair[j] != -1)
                    ++newAns;
            mx = max(mx, newAns);
        }
        return mx;
    }

    int findMinimalEdge() {
        int l = -INF, r = INF;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (findMax(m) == n)
                l = m;
            else
                r = m;
        }
        return l;
    }
};

int main()
{
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    Graph g;
    g.read();
    cout << g.findMinimalEdge();
    return 0;
}
