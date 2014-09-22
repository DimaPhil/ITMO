#include <bits/stdc++.h>

void merge(int *elements, int l, int m, int r, int &inversionsCount) {
    int p1 = l, p2 = m + 1;
    std::vector <int> tmp(r - l + 1);
    int p = 0;
    while (p1 <= m && p2 <= r) {
        if (elements[p1] <= elements[p2])
            tmp[p++] = elements[p1++];
        else {         
            inversionsCount += m - p1 + 1;
            tmp[p++] = elements[p2++];
        }
    }
    while (p1 <= m)
        tmp[p++] = elements[p1++];
    while (p2 <= r)
        tmp[p++] = elements[p2++];
    for (int i = l; i <= r; i++)
        elements[i] = tmp[i - l];
}

void mergesort(int *elements, int l, int r, int &inversionsCount) {
    if (l == r)
        return;
    int m = (l + r) >> 1;
    mergesort(elements, l, m, inversionsCount);
    mergesort(elements, m + 1, r, inversionsCount);
    merge(elements, l, m, r, inversionsCount);
}

int inversionsCount(int *elements, int n, bool canChange = false) {
    int res = 0;
    if (!canChange) {
        int *tmp = new int[n];
        for (int i = 0; i < n; i++)
            tmp[i] = elements[i];
        mergesort(tmp, 0, n - 1, res);
    } else
        mergesort(elements, 0, n - 1, res);
    return res;
}

int inversionsCount(std::vector <int> elements) {
    int n = elements.size();
    int *tmp = new int[n];
    for (int i = 0; i < n; i++)
        tmp[i] = elements[i];
    return inversionsCount(tmp, n, true);
}