#include <bits/stdc++.h>

class FenwickTree {
    std::vector <int> tree;
    int n;

public:
    FenwickTree() { tree.clear(), n = 0; }
    FenwickTree(int _n) {
        n = _n;
        tree.resize(n);
    }

    void update(int v, int x) {
        for (int i = v; i < n; i |= (i + 1))
            tree[i] += x;
    }

    int get(int v) {
        int answer = 0;
        for (int i = v; i >= 0; i = (i & (i + 1)) - 1)
            answer += tree[i];
        return answer;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

class FenwickTree2 {
    std::vector <int> tree;
    int n;

public:
    FenwickTree2() { tree.clear(), n = 0; }
    FenwickTree2(int _n) {
        n = _n + 1;
        tree.resize(n);
    }

    void update(int v, int x) {
        for (int i = v + 1; i < n; i += i & (-i))
            tree[i] += x;
    }

    int get(int v) {
        int answer = 0;
        for (int i = v + 1; i > 0; i -= i & (-i))
            answer += tree[i];
        return answer;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void test() {
    FenwickTree a(5);
    a.update(4, 1);
    a.update(2, 5);
    a.update(1, -3);
    printf("%d\n%d\n\n", a.get(3), a.get(4));
    FenwickTree2 b(5);
    b.update(4, 1);
    b.update(2, 5);
    b.update(1, -3);
    printf("%d\n%d\n\n", b.get(3), b.get(4));
}

int main() {
    test();
}