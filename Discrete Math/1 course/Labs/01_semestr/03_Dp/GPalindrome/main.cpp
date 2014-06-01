#define TASKNAME "palindrome"
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
char s[maxn];
int dp[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  gets(s);
  n = strlen(s);
  for (int len = 1; len <= n; len++)
    for (int i = 0; i <= n - len; i++)
    {
      int j = i + len - 1;
      if (s[i] == s[j])
        dp[i][j] = (j ? dp[i + 1][j - 1] : 0) + ((i < j) ? 2 : 1);
      dp[i][j] = max(dp[i][j], max(dp[i + 1][j], j ? dp[i][j - 1] : 0));
    }
  int nowi = 0, nowj = n - 1;
  vector < pair <char, int> > ans;
  while (nowi <= nowj && nowj >= 0 && nowi < n)
  {
    if (s[nowi] == s[nowj])
    {
      ans.pb(mp(s[nowi], int(nowi < nowj)));
      ++nowi, --nowj;
    }
    else
    {
      int first = dp[nowi + 1][nowj];
      int second = (nowj ? dp[nowi][nowj - 1] : 0);
      if (first < second)
        --nowj;
      else
        ++nowi;
    }
  }
  int answer = (sz(ans) - 1) * 2 + ans.back().snd + 1;
  printf("%d\n", answer);
  for (int i = 0; i < sz(ans) - 1; i++)
    printf("%c", ans[i].fst);
  for (int i = 0; i <= ans.back().snd; i++)
    printf("%c", ans.back().fst);
  for (int i = sz(ans) - 2; i >= 0; i--)
    printf("%c", ans[i].fst);
  printf("\n");
  return 0;
}

