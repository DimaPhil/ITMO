#define TASKNAME "lis"
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
  vi dp(n, 1), pr(n, -1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[j] < a[i] && dp[j] + 1 > dp[i])
        dp[i] = dp[j] + 1, pr[i] = j;
  int idx = -1, mx = 0;
  for (int i = 0; i < n; i++)
    if (mx < dp[i])
      mx = dp[i], idx = i;
  assert(idx != -1 && mx == dp[idx]);
  printf("%d\n", dp[idx]);
  vi ans;
  while (idx != -1)
  {
    ans.pb(a[idx]);
    idx = pr[idx];
  }
  reverse(all(ans));
  for (int i = 0; i < sz(ans); i++)
    printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
  return 0;
}

