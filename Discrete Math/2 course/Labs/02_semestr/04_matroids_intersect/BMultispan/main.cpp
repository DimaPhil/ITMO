#include <bits/stdc++.h>

class DSU {
    std::vector<int> parent, rank;
    int n;

public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int get(int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {    
            std::swap(x, y);
        }
        parent[y] = x;
        rank[x] += rank[x] == rank[y];
    }
};

class Edge {
    int from, to, weight;
public:
    Edge(int from, int to, int weight, int reverseEdge) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }

    int getFrom() {
        return from;
    }

    int getTo() {
        return to;
    }

    int getWeight() {
        return weight;
    }
};

int main() {
    freopen("rainbow.in", "r", stdin);
    freopen("rainbow.out", "w", stdout);
    scanf("%d%d", &n, &m);
    DSU dsu = DSU(n);
    std::vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        --a, --b;
        edges.push_back(Edge(a, b, w));
        dsu.unite(a, b);
    }

    int l = 0, r = m / (n - 1) + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
    }
    return 0;
}