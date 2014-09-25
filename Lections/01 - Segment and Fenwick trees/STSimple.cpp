#include <bits/stdc++.h>                 

#define l(v) (v << 1) //left son
#define r(v) ((v << 1) + 1) //right son

class SegmentTree {
    std::vector <int> tree;
    int n;

public:
    const int fictValue = 0;
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
        for (int i = 0; i < n; i++)
            tree[i + n] = i < _n ? as[i] : fictValue; //<=> if (i < _n) then t[i + n] = a[i] else t[i + n] = fictValue
        for (int i = n - 1; i > 0; i--)
            tree[i] = operation(tree[l(i)], tree[r(i)]);
    }

    void update(int v, int x) { //equate value in vertex v to x
        v += n;
        tree[v] = x;
        v >>= 1; //<=> v /= 2
        while (v) { //<=> while (v > 0)
            tree[v] = operation(tree[l(v)], tree[r(v)]);
            v >>= 1; //<=> v /= 2
        }
    }

    int get(int v, int a, int b, int l, int r) {
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
    tree.update(2, 1);
    printf("%d\n", tree.get(2, 4));
}

int main() {
    test();
    return 0;
}                             