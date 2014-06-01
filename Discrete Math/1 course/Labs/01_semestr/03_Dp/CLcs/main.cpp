#define TASKNAME "lcs"
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
  int n;
  scanf("%d", &n);
  vi a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  int m;
  scanf("%d", &m);
  vi b(m);
  for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);

  vvi dp(n, vi(m, 0));
  dp[0][0] = a[0] == b[0];
  for (int i = 1; i < n; i++)
    dp[i][0] = max(int(a[i] == b[0]), dp[i - 1][0]);
  for (int i = 1; i < m; i++)
    dp[0][i] = max(int(a[0] == b[i]), dp[0][i - 1]);
  for (int i = 1; i < n; i++)     
    for (int j = 1; j < m; j++)
    {
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = dp[i - 1][j];
      dp[i][j]  = max(dp[i][j], dp[i][j - 1]);
    }

  printf("%d\n", dp[n - 1][m - 1]);
  int nowi = n - 1, nowj = m - 1;
  vi ans;
  while (nowi != -1 && nowj != -1)
  {
    if (a[nowi] == b[nowj])
      ans.pb(a[nowi--]), --nowj;
    else
    {
      int prev1 = (!nowi ? 0 : dp[nowi - 1][nowj]);
      int prev2 = (!nowj ? 0 : dp[nowi][nowj - 1]);
      if (prev1 < prev2)
        --nowj;
      else
        --nowi;
    }
  }
  reverse(all(ans));
  for (int i = 0; i < sz(ans); i++)
    printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
  return 0;
}

