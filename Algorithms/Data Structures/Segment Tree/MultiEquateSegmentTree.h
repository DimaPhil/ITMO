#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/* Start copying from here */

#define l(v) (v << 1)
#define r(v) ((v << 1) + 1)

const int fictIndex = -1;

/*
Use:
  MultiEquateSegmentTree tree<some type, 
                   fictive value for this type,
                   associative binary function, which takes two arguments which are const&
                  >

  For more information how to use it see "Testing/MultiEquateSegmentTreeTester.cpp"
*/

template <typename T, T fictValue, T (*operation)(T const&, T const&)>
struct MultiEquateSegmentTree {                              
    inline void push(int v) {
        if (delta[v] == fictValue)
            return;
        tree[v] = delta[v];
        if (v < size) {
            delta[l(v)] = delta[v];
            delta[r(v)] = delta[v];
        }
        delta[v] = fictValue;
    }

    inline void updateVertex(int v) {
        int lv = l(v), rv = r(v);
        tree[v] = (*operation)(tree[lv], tree[rv]);
        if (tree[v] == tree[lv])
            index[v] = index[lv];
        else
            index[v] = index[rv];
    }

    MultiEquateSegmentTree() {
        tree.clear();
        delta.clear();
        index.clear();
        size = 0;
    }

    MultiEquateSegmentTree(int _size) {
        size = 1;
        while (size < _size)
            size <<= 1;
        tree.resize(size << 1);
        delta.resize(size << 1);
        index.resize(size << 1);
        for (int i = 1; i < (size << 1); ++i) {
            tree[i] = fictValue;
            delta[i] = fictValue;
            index[i] = fictIndex;
        }
    }

    MultiEquateSegmentTree(vector <T> const& as) {
        int _size = as.size();
        size = 1;
        while (size < _size)
            size <<= 1;
        tree.resize(size << 1);
        delta.resize(size << 1);
        index.resize(size << 1);

        for (int i = 0; i < _size; ++i) {
            tree[i + size] = as[i];
            delta[i + size] = fictValue;
            index[i + size] = i;
        }
        for (int i = _size; i < size; ++i) {
            tree[i + size] = fictValue;
            delta[i + size] = fictValue;
            index[i + size] = fictIndex;
        }
        for (int i = size - 1; i > 0; --i) {
            delta[i] = fictValue;
            updateVertex(i);
        }
    }

    void set(int v, int a, int b, int l, int r, T x) {
        push(v);
        if (a > r || l > b)
            return;
        if (l <= a && b <= r) {
            tree[v] = x;
            push(v);
            return;
        }
        int m = (a + b) >> 1;
        set(l(v), a, m, l, r, x);
        set(r(v), m + 1, b, l, r, x);
        updateVertex(v);
    }

    void set(int l, int r, T x) {
        set(1, size, (size << 1) - 1, l + size, r + size, x);
    }

    T get(int v, int a, int b, int l, int r) {
        push(v);
        if (a > r || l > b)
            return fictValue;
        if (l <= a && b <= r)
            return tree[v];
        int m = (a + b) >> 1;
        return (*operation)(get(l(v), a, m, l, r), get(r(v), m + 1, b, l, r));
    }

    T get(int l, int r) {
        return get(1, size, (size << 1) - 1, l + size, r + size);
    }

    pair <T, int> getIndex(int v, int a, int b, int l, int r) {
        push(v);
        if (a > r || l > b)
            return make_pair(fictValue, fictIndex);
        if (l <= a && b <= r)
            return make_pair(tree[v], index[v]);
        int m = (a + b) >> 1;
        pair <T, int> leftAns = get(l(v), a, m, l, r);
        pair <T, int> rightAns = get(r(v), m + 1, b, l, r);
        T result = (*operation)(leftAns.first, rightAns.first);
        if (result == leftAns)
            return make_pair(result, leftAns.second);
        else
            return make_pair(result, rightAns.second);
    }

    pair <T, int> getIndex(int l, int r) {
        return getIndex(1, size, (size << 1) - 1, l + size, r + size);
    }

private:
    vector <T> tree, delta;
    vector <int> index;
    int size;
};