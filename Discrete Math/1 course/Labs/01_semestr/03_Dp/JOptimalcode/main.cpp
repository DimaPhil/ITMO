#define TASKNAME "optimalcode"
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

const int maxn = 3010;

int n;
int f[maxn];
ll pref[maxn];
ll dp[maxn][maxn];
int pr[maxn][maxn];
string ans[maxn];

inline ll getw(int l, int r)
{
  if (!l)
    return pref[r];
  return pref[r] - pref[l - 1];
}

inline void get_ans(int l, int r, string &s)
{
  if (l > r)
    return;
  if (l == r)
  {
    ans[l] = s;
    return;
  }
  int pos = pr[l][r];
  string tleft = s + '0';
  string tright = s + '1';
  get_ans(l, pos, tleft);
  get_ans(pos + 1, r, tright);
}                    
                   
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &f[i]);
  pref[0] = f[0];
  for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + f[i];

  for (int i = 0; i < n; i++)
    dp[i][i] = 0, pr[i][i] = i;
  for (int len = 2; len <= n; len++)
    for (int i = 0; i <= n - len; i++)
    {
      int j = i + len - 1;
      int best = -1;
      ll mn = INFLONG;
      //for (int k = i; k < j; k++)
      for (int k = pr[i][j - 1]; k <= pr[i + 1][j]; k++)
        if (mn > dp[i][k] + dp[k + 1][j])
          mn = dp[i][k] + dp[k + 1][j], best = k;
      assert(best != -1);
      pr[i][j] = best;
      dp[i][j] = mn + getw(i, j);
    }
  printf("%I64d\n", dp[0][n - 1]);
  string s = "";
  get_ans(0, n - 1, s);
  for (int i = 0; i < n; i++)
    printf("%s\n", ans[i].c_str());
  return 0;
}

