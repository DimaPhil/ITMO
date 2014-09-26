#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
 
using namespace std;
 
const int INF = (int)1e9;
 
struct ST {
    int n;
    vector <int> t;
 
    ST() {n = 0, t.clear();}
    ST(int _n) {
        n = 1;
        while (n < _n)
            n <<= 1;
        t.resize(n << 1);
        for (int i = 0; i < (n << 1); i++)
            t[i] = -INF;
    }
 
    void update(int v, int x) {
        v += n;
        t[v] = x;
        v >>= 1;
        while (v)
            t[v] = max(t[v << 1], t[(v << 1) + 1]), v >>= 1;
    }
 
    int get(int v, int a, int b, int l, int r) {
        if (a > r || l > b)
            return -INF;
        if (l <= a && b <= r)
            return t[v];
        int m = (a + b) >> 1;
        return max(get(v << 1, a, m, l, r), get((v << 1) + 1, m + 1, b, l, r));
    }
 
    int get(int l, int r) {
        if (l > r)
            return -INF;
        return get(1, n, (n << 1) - 1, l + n, r + n);
    }
};
 
const int maxn = (int)1e5 + 10;
 
int n[2];
int ans;
int x[2][maxn], y[2][maxn];
int compress[maxn];
vector <int> ys;
 
struct event {
    int x, y, type, id;
    event() {x = y = type = id = 0;}
    event(int x, int y, int type, int id) : x(x), y(y), type(type), id(id) {}
};                                          
 
inline bool operator < (const event &a, const event &b) {return a.x < b.x || (a.x == b.x && a.type > b.type);}
 
vector <event> events;
 
void solve() {
    ys.clear();
    for (int i = 0; i < n[1]; i++) {
        ys.push_back(y[1][i]);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
 
    for (int type = 0; type < 2; type++)
    for (int i = 0; i < n[type]; i++) {
        events.push_back(event(x[type][i], y[type][i], type, i));
    }
    sort(events.begin(), events.end());
 
    ST tree[2];
    tree[0] = ST((int)ys.size());
    tree[1] = ST((int)ys.size());
    for (int i = 0; i < (int)events.size(); i++) {
        if (events[i].type == 1) {
            int pos = lower_bound(ys.begin(), ys.end(), events[i].y) - ys.begin();
            tree[0].update(pos, events[i].x + events[i].y);
            tree[1].update(pos, events[i].x - events[i].y);
            continue;
        }
        int x = events[i].x;
        int y = events[i].y;
 
        int pos = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
        int maxDown = tree[0].get(0, pos - 1);
        int maxUp = tree[1].get(pos, (int)ys.size() - 1);
        ans = min(ans, x + y - maxDown);
        ans = min(ans, x - y - maxUp);
    }
}                                   
 
int main() {
    //freopen("text.in", "r", stdin);
    //freopen("text.out", "w", stdout);
    scanf("%d%d", &n[0], &n[1]);
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < n[i]; j++)
        scanf("%d%d", &x[i][j], &y[i][j]);
 
    ans = INF;
    solve();
    for (int type = 0; type < 2; type++)
    for (int i = 0; i < n[type]; i++)
        x[type][i] *= -1;
    solve();
    printf("%d\n", ans);
    return 0;
}