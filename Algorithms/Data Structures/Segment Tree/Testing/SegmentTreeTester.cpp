#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cassert>
#include "../SegmentTree.h"
//#include "../MultiSegmentTree.h"

using namespace std;

long long rdtsc() {
    long long tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

const int maxIterations = 100;
const int maxn = 100000;
const int maxQueries = 100000;
const int maxLen = 100;
const int maxValue = 1e9;

int rand(int x) {
    return ((rand() & 1) ? 1 : -1) * rand() % x;
}

inline int min(int const& a, int const& b) {
    return a < b ? a : b;
}

inline int sum(int const& a, int const& b) {
    return a + b;
}

inline long long min(long long const& a, long long const& b) {
    return a < b ? a : b;
}

inline long long sum(long long const& a, long long const& b) {
    return a + b;
}

/*template <typename T> void testCorrectness(vector <T> &as, SegmentTree<T, T, (T*)(T const&, T const&)> &tree) {
    
} */

int main() {
    srand(rdtsc());
    double startTime = double(clock()) / CLOCKS_PER_SEC;
    printf("Testing SegmentTree<int>, operation = +: ");
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        int n = maxn;
        vector <int> as(n);

        for (int i = 0; i < n; ++i)
            as[i] = rand(maxValue);
        SegmentTree<int, 0, sum> tree(as);
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              int expectedValue = 0;
              for (int it = i; it <= j; ++it)
                  expectedValue += as[it];
              int actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            int expectedValue = 0;
            for (int it = l; it <= r; ++it)
                expectedValue += as[it];
            int actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            as[i] = rand(maxValue);
            tree.set(i, as[i]);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              int expectedValue = 0;
              for (int it = i; it <= j; ++it)
                  expectedValue += as[it];
              int actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            int expectedValue = 0;
            for (int it = l; it <= r; ++it)
                expectedValue += as[it];
            int actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            int last = as[i];
            as[i] = rand(maxValue);
            tree.add(i, as[i] - last);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              int expectedValue = 0;
              for (int it = i; it <= j; ++it)
                  expectedValue += as[it];
              int actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            int expectedValue = 0;
            for (int it = l; it <= r; ++it)
                expectedValue += as[it];
            int actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }
    }
    double finishTime = double(clock()) / CLOCKS_PER_SEC;
    printf("OK, Time elapsed: %.2lf\n", finishTime - startTime);

    startTime = finishTime;
    printf("Testing SegmentTree<long long>, operation = +: ");
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        int n = maxn;
        vector <long long> as(n);

        for (int i = 0; i < n; ++i)
            as[i] = rand(maxValue);
        SegmentTree<long long, 0, sum> tree(as);
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              long long expectedValue = 0;
              for (int it = i; it <= j; ++it)
                  expectedValue += as[it];
              long long actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            long long expectedValue = 0;
            for (int it = l; it <= r; ++it)
                expectedValue += as[it];
            long long actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            as[i] = rand(maxValue);
            tree.set(i, as[i]);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              long long expectedValue = 0;
              for (int it = i; it <= j; ++it)
                  expectedValue += as[it];
              long long actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            long long expectedValue = 0;
            for (int it = l; it <= r; ++it)
                expectedValue += as[it];
            long long actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            int last = as[i];
            as[i] = rand(maxValue);
            tree.add(i, as[i] - last);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              long long expectedValue = 0;
              for (int it = i; it <= j; ++it)
                  expectedValue += as[it];
              long long actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            long long expectedValue = 0;
            for (int it = l; it <= r; ++it)
                expectedValue += as[it];
            long long actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            as[i] = maxValue;
            tree.set(i, as[i]);
        }
        long long expectedValue = 1LL * maxValue * n;
        long long actualValue = tree.get(0, n - 1);
        assert(expectedValue == actualValue);
    }
    finishTime = double(clock()) / CLOCKS_PER_SEC;
    printf("OK, Time elapsed: %.2lf\n", finishTime - startTime);

    startTime = finishTime;
    printf("Testing SegmentTree<int>, operation = min: ");
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        int n = maxn;
        vector <int> as(n);

        for (int i = 0; i < n; ++i)
            as[i] = rand(maxValue);
        SegmentTree<int, (int)2e9, min> tree(as);
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              int expectedValue = (int)2e9;
              for (int it = i; it <= j; ++it)
                  expectedValue = min(expectedValue, as[it]);
              int actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            int expectedValue = (int)2e9;
            for (int it = l; it <= r; ++it)
                expectedValue = min(expectedValue, as[it]);
            int actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            as[i] = rand(maxValue);
            tree.set(i, as[i]);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              int expectedValue = (int)2e9;
              for (int it = i; it <= j; ++it)
                  expectedValue = min(expectedValue, as[it]);
              int actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            int expectedValue = (int)2e9;
            for (int it = l; it <= r; ++it)
                expectedValue = min(expectedValue, as[it]);
            int actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            int last = as[i];
            as[i] = rand(maxValue);
            tree.add(i, as[i] - last);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              int expectedValue = (int)2e9;
              for (int it = i; it <= j; ++it)
                  expectedValue = min(expectedValue, as[it]);
              int actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            int expectedValue = (int)2e9;
            for (int it = l; it <= r; ++it)
                expectedValue = min(expectedValue, as[it]);
            int actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }
    }
    finishTime = double(clock()) / CLOCKS_PER_SEC;
    printf("OK, Time elapsed: %.2lf\n", finishTime - startTime);

    startTime = finishTime;
    printf("Testing SegmentTree<long long>, operation = min: ");
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        int n = maxn;
        vector <long long> as(n);

        for (int i = 0; i < n; ++i)
            as[i] = rand(maxValue);
        SegmentTree<long long, (long long)2e18, min> tree(as);
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              long long expectedValue = (long long)2e18;
              for (int it = i; it <= j; ++it)
                  expectedValue = min(expectedValue, as[it]);
              long long actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            long long expectedValue = (long long)2e18;
            for (int it = l; it <= r; ++it)
                expectedValue = min(expectedValue, as[it]);
            long long actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            as[i] = rand(maxValue);
            tree.set(i, as[i]);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              long long expectedValue = (long long)2e18;
              for (int it = i; it <= j; ++it)
                  expectedValue = min(expectedValue, as[it]);
              long long actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            long long expectedValue = (long long)2e18;
            for (int it = l; it <= r; ++it)
                expectedValue = min(expectedValue, as[it]);
            long long actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }

        for (int i = 0; i < n; ++i) {
            int last = as[i];
            as[i] = rand(maxValue);
            tree.add(i, as[i] - last);
        }
        for (int i = 0; i < maxLen; ++i)
          for (int j = i; j < maxLen; ++j) {
              long long expectedValue = (long long)2e18;
              for (int it = i; it <= j; ++it)
                  expectedValue = min(expectedValue, as[it]);
              long long actualValue = tree.get(i, j);
              assert(actualValue == expectedValue);
          }
        for (int i = 0; i < maxQueries; ++i) {
            int l = rand() % n;
            int r = l + rand() % maxLen;
            long long expectedValue = (long long)2e18;
            for (int it = l; it <= r; ++it)
                expectedValue = min(expectedValue, as[it]);
            long long actualValue = tree.get(l, r);
            assert(expectedValue == actualValue);
        }
    }
    finishTime = double(clock()) / CLOCKS_PER_SEC;
    printf("OK, Time elapsed: %.2lf\n", finishTime - startTime);
}           