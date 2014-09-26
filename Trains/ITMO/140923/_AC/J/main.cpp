
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
#define N 555000
 
using namespace std;
typedef pair<int, int> pt;
 
#define TASK "1"
 
char s[N];
int n;
pair<pt, int> p[N];
int c[21][N];
int ans[N];
int it;
 
int lcp(int x, int y) {
    int r = 0;
    for (int i = it; i >= 0; i--) if (x + pw(i) <= n && y + pw(i) <= n && c[i][x] == c[i][y]) {
        x += pw(i);
        y += pw(i);
        r += pw(i);
    }
//    cout << x << " " << y << " " << r << endl;
    return r;
}
 
int main() {
//    assert(freopen(TASK".in", "r", stdin));
//    assert(freopen(TASK".out", "w", stdout));
    scanf("%d\n", &n);    
    gets(s);
 
    for (int i = 0; i < n; i++) p[i] = mp(mp(s[i], 0), i);
    sort(p, p + n);
 
    int e = 0;
 
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i - 1].F != p[i].F) e++;
        c[0][p[i].S] = e;
    }
 
    it = 0;
    while (pw(it) < n) {
        it++;
        for (int i =0; i < n; i++) if (i + pw(it - 1) >= n) p[i] = mp(mp(c[it - 1][i], -1), i); 
            else p[i] = mp(mp(c[it - 1][i], c[it - 1][i + pw(it - 1)]), i);
        sort(p, p + n);
        int e = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && p[i - 1].F != p[i].F) e++;
            c[it][p[i].S] = e;
        }
    }
//    for (int i = 0; i < n; i++) cout << p[i].S << " ";
  //  cout << endl;
    for (int i = 0; i < n; i++) {
        int x = 0;
        if (i > 0) x = max(x, lcp(p[i].S, p[i - 1].S));
        if (i + 1 < n) x = max(x, lcp(p[i].S, p[i + 1].S));
//        cout << x << endl;
        ans[p[i].S] = x;
    }
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}