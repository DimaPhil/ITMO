#define TASKNAME "smallnim"
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

const int maxn = 1e5 + 10;

int n;
int a[maxn];
bool win[maxn][2];
int take[maxn][2];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a + n);
  int i = 0;
  int turn = 0;
  while (i < n && a[i] == 1)
    ++i, turn = 1 - turn;
  if (i == n)
  {
    if (!turn)
      printf("YES\n1\n");
    else
      printf("NO\n");
    return 0;
  }
  int f = i;
  win[n][0] = win[n][1] = 1;
  for (int i = n - 1; i >= f; i--)
    for (int turn = 0; turn < 2; turn++)
    {
      if (win[i + 1][1 - turn])
      {
        win[i][turn] = 1;
        take[i][turn] = a[i] - 1;
      }
      else
      {
        win[i][turn] = 1;
        take[i][turn] = a[i];
      }
    }
  if (!turn)
  {
    printf("YES\n");
    printf("%d\n", take[f][turn]);
  }
  else
    printf("NO");
  return 0;
}

