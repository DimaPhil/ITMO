#define TASKNAME "foremen"
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

const int maxn = 110;

int n, k;
int cost[maxn][maxn];
int dp[maxn][maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &cost[i][j]);
  for (int i = 0; i < n; i++)
    for (int taken = 0; taken <= i + 1; taken++)
      for (int caps = 0; caps <= taken; caps++)
      {
        dp[i][taken][caps] = INF;
        for (int size = 1; size <= i - taken + 1; size++)
          if (dp[i][taken][caps] > (i - size >= 0 ? dp[i - size][taken + size][caps + 1] : 0) + cost[i][size])
            dp[i][taken][caps] = (i - size >= 0 ? dp[i - size][taken + size][caps + 1] : 0) + cost[i][size];
      }
  printf("%d\n", dp[])
  return 0;
}

