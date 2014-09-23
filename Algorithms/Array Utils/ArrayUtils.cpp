#include <bits/stdc++.h>

template <typename T>
struct ArrayUtils {
    static std::vector <T> toVector(T *elements, int n) {
        std::vector <T> answer(n);
        for (int i = 0; i < n; i++)
            answer[i] = elements[i];
        return answer;
    }              

    static void merge(T *elements, int l, int m, int r, long long &inversionsCount) {
        int p1 = l, p2 = m + 1;
        std::vector <T> tmp(r - l + 1);
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

    static void mergesort(T *elements, int l, int r, long long &inversionsCount) {
        if (l == r)
            return;
        int m = (l + r) >> 1;
        mergesort(elements, l, m, inversionsCount);
        mergesort(elements, m + 1, r, inversionsCount);
        merge(elements, l, m, r, inversionsCount);
    }

    static long long inversionsCount(T *elements, int n, bool canChange = false) {
        long long res = 0;
        if (!canChange) {
            T *tmp = new T[n];
            for (int i = 0; i < n; i++)
                tmp[i] = elements[i];
            mergesort(tmp, 0, n - 1, res);
        } else
            mergesort(elements, 0, n - 1, res);
        return res;
    }
    
    static long long inversionsCount(std::vector <T> &elements) {
        int n = elements.size();
        T *tmp = new T[n];
        for (int i = 0; i < n; i++)
            tmp[i] = elements[i];
        return inversionsCount(tmp, n, true);
    }
    
    static void sortAndUnique(T *elements, int n) {
        std::sort(elements, elements + n);
        int newSize = std::unique(elements, elements + n) - elements;
        for (int i = newSize; i < n; i++)
            elements[i] = 0;
    }

    static void sortAndUnique(std::vector <T> &elements) {
        std::sort(elements.begin(), elements.end());
        elements.erase(std::unique(elements.begin(), elements.end()), elements.end());
    }
};

int main() {
    int a[] = {2, 3, 4, 1, 5};
    std::vector <long long> b;
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    b.push_back(1);
    b.push_back(5);
    printf("%lld\n", ArrayUtils<int>::inversionsCount(a, 5));
    printf("%lld\n", ArrayUtils<long long>::inversionsCount(b));

    int c[] = {4, 2, 4, 2, 3, 5, 3};
    ArrayUtils<int>::sortAndUnique(c, 7);
    for (int i = 0; i < 7; i++)
        printf("%d ", c[i]);
    printf("\n");

    std::vector <int> d;
    d.push_back(4);
    d.push_back(2);
    d.push_back(4);
    d.push_back(2);
    d.push_back(3);
    d.push_back(5);
    d.push_back(3);
    ArrayUtils<int>::sortAndUnique(d);
    for (int i = 0; i < (int)d.size(); i++)
        printf("%d ", d[i]);
    printf("\n"); 

    return 0;
}