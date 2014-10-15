#define TASKNAME "docs"
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
 
#define EPS (1e-9)
#define INF (int(1e9))
#define INFLONG (long long)(1e18)
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
#define next dlkjdslfkdj
#define prev dsdflksdfjl
#define hash lkdfjldskfj
#define pi 3.1415926535897932384626433832795
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

const int maxn = 1e5 + 10;

struct T
{
  int a, b, id;
  T() {a = b = id = 0;}
  T(int a, int b, int id) : a(a), b(b), id(id) {}
};

inline bool operator < (const T &a, const T &b) {return a.a < b.a;}

struct ST
{
  vpii t;
  int n;

  ST() {t.clear(), n = 0;}
  ST(vector <T> &a)
  {
    int _n = sz(a);
    n = 1;
    while (n < _n)
      n <<= 1;

    t.resize(n << 1);
    for (int i = 0; i < (n << 1); i++)
      t[i] = mp(INF, INF);
    for (int i = 0; i < _n; i++)
      t[i + n] = mp(a[i].b, i);
  }

  inline void update(int v, int x)
  {
    v += n;
    t[v].fst = x;
    v >>= 1;
    while (v)
      t[v] = min(t[v << 1], t[(v << 1) + 1]), v >>= 1;
  }                     

  inline pii get(int v, int l, int r, int a, int b)
  {
    if (l > b || a > r)
      return mp(INF, INF);
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    return min(get(v << 1, l, r, a, m), get((v << 1) + 1, l, r, m + 1, b));
  }

  inline pii get(int l, int r)
  {
    return get(1, l + n, r + n, n, (n << 1) - 1);
  }
};

struct query
{
  int l, r, val, id;
  query() {l = r = val = id = 0;}
  query(int l, int r, int val, int id) : l(l), r(r), val(val), id(id) {}
};

inline bool operator < (const query &a, const query &b) {return a.l < b.l || (a.l == b.l && a.r < b.r);}

map <int, int> get;
vi poses[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vector <T> p(n);
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &p[i].a, &p[i].b), p[i].id = i;
    if (get.find(p[i].b) == get.end())
      get[p[i].b] = cnt++;
    poses[get[p[i].b]].pb(i);
  }
  sort(all(p));

  ST tree = ST(p);
  eprintf("%d\n", tree.get(1, 2).fst);
  int q;
  scanf("%d", &q);
  vector <query> qs;
  for (int i = 0; i < q; i++)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    int pl = lower_bound(all(p), T(l, -1, -1)) - p.begin();
    int pr = upper_bound(all(p), T(r, INF, INF)) - p.begin();
    if (pl >= pr)
    {
      puts("BOTVA");
      return 0;
    }
    pii ansq = tree.get(pl, pr - 1);
    if (ansq.fst == INF)
    {
      puts("BOTVA");
      return 0;
    }
    //ans.pb(p[ansq.snd].id);
    //tree.update(ansq.snd, INF);
    qs.pb(query(pl, pr, ansq.fst, i));
  }

  sort(all(qs));
  int now_pos = 0;
  vi ans(q);
  for (int i = 0; i < sz(qs); i++)
  {
    eprintf("%d %d %d\n", qs[i].l + 1, qs[i].r + 1, qs[i].val);
    int x = qs[i].val;                                 
    int px = get[x];
    if (now_pos < qs[i].l)
      now_pos = qs[i].l;
    int pos = lower_bound(all(poses[px]), now_pos) - poses[px].begin();
    if (pos < sz(poses[px]) && pos <= qs[i].r)
    {
      int idx = poses[px][pos];
      ans[qs[i].id] = p[idx].id;
      //was[idx] = 1;
      now_pos = idx;
    }
    else
    {
      puts("BOTVA");
      return 0;
    }
  }
               
  for (int i = 0; i < sz(ans); i++)
    printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
  return 0;
}

