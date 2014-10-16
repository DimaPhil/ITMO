#define TASKNAME "path"

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
const ll INFLONG = (ll)7e18;

const int MAX_IT = 5000;

vector < vector <pil> > gr;
vb was;

void dfs(int v) {
    was[v] = true;
    for (auto &e : gr[v]) {
        if (!was[e.fst])
            dfs(e.fst);
    }
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);
  --s;
  gr.resize(n);
  for (int i = 0; i < m; i++) {
      int v, u;
      ll w;
      scanf("%d%d" LLD, &v, &u, &w);
      --v, --u;
      gr[v].pb(mp(u, w));
  }

  vll d(n, INFLONG);
  d[s] = 0;
  vb better(n, false);
  for (int it = 0; it < MAX_IT; it++) {
      vll nd(n);
      for (int i = 0; i < n; i++)
          nd[i] = d[i], better[i] = false;

      for (int i = 0; i < n; i++) {
          for (auto &e : gr[i]) {
              int u = e.fst;
              if (d[i] != INFLONG && d[u] > d[i] + e.snd) {
                  better[u] = true;
                  nd[u] = d[i] + e.snd;
              }
          }
      }

      for (int i = 0; i < n; i++)
          d[i] = nd[i];
  }

  was.resize(n);
  for (int i = 0; i < n; i++)
      was[i] = false;
  for (int i = 0; i < n; i++)
      if (better[i] && !was[i])
          dfs(i);
  for (int i = 0; i < n; i++) {
      if (was[i])
          printf("-\n");
      else
      if (d[i] == INFLONG)
          printf("*\n");
      else
          printf(LLD"\n", d[i]);
  }
  return 0;
}
