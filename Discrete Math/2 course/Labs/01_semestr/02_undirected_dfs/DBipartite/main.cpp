#define TASKNAME "bipartite"

#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
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

template <typename T>
T sqr(T x) {
    return x * x;
}

template <typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

const int maxn = 2e5 + 10;
const int maxq = maxn * 10;

int n, m;
vvi gr;
int q[maxq];
int d[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  gr.resize(n);
  bool fail = false;
  for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      if (a == b)
          fail = true;
      gr[a].pb(b);
      gr[b].pb(a);
  }

  for (int i = 0; i < n; i++)
      d[i] = INF;
  for (int startV = 0; startV < n; startV++) {
      if (d[startV] != INF)
          continue;
      d[startV] = 0;
      int start = 0, end = 0;
      q[end++] = startV;
      while (start != end) {
          int v = q[start++];
          if (start == maxq)
              start = 0;
          for (auto &u : gr[v]) {
              if (d[u] != INF && !((d[u] - d[v]) & 1))
                  fail = true;
              if (d[u] > d[v] + 1) {
                  d[u] = d[v] + 1;
                  q[end++] = u;
                  if (end == maxq)
                      end = 0;
              }
          }
      }
  }
  printf("%s\n", fail ? "NO" : "YES");
  return 0;              
}
