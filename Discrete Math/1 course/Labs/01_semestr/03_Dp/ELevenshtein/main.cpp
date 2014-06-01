#define TASKNAME "levenshtein"
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

const int maxn = 6000;

char s[maxn], t[maxn];
int dp[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  gets(s);
  gets(t);
  int ls = strlen(s), lt = strlen(t);

  for (int i = 0; i <= ls; i++)
    dp[i][0] = i;
  for (int i = 0; i <= lt; i++)
    dp[0][i] = i;
  for (int i = 1; i <= ls; i++)
    for (int j = 1; j <= lt; j++)
    {
      char a = s[i - 1], b = t[j - 1];
      dp[i][j] = dp[i - 1][j - 1] + (a != b);
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);     
    }     
  printf("%d\n", dp[ls][lt]);
  return 0;
}

