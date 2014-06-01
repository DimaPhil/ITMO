#define TASKNAME "bwt"
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

const int maxn = 1010;
const ll P = 1e9 + 7;

int n;
char s[maxn];
char shifts[maxn][maxn];
ll powers[maxn];
ll hashes[maxn][maxn];
int p[maxn];

inline ll get(int i, int l, int r)
{
  return hashes[i][r + 1] - hashes[i][l] * powers[r - l + 1];
}

inline bool Less(int a, int b)
{
  if (shifts[a][0] != shifts[b][0])
    return shifts[a][0] < shifts[b][0];
  int l = 1, r = n + 1;
  while (l < r - 1)
  {
    int m = (l + r) >> 1;
    if (get(a, 0, m - 1) == get(b, 0, m - 1))
      l = m;
    else
      r = m;
  }
  if (l == n)
    return 0;
  return shifts[a][l] < shifts[b][l];
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  powers[0] = 1;
  for (int i = 1; i < maxn; i++)
    powers[i] = powers[i - 1] * P;

  gets(s);
  n = strlen(s);
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
      shifts[i][j - i] = s[j];
    for (int j = 0; j < i; j++)
      shifts[i][j + n - i] = s[j];
    hashes[i][0] = 0;
    for (int j = 0; j < n; j++)
      hashes[i][j + 1] = hashes[i][j] * P + shifts[i][j];
  }
  for (int i = 0; i < n; i++)
    p[i] = i;
  sort(p, p + n, Less);
  for (int i = 0; i < n; i++)
    printf("%c", shifts[p[i]][n - 1]);
  printf("\n");
  //eprintf("%.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  return 0;
}

