#define TASKNAME "bestcomb"
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

const int maxn = 2e3 + 100;

int n, m;
int a[maxn][maxn];
int lastzero[maxn][maxn];
int lz[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
  {
    int j = 0;
    while (j < m)
    {
      if (a[i][j])
        lastzero[i][j] = -1, ++j;
      else
      {
        int j0 = j;
        while (j < m && !a[i][j])
          ++j;
        for (int k = j0; k < j; k++)
          lastzero[i][k] = j - 1;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      lz[j][i] = lastzero[i][j];

  int max_ans = 0;
  for (int i = 0; i < m; i++)
  {
    int j = 0;
    while (j < n)
    {
      int ans = 0;
      while (j < n)
      {
        int last = lastzero[j][i];
        if (last == -1)
        {
          ++j;
          break;
        }
        ans += last - i + 1;
        ++j;
      }        
      if (ans > max_ans)
        max_ans = ans;
    }
  }
  printf("%d\n", max_ans);
  return 0;
}

