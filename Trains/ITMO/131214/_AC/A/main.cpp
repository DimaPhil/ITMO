#define TASKNAME "a"

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
#define all(a) (a).begin, (a).end()
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

const int maxn = 7010;

struct edge
{
  int v, u, w, id;
  edge() {v = u = w = id = 0;}
  edge(int v, int u, int w, int id) : v(v), u(u), w(w), id(id) {}
};

//inline bool operator < (const edge &a, const edge &b) {return a.w < b.w;}
                                                       
int n, m;
int p[maxn];

int get(int x)
{
  return x == p[x] ? x : p[x] = get(p[x]);
}

void unite(int x, int y)
{
  x = get(x);
  y = get(y);
  if (x == y)
    return;
  if (rand() & 1)
    p[x] = y;
  else
    p[y] = x;
}

inline bool Less(edge a, edge b)
{
  return a.w < b.w;
}

int main()
{
  srand(time(NULL));
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  vector <edge> edges;
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    --a, --b;
    edges.pb(edge(a, b, w, i));
  }
  sort(edges.begin(), edges.end(), Less);
  vi ans(sz(edges), 0);
  for (int i = 0; i < n; i++)
    p[i] = i;
  for (int i = 0; i < sz(edges);)
  {
    int i0 = i;
    while (i < sz(edges) && edges[i].w == edges[i0].w)
      ++i;
    for (int j = i0; j < i; j++)
      if (get(edges[j].v) != get(edges[j].u))
        ans[edges[j].id] = 1;
      else
        ans[edges[j].id] = 0;
    for (int j = i0; j < i; j++)
      if (get(edges[j].v) != get(edges[j].u))
        unite(edges[j].v, edges[j].u);
  }
  for (int i = 0; i < m; i++)
    printf("%s\n", ans[i] ? "YES" : "NO");
  return 0;          
}
