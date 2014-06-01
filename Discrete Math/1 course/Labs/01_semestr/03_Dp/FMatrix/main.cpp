#define TASKNAME "matrix"
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

const int maxn = 500;

int n;
int a[maxn], b[maxn];
int dp[maxn][maxn], idx[maxn][maxn];

void get_ans(int l, int r)
{
  if (l > r)
    return;
  if (l == r)
  {
    printf("A");
    return;
  }
  int middle = idx[l][r];
  if (l < middle)
    printf("(");
  get_ans(l, middle);
  if (l < middle)
    printf(")");
  if (middle + 1 < r)
    printf("(");
  get_ans(middle + 1, r);
  if (middle + 1 < r)
    printf(")");
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &a[i], &b[i]);
  for (int i = 0; i < n; i++)
    dp[i][i] = 0, idx[i][i] = -1;
  for (int len = 2; len <= n; len++)
    for (int i = 0; i <= n - len; i++)
    {
      int j = i + len - 1;
      dp[i][j] = INF;
      idx[i][j] = -1;
      for (int k = i; k < j; k++)
        if (dp[i][j] > dp[i][k] + a[i] * b[k] * b[j] + dp[k + 1][j])
          dp[i][j] = dp[i][k] + a[i] * b[k] * b[j] + dp[k + 1][j], idx[i][j] = k;
    }
  eprintf("%d\n", dp[0][n - 1]);
  if (n > 1)
    printf("(");
  get_ans(0, n - 1);
  if (n > 1)
    printf(")");
  printf("\n");
  return 0;
}

                               