#define TASKNAME "keyboard"

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

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

const int maxn = 1010;

int n, k;
int a[maxn];
ll dp[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
  for (int i = 0; i <= k; i++)
      for (int j = 0; j <= n; j++)
          dp[i][j] = INFLONG;
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
          dp[i][j] = dp[i - 1][j];
          ll s = 0, ps = 0;
          for (int lj = j - 1; lj >= 0; lj--) {
              ll cost = ps + s + a[lj];
              ps = cost;
              s += a[lj];
              dp[i][j] = min(dp[i][j], dp[i - 1][lj] + cost);
          }
      }
  }
  printf(LLD"\n", dp[k][n]);
  return 0;
}
