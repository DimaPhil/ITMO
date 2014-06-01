#define TASKNAME "num2brackets2"
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
ll k;
char s[maxn];
ll dp[maxn][maxn];
ll twos[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  n = 45;
  twos[0] = 1;
  for (int i = 1; i < n; i++)
    twos[i] = (twos[i - 1] << 1ll);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = (!j ? 0 : dp[i - 1][j - 1]) + dp[i - 1][j + 1];

  vector <char> st(n + 1);
  int sz = 0;
  while (scanf("%d%I64d", &n, &k) >= 1)
  {
    int balance = 0;
    n <<= 1;
    for (int i = 0; i < n; i++)
    {
      if (k < dp[n - i - 1][balance + 1] * twos[(n - i - 1 - (balance + 1)) >> 1])
      {
        s[i] = st[sz++] = '(';
        ++balance;
        continue;
      }
      k -= dp[n - i - 1][balance + 1] * twos[(n - i - 1 - (balance + 1)) >> 1];

      ll val = ((balance && sz && st[sz - 1] == '(') ? dp[n - i - 1][balance - 1] * twos[(n - i - 1 - (balance - 1)) >> 1] : 0);
      if (k < val)
      {
        s[i] = ')';
        --sz;
        --balance;
        continue;
      }
      k -= val;

      if (k < dp[n - i - 1][balance + 1] * twos[(n - i - 1 - (balance + 1)) >> 1])
      {
        s[i] = st[sz++] = '[';
        ++balance;
        continue;
      }
      k -= dp[n - i - 1][balance + 1] * twos[(n - i - 1 - (balance + 1)) >> 1];

      s[i] = ']';
      --sz;
      --balance;
    }        
    s[n] = '\0';
    printf("%s\n", s);
    break;
  }
  return 0;
}

