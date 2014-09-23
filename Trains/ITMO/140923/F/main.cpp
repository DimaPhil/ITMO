
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
 
int n;
int a[N], b[N], gg[N];
pair<int, int> ff[20][N];
 
 
 
pair<int, int> fm(int x, int y) {
    int w = gg[y - x + 1];
    return min(ff[w][x], ff[w][y - pw(w) + 1]);
}
 
int solve(int x, int y, int d) {
    int ret = y - x + 1;
    if (ret == 0) return 0;
    if (x == y) {
        if (d == b[x]) return 0;
        return 1;
    }
//    cout << x << " " << y << endl;
 
    pair<int, int> e = fm(x, y);
    int val = solve(x, e.S - 1, e.F) + solve(e.S + 1, y, e.F);
    if (e.F != d) val++;
    ret = min(ret, val);
    return ret;
}
 
int main() {
//    assert(freopen(TASK".in", "r", stdin));
  //  assert(freopen(TASK".out", "w", stdout));
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
 
    for (int i = 0; i < n; i++) ff[0][i] = mp(b[i], i);
 
    for (int i = 1; i < 20; i++) for (int j = 0; j < n; j++) if (j + pw(i) <= n) ff[i][j] = min(ff[i - 1][j], ff[i - 1][j + pw(i - 1)]);
    gg[1] = 0;
    for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1; 
 
    cout << solve(0, n - 1, 0) << endl;
    return 0;
}
