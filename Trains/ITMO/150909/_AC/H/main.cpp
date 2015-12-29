#include <bits/stdc++.h>

class DSU {
private:
    std::vector<int> p, rank;    
    int n;
public:
    DSU(int n) {
        this->n = n;
        p.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            p[i] = i;
        }
    }

    int get(int x) {
        return x == p[x] ? x : (p[x] = get(p[x]));
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            std::swap(x, y);
        }
        p[y] = x;
        rank[x] += rank[x] == rank[y];
        return true;
    }
};

const int maxn = 3000;

std::vector<int> g[maxn];
int d[maxn][maxn];

void dfs(int start, int v, int pr = -1) {
    for (auto u : g[v]) {
        if (u == pr) {
            continue;
        }
        d[start][u] = d[start][v] + 1;
        dfs(start, u, v);
    }
}

struct edge {
    int v, u, w;
    edge() {}
    edge(int v, int u, int w) : v(v), u(u), w(w) {}

    bool operator < (const edge &other) const {
        return w > other.w;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        d[i][j] = -(int)1e9;
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
        dfs(i, i);
    }
    std::vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
            edges.push_back(edge(i, j, d[i][j]));
        }
    }
    std::sort(edges.begin(), edges.end());
    int ans = 0;
    DSU dsu(n);
    for (auto edge : edges) {
        if (dsu.unite(edge.v, edge.u)) {
            ans += edge.w;
        }
    }
    printf("%d\n", ans);
    return 0;
}
