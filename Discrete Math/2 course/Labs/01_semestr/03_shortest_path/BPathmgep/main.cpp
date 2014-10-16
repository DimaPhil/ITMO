#define TASKNAME "pathmgep"

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

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, s, f;
  scanf("%d%d%d", &n, &s, &f);
  --s, --f;
  vector <vpii> gr(n);
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      if (x >= 0)
          gr[i].pb(mp(j, x));
  }
  
  vi d(n, INF);
  d[s] = 0;
  set <pii> q;
  q.insert(mp(0, s));
  while (!q.empty()) {
      int v = q.begin()->snd;
      q.erase(q.begin());
      for (auto &e : gr[v]) {
          int u = e.fst;
          if (d[u] > d[v] + e.snd) {
              q.erase(mp(d[u], u));
              d[u] = d[v] + e.snd;
              q.insert(mp(d[u], u));
          }
      }
  }
  printf("%d\n", d[f] == INF ? -1 : d[f]);  
  return 0;
}
                   