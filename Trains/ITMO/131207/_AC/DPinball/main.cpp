#define TASKNAME "pinball"
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

const int maxn = 50;

int n;
ll C[maxn][maxn];
int cost[maxn][maxn];

inline int digit_sum(int x)
{
  int ans = 0;
  while (x)
    ans += x % 10, x /= 10;
  return ans;
}

ll dp[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  for (int i = 0; i < maxn; i++)
    C[i][0] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j < maxn; j++)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++)
      cost[i][j] = digit_sum(C[i][j]);

  scanf("%d", &n);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++)
      dp[i][j] = max(dp[i - 1][j], (j ? dp[i - 1][j - 1] : 0)) + cost[i][j];
  ll mx = 0;
  for (int i = 0; i <= n; i++)
    mx = max(mx, dp[n][i]);
  printf("%I64d\n", mx);
  return 0;
}

