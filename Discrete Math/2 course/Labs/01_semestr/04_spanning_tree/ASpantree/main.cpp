#define TASKNAME "spantree"

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

const int maxn = 5010;

int n;
int x[maxn], y[maxn];

double dist(int i, int j) {
    return sqrt(.0 + sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
      scanf("%d%d", &x[i], &y[i]);
  vb was(n, false);
  vector <double> d(n, 1e18);
  double ans = 0;
  d[0] = 0;
  for (int it = 0; it < n; it++) {
      int v = -1;
      for (int i = 0; i < n; i++) {
          if (!was[i] && (v == -1 || d[i] < d[v]))
              v = i;
      }
      ans += d[v];
      was[v] = true;
      for (int i = 0; i < n; i++)
          if (!was[i] && d[i] > dist(v, i))
              d[i] = dist(v, i);
  }
  printf("%.10lf\n", ans);
  return 0;
}
