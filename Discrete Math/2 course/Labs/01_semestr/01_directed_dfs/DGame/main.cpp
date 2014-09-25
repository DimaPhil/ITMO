#define TASKNAME "game"

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

int n, m, s;
vi gr[maxn];
bool was[maxn];
bool win[maxn];
vi topsort;

void dfs(int v) {
    was[v] = 1;
    for (int i = 0; i < sz(gr[v]); i++)
        if (!was[gr[v][i]])
            dfs(gr[v][i]);
    topsort.pb(v);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &s);
  --s;
  for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      gr[a].pb(b);
  }
  dfs(s);
  reverse(all(topsort));
  win[sz(topsort) - 1] = 0;
  for (int i = sz(topsort) - 2; i >= 0; i--) {
      int v = topsort[i];
      win[v] = 0;
      for (int j = 0; j < sz(gr[v]); j++) {
          int u = gr[v][j];
          if (!win[u])
              win[v] = 1;
      }
  }
  printf("%s\n", win[s] ? "First player wins" : "Second player wins");
  return 0;
}
      