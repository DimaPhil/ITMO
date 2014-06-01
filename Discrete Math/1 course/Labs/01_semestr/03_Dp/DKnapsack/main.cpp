#define TASKNAME "knapsack"
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
#define INF (int(1e9))
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
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  vi w(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &w[i]);
  vi c(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);
  vvi dp(n + 1, vi(m + 1, -INF)), pr(n + 1, vi(m + 1, 0));
  for (int i = 0; i <= m; i++)
  {
    dp[0][i] = 0;
    pr[0][i] = 0;
  }
  for (int i = 1; i <= n; i++)
    for (int needw = 0; needw <= m; needw++)
    {
      dp[i][needw] = dp[i - 1][needw];
      pr[i][needw] = 0;
      if (w[i - 1] <= needw && dp[i][needw] < dp[i - 1][needw - w[i - 1]] + c[i - 1])
        dp[i][needw] = dp[i - 1][needw - w[i - 1]] + c[i - 1], pr[i][needw] = 1;
    }
 
  vi ans;
  int nowi = n, nowj = m;
  for (int j = 0; j <= m; j++)
    if (dp[nowi][j] > dp[nowi][nowj])
      nowj = j;
  while (nowi)
  {
    if (pr[nowi][nowj])
      ans.pb(nowi), nowj -= w[nowi - 1];
    --nowi;
  }
  reverse(all(ans));
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++)
    printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
  return 0;
}

	