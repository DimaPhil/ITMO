#define TASKNAME "game"
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

const int maxn = 1e5 + 10;

int n, k;
int a[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    ll x;
    scanf("%I64d", &x), a[i] = (int)min(x, (ll)n);
  }
  vi dp(n + 1, 0);
  vi pr(n + 1, 1);
  dp[1] = 1;
  vi mx(n + 1, 0);
  vi idx(n + 1, 0);
  mx[1] = a[1] + 1;
  idx[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    mx[i] = mx[i - 1], idx[i] = idx[i - 1];
    if (i - k <= 0)
    {
      dp[i] = 0;
      continue;
    }
    int m = mx[i - k];
    int id = idx[i - k];
    if (m >= i)
      dp[i] = 1, pr[i] = id;
    if (dp[i] && a[i] + i > mx[i])
      mx[i] = a[i] + i, idx[i] = i;
  }
  if (!dp[n])
    puts("IMPOSSIBLE");
  else
  {
    puts("POSSIBLE");
    int now = n;
    vpii ans;
    while (now != 1)
    {
      ans.pb(mp(pr[now], now - pr[now]));
      now = pr[now];
    }
    reverse(all(ans));
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++)  
      printf("%d %d\n", ans[i].fst, ans[i].snd);
  }
  return 0;
}

