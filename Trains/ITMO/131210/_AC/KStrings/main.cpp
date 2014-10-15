#define TASKNAME "strings"
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

const ll p = 239017;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int n, m;
char s[2][maxn];
ll powers[maxn], hash[2][maxn];
int len[2];

inline ll mmod(ll x)
{
  return (x % mod + mod) % mod;
}

inline ll get(int num, int l, int r)
{
  return mmod(hash[num][r + 1] - hash[num][l] * powers[r - l + 1]);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  powers[0] = 1;
  for (int i = 1; i < maxn; i++)
    powers[i] = mmod(powers[i - 1] * p);

  for (int i = 0; i < 2; i++)
  {
    gets(s[i]);
    len[i] = strlen(s[i]);
    hash[i][0] = 0;
    for (int j = 0; j < len[i]; j++)
      hash[i][j + 1] = mmod(hash[i][j] * p + s[i][j]);
  }                                          

  int q;
  scanf("%d", &q);
  for (int it = 0; it < q; it++)
  {
    int p1, p2;
    scanf("%d%d", &p1, &p2);
    --p1, --p2;
    if (s[0][p1] != s[1][p2])
    {
      printf("0\n");
      continue;
    }
    int l = 1, r = min(len[0] - p1, len[1] - p2) + 1;
    while (l < r - 1)
    {
      int m = (l + r) >> 1;
      if (get(0, p1, p1 + m - 1) == get(1, p2, p2 + m - 1))
        l = m;
      else
        r = m;
    }
    printf("%d\n", l);
  }
  return 0;
}

