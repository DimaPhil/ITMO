#include <bits/stdc++.h>

class FenwickTree {
    std::vector < std::vector <int> > tree;
    int n, m;

public:
    FenwickTree() { tree.clear(), n = m = 0; }
    FenwickTree(int _n, int _m) {
        n = _n;
        m = _m;
        tree.resize(n);
        for (int i = 0; i < n; i++)
            tree[i].resize(m);
    }

    void update(int x, int y, int add) {
        for (int i = x; i < n; i |= (i + 1))
        for (int j = y; j < m; j |= (j + 1))
            tree[i][j] += add;
    }

    int get(int x, int y) {
        int answer = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            answer += tree[i][j];
        return answer;
    }

    int get(int x1, int y1, int x2, int y2) {
        return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
    }
};

int main() {
}