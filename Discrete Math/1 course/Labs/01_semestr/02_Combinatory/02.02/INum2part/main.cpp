#define TASKNAME "num2part"
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

const int maxn = 200;

int n, k;
int dp[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  while (scanf("%d%d", &n, &k) >= 1)
  {
    for (int i = 0; i <= n; i++)
      dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
      for (int last = 1; last <= n; last++)
        for (int x = last; x <= i; x++)
          dp[i][last] += dp[i - x][x];
          
    int last = 1;
    vi ans;
    while (n > 0)
    {
      for (int i = last; i <= n; i++)
      {
        if (k >= dp[n - i][i])
          k -= dp[n - i][i];
        else
        {
          ans.pb(i);
          last = i;
          n -= i;
          break;
        }
      }
    }
    assert(!n);
    for (int i = 0; i < sz(ans); i++)
      printf("%d%c", ans[i], "+\n"[i == sz(ans) - 1]);
    break;
  }
  return 0;
}

