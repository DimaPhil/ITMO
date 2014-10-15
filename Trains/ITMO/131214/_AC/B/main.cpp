#define TASKNAME "b"

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define EPS (1e-9)
#define INF (1e9)
#define INFLONG (1e18)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define zero(a) memset(a, 0, sizeof(a))
#define sqr(a) ((a) * (a))
#define fst first
#define snd second
#define y1 dfkljaf
#define y0 flksdjf
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <bool> vb;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <vb> vvb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

struct pt
{
  ll x, y;
  pt() {x = y = 0;}
  pt(ll x, ll y) : x(x), y(y) {}

  inline ll len2()
  {
    return x * x + y * y;
  }

  inline double len()
  {
    return sqrt(len2() + 0.0);
  }
};

const int maxn = 1e5 + 100;

int n;
ll k;
int m[maxn], p[maxn];
vector <pt> ps[maxn];

inline ll updh(ll h)
{
  if (!(h % k))
    return h / k;
  return (h / k) + 1;
}

inline ll geth(vector <pt> &p)
{
  ll mx = 0;
  for (int i = 0; i < sz(p); i++)
    mx = max(mx, p[i].len2());
  ll root = sqrt(mx + 0.0);
  for (ll h = root - 1; h <= root + 1; h++)
    if (h * h >= mx)
      return updh(h);
  assert(0);
  return -1;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%I64d", &n, &k);
  vector < pair <ll, int> > hs(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &m[i], &p[i]);
    ps[i].resize(m[i]);
    for (int j = 0; j < m[i]; j++)
      scanf("%I64d%I64d", &ps[i][j].x, &ps[i][j].y);
    hs[i] = mp(geth(ps[i]), i);
  }
  sort(all(hs));
  int i = 0;
  ll mx = 0;
  ll s = 0;
  while (i < sz(hs))
  {
    int i0 = i;
    while (i < sz(hs) && hs[i].fst == hs[i0].fst)
      s += p[hs[i].snd], ++i;            
    mx = max(mx, s - hs[i0].fst * (hs[i0].fst - 1) / 2);
  }
  printf("%I64d\n", mx);
  return 0;
}
