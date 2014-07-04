#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    Point() { x = y = 0; }
    Point(long long x, long long y) : x(x), y(y) {}

    void print() {
        printf(LLD" "LLD"\n", x, y);
    }                
};                    