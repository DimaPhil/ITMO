#define TASKNAME "mindiff"
 
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
 
const int maxn = 1e5 + 10;
 
int p[maxn], h[maxn];
                  
struct edge {
    int a, b, w;
    edge() {}
    edge(int a, int b, int w) : a(a), b(b), w(w) {}
};
 
bool operator < (const edge &a, const edge &b) { return a.w < b.w; }
 
int get(int x) {
    if (p[x] == x)
        return x;
    return p[x] = get(p[x]);
}
 
void unite(int v, int u) {
    if (h[v] > h[u])
        swap(v, u);
    p[v] = u;
    if (h[v] == h[u])
        ++h[u];
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  vector <edge> edges;
  for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      --a, --b;
      edges.pb(edge(a, b, w));
  }
  sort(all(edges));
  bool exist = false;
  int ans = 2 * INF + 1;
  for (int e = 0; e < m; e++) {
      for (int i = 0; i < n; i++)
          p[i] = i, h[i] = 0;
      int maxe = -INF;
      int cnt_edges = 0;
      for (int i = e; i < m; i++) {
          int v = get(edges[i].a);
          int u = get(edges[i].b);
          if (v != u)
              unite(v, u), maxe = edges[i].w, cnt_edges++;
      }
      if (cnt_edges == n - 1) {
          exist = true;
      } else {
          continue;
      }
      if (maxe - edges[e].w < ans)
          ans = maxe - edges[e].w;
  }
  if (!exist) {
      printf("NO\n");
  } else {
      printf("YES\n");
      printf("%d\n", ans);
  }
  return 0;
}