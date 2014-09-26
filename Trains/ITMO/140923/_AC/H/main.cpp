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
#define N 333000
 
using namespace std;
typedef pair<int, int> pt;
 
#define TASK "1"
 
int n, m;
int was[N], ans[N];
vector<int> v[N];
 
int rec(int x, int p) {
    was[x] = 1;
    int ok = 0;
    for (int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if (to == p) continue;
        if (!was[to]) {
            if (rec(to, x)) {
                ans[x] = to + 1;
                ok = 1;
            }
        } else {
            if (ans[to] == x + 1) continue;
            ok = 1;
            ans[x] = to + 1;
        }
    }
    if (!ok) {
        ans[x] = p + 1;
    }
    return ok;
}
 
int main() {
//    assert(freopen(TASK".in", "r", stdin));
//    assert(freopen(TASK".out", "w", stdout));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        v[x].pb(y);
        v[y].pb(x);
    }    
    for (int i = 0; i < n; i++) if (!was[i]) {
        if (rec(i, i) == 0) {
            puts("NIE");
            return 0;
        }
    }
    puts("TAK");
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}
