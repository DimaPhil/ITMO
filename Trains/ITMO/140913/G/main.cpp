#define TASKNAME "text"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
 
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;            
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

struct ST {
    vi t, upd;
    int n;       

    ST() {t.clear(), upd.clear(), n = 0;}
    ST(int _n) {
        n = 1;
        while (n < _n)
            n <<= 1;
        t.resize(n << 1);
        upd.resize(n << 1);
        for (int i = 0; i < (n << 1); i++)
            t[i] = upd[i] = 0;
    }

    void push(int v, int len) {
        if (!upd[v])
            return;
        t[v] += upd[v] * len;
        if (v < n) {
            upd[v << 1] += upd[v];
            upd[(v << 1) + 1] += upd[v];
        }
        upd[v] = 0;
    }

    void update(int v, int a, int b, int l, int r, int x) {
        push(v, b - a + 1);
        if (l > b || a > r)
            return;
        if (l <= a && b <= r) {
            upd[v] += x;
            push(v, b - a + 1);
            return;
        }
        int m = (a + b) >> 1;
        update(v << 1, a, m, l, r, x);
        update((v << 1) + 1, m + 1, b, l, r, x);
        t[v] = t[v << 1] + t[(v << 1) + 1];
    }              

    void update(int l, int r, int x) {
        update(1, n, (n << 1) - 1, l + n, r + n, x);
    }

    int get(int v, int a, int b, int l, int r) {
        push(v, b - a + 1);
        if (l > b || a > r)
            return 0;
        if (l <= a && b <= r)
            return t[v];
        int m = (a + b) >> 1;
        return get(v << 1, a, m, l, r) + get((v << 1) + 1, m + 1, b, l, r);
    }

    int get(int l, int r) {
        return get(1, n, (n << 1) - 1, l + n, r + n);
    }
};

int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  int testsCount;
  scanf("%d", &testsCount);
  for (int testNumber = 0; testNumber < testsCount; testNumber++) {
      int n;
      scanf("%d", &n);
      vi xs, ys;
      vi x(n), y(n);
      for (int i = 0; i < n; i++) {
          scanf("%d%d", &x[i], &y[i]);
          xs.pb(x[i]);
          ys.pb(y[i]);
      }           
      sort(all(xs));
      sort(all(ys));
      xs.erase(unique(all(xs)) - xs.begin());
      ys.erase(unique(all(ys)) - ys.begin());

      for ()
  }
  return 0;
}
                     