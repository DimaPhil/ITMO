#define TASKNAME "illumination"

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

int n;

struct FenwickTree {
    int n;
    vi t;

    FenwickTree(int _n) {
        n = _n;
        t.resize(n);
        t.assign(n, 0);
    }

    inline void update(int v, int x) {
        for (int i = v; i < n; i |= (i + 1))
            t[i] += x;
    }

    inline int get(int v) {
        int res = 0;
        for (int i = v; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }
};

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  vi a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
      scanf("%d", &b[i]), c[i] = a[i] - b[i];
  vll pref(n);
  pref[0] = c[0];
  vll pr;
  pr.pb(c[0]);
  for (int i = 1; i < n; i++)
      pref[i] = pref[i - 1] + c[i], pr.pb(pref[i]);
  
  sort(all(pr));
  map <ll, int> get;
  int counter = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
      if (pr[i] > 0)
          ++ans;
      if (get.find(pr[i]) == get.end())
          get[pr[i]] = counter++;
  }
  FenwickTree tree = FenwickTree(n + 10);
  for (int i = 0; i < n; i++) {
      ans += tree.get(get[pref[i]] - 1);
      tree.update(get[pref[i]], 1);
  }
  printf(LLD"\n", ans);
  return 0;
}
