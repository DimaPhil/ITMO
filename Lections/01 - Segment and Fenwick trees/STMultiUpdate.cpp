#include <bits/stdc++.h>                 

#define l(v) (v << 1) //left son
#define r(v) ((v << 1) + 1) //right son

const int INF = 1e9; //10^9

class SegmentTree {
    std::vector <int> tree;
    std::vector <int> delta;
    int n;

public:
    const int fictValue = 0;
    const int fictDelta = -INF;
    int operation(int a, int b) {
        return a + b;
    }  

    SegmentTree() { tree.clear(), n = 0; }
    SegmentTree(std::vector <int> &as) {
        int _n = as.size();
        n = 1;
        while (n < _n)
            n <<= 1; //<=> n *= 2
        tree.resize(n << 1); //<=> n * 2
        delta.resize(n << 1);
        for (int i = 0; i < n; i++)
            tree[i + n] = i < _n ? as[i] : fictValue; //<=> if (i < _n) then t[i + n] = a[i] else t[i + n] = fictValue
        for (int i = n - 1; i > 0; i--)
            tree[i] = operation(tree[l(i)], tree[r(i)]);
        for (int i = 1; i < (n << 1); i++)
            delta[i] = fictDelta;
    }

    void push(int v, int lengthSegment) {
        if (delta[v] == fictDelta)
            return;
        tree[v] = delta[v] * lengthSegment;
        if (v < n) {
            delta[l(v)] = delta[v];
            delta[r(v)] = delta[v];
        }
        delta[v] = fictDelta;
    }

    void update(int v, int a, int b, int l, int r, int x) { //equate segment [l, r] to x
        push(v, b - a + 1);
        if (a > r || l > b)
            return;
        if (l <= a && b <= r) {
            delta[v] = x;
            push(v, b - a + 1);
            return;
        }
        int m = (a + b) >> 1;
        update(l(v), a, m, l, r, x);
        update(r(v), m + 1, b, l, r, x);
        tree[v] = operation(tree[l(v)], tree[r(v)]);
    }

    void update(int l, int r, int x) { //simple way to update
        update(1, n, (n << 1) - 1, l + n, r + n, x);
    }

    int get(int v, int a, int b, int l, int r) {
        push(v, b - a + 1);
        if (a > r || l > b)
            return fictValue;
        if (l <= a && b <= r)
            return tree[v];
        int m = (a + b) >> 1; //<=> (a + b) / 2
        return operation(get(l(v), a, m, l, r),
                         get(r(v), m + 1, b, l, r)
                         );
    }

    int get(int l, int r) { //simple way to use get
        return get(1, n, (n << 1) - 1, l + n, r + n);
    }
};

void test() {
    std::vector <int> a;
    a.push_back(2);
    a.push_back(5);
    a.push_back(3);
    a.push_back(4);
    a.push_back(6);
    SegmentTree tree(a);
    printf("%d\n", tree.get(2, 4));
    tree.update(2, 3, 1);
    printf("%d\n", tree.get(2, 4));
    tree.update(0, 4, 1);
    printf("%d\n", tree.get(0, 3));
}

int main() {
    test();
    return 0;
}                             