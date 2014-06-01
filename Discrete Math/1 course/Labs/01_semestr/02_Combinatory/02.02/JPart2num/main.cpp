#define TASKNAME "part2num"
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

const int maxn = 300;

int n;
char s[maxn];
int dp[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  while (gets(s))
  {
    int len = strlen(s);
    s[len++] = '+';
    vi a;
    n = 0;
    int now = 0;
    for (int i = 0; i < len; i++)
    {
      if (isdigit(s[i]))
        now = now * 10 + s[i] - '0';
      else
        a.pb(now), n += now, now = 0;
    }

    for (int i = 0; i <= n; i++)
      dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
      for (int last = 1; last <= n; last++)
        for (int x = last; x <= i; x++)
          dp[i][last] += dp[i - x][x];
          
    int last = 1;
    int ans = 0;
    for (int i = 0; i < sz(a); i++)
    {
      for (int j = last; j < a[i]; j++)
        ans += dp[n - j][j];
      last = a[i];
      n -= a[i];
    }
    printf("%d\n", ans);
    break;
  }
  return 0;
}

