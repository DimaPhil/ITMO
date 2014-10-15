#define TASKNAME "cubes"
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
#define INF (int(2e9))
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

struct edge
{
  int b, u, c, f;
  int back;
  edge() {}
  edge(int b, int u, int c, int f, int back) : b(b), u(u), c(c), f(f), back(back) {}
};

const int maxn = 500;

int n, s, need;
int S, T;
int a[maxn];
int d[maxn][maxn];
vector <edge> gr[maxn];  

inline void add_edge(int a, int b, int u, int c) {
  edge r1 = edge(b, u, c, 0, sz(gr[b]));
  edge r2 = edge(a, 0, -c, 0, sz(gr[a]));
  gr[a].pb(r1);
  gr[b].pb(r2);
}

inline void adde(int a, int b, int u, int c)
{
  add_edge(a, b, u, c);
  //add_edge(b, a, 0, -c);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  s = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), s += a[i];
  assert(!(s % n));
  need = s / n;
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &d[i][j]);
  for (int i = 0; i < n; i++)
    d[i][i] = 0;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  S = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > need)
      adde(S, i + 1, a[i] - need, 0);
    else
      adde(S, i + 1, 0, 0);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i] > need && a[j] < need)
        adde(i + 1, j + n + 1, INF, d[i][j]);
  T = 2 * n + 1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < need)
      adde(i + n + 1, T, need - a[i], 0);
    else
      adde(i + n + 1, T, 0, 0);
  }

  int N = 4 * n + 10;

  ll flow = 0;
  ll cost = 0;
  while (flow < INFLONG) {
    vi id(N, 0);
    vll d(N, INFLONG);
    vi q(N);
    vi p(N);
    vi p_edge(N);
    int qh = 0, qt = 0;
    q[qt++] = S;
    d[S] = 0;
    while (qh != qt)
    {
      int v = q[qh++];
      id[v] = 2;
      if (qh == N)
        qh = 0;
      for (int i = 0; i < sz(gr[v]); i++) {
        edge &r = gr[v][i];
        if (r.f < r.u && d[v] + r.c < d[r.b]) {
          d[r.b] = d[v] + r.c;
          if (!id[r.b])
          {
            q[qt++] = r.b;
            if (qt == N)
              qt = 0;
          }
          else if (id[r.b] == 2)
          {
            if (--qh == -1)
              qh = N - 1;
            q[qh] = r.b;
          }
          id[r.b] = 1;
          p[r.b] = v;
          p_edge[r.b] = i;
        }
      }
    }
    if (d[T] == INFLONG)
      break;
    int addflow = INF;
    for (int v = T; v != S; v = p[v])
    {
      int pv = p[v];
      int pr = p_edge[v];
      addflow = min(addflow, gr[pv][pr].u - gr[pv][pr].f);
    }
    for (int v = T; v != S; v = p[v])
    {
      int pv = p[v];
      int pr = p_edge[v];
      int r = gr[pv][pr].back;
      gr[pv][pr].f += addflow;
      gr[v][r].f -= addflow;
      cost += (ll)gr[pv][pr].c * addflow;
    }
    flow += addflow;
  }
  printf("%I64d\n", cost);
  return 0;
}

