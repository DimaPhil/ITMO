#define TASKNAME "roundelay"

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

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vi a(n);
  for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
  vvi dp(n + 1, vi(n + 1, 1));
  for (int i = 0; i < n - 1; i++)
      dp[i][i + 1] = a[i] == a[i + 1] ? 2 : 1;
  for (int len = 3; len <= n; len++)
  for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      dp[i][j] = max(dp[i][j], dp[i + 1][j]);
      for (int it = i + 1; it <= j; it++)
          if (a[i] == a[it])
              dp[i][j] = max(dp[i][j], dp[i + 1][it - 1] + dp[it + 1][j]);
  }
  printf("%d\n", dp[0][n - 1]);                           
  return 0;
}
