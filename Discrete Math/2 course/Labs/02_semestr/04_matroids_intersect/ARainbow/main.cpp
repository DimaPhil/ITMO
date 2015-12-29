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
        return x == parent[x] ? x : parent[x] = get(parent[x]);
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
    int from, to, weight, id;
public:
    bool taken, taken2;
    Edge *prev;
    bool used;

    Edge() { from = to = weight = id = 0, taken = false; }
    Edge(int from, int to, int weight, int id) {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->id = id;
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

    int getId() {
        return id;
    }
};

const int maxn = 5e5 + 100;

std::vector <Edge> graph[maxn];

bool eq(Edge a, Edge b) {
    return a.getId() == b.getId() && a.getFrom() == b.getFrom() && a.getTo() == b.getTo() && a.getWeight() == b.getWeight();
}

Edge cur;

std::vector<Edge> findCycles(Edge start) {
    std::queue<
}

int main() {
    freopen("rainbow.in", "r", stdin);
    freopen("rainbow.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<Edge> edges;
    std::set<int> weights;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        --a, --b;
        edges.push_back(Edge(a, b, w, i + 1));
        weights.insert(w);
    }
    for (Edge &edge : edges) {
        graph[edge.getFrom()].push_back(edge);
        graph[edge.getTo()].push_back(Edge(edge.getTo(), edge.getFrom(), edge.getWeight(), edge.getId()));
    }
    DSU dsu = DSU(n);
    int edgesCount = 0;
    for (Edge &edge : edges) {
        if (dsu.get(edge.getFrom()) == dsu.get(edge.getTo())) {
            continue;
        }
        edge.taken = true;
        edge.taken2 = true;
        dsu.unite(edge.getFrom(), edge.getTo());
        ++edgesCount;
    }

    std::queue<Edge> q;
    while (true) {
        for (Edge &edge : edges) {
            if (!edge.taken) {
                edge.prev = 0;
                edge.used = true;
                q.push(edge);
            } else {
                edge.used = false;
            }
        }

        Edge finish = Edge(-1, -1, -1, -1);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur.taken) {
                for (Edge &next : edges) {
                    if (!next.used && !eq(next, cur) && next.taken == cur.taken) {
                        next.used = true;
                        next.prev = &cur;
                        q.push(next);
                    }
                }
            } else {
                std::vector<Edge> cycles = findCycles(cur);
                if (cycles.size() == 0) {
                    finish = cur;
                    break;
                }

                for (Edge &next : cycles) {
                    if (!next.used) {
                        next.used = true;
                        next.prev = &cur;
                        q.push(next);
                    }
                }
            }
        }
        if (finish.getFrom() == -1) {
            break;
        }
        while (finish.getFrom() != -1) {
            finish.taken2 = !finish.taken2;
            finish.taken = true;
            finish = *finish.prev;
        }
    }
    return 0;
}