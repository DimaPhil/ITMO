#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
 
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pw(x) (1ll << (x))
#define N 1000111
 
using namespace std;
typedef pair<int, int> pt;
 
#define TASK "1"
 
char a[N];
int n, p, q, xx, yy;
int s[N], m1[N], m2[N];
 
int main() {
//    assert(freopen(TASK".in", "r", stdin));
//    assert(freopen(TASK".out", "w", stdout));
    scanf("%d%d%d%d%d\n", &n, &p, &q, &xx, &yy);
    gets(a);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i];
        if (a[i] == '+') s[i + 1]++; else s[i + 1]--;
    }
    m1[0] = s[1];
    for (int i = 1; i < n; i++) m1[i] = min(m1[i - 1], s[i + 1]);
 
    m2[n - 1] = s[n];
    for (int i = n - 2; i >= 0; i--) m2[i] = min(m2[i + 1], s[i + 1]);
 
    long long ans = 2e12 + 10;
    for (int i = 0; i < n; i++) {
        int x = m2[i] - s[i];
        if (i > 0) {
            int y = m1[i];
            y += s[n] - s[i];
            x = min(x, y);
        }
        x += p;
        int add = 0;
 
        if (x < 0) {
            add = (-x + 1) / 2;
        }
        int add2 = abs(p + s[n] + add * 2 - q) / 2;
 
        int shift = (n - i);
        if (i == 0) shift = 0;
        ans = min(ans, shift * 1ll * yy + (add + add2) * 1ll * xx);
//        cout << i << " " << add2 << endl;
//        cout << i << " " << shift * yy + (add + add2) * xx << endl;
    }
    cout << ans << endl;
 
    return 0;
}
