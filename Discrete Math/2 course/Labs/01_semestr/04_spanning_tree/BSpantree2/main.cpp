#define TASKNAME "spantree2"

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

int p[maxn];

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

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    p[x] = y;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
      p[i] = i;
  vector <edge> edges;
  for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      --a, --b;
      edges.pb(edge(a, b, w));
  }
  sort(all(edges));
  ll ans = 0;
  for (int i = 0; i < m ;i++) {
      if (get(edges[i].a) != get(edges[i].b))
          unite(edges[i].a, edges[i].b), ans += edges[i].w;
  }
  printf("%I64d\n", ans);
  return 0;
}
