#define TASKNAME "radixsort"
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
const int alphSize = 26;

int n, m, k;
char s[maxn][maxn], t[maxn][maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);

  int ind = m - 1;
  for (int it = 0; it < k; it++, ind--) {
    vi cnt(alphSize, 0);
    for (int i = 0; i < n; i++)
      ++cnt[s[i][ind] - 'a'];
    vi pref(alphSize, 0);
    for (int i = 1; i < alphSize; i++)
      pref[i] = pref[i - 1] + cnt[i - 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        t[pref[s[i][ind] - 'a']][j] = s[i][j];
      ++pref[s[i][ind] - 'a'];
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        s[i][j] = t[i][j];
  } 
  for (int i = 0; i < n; i++)
    printf("%s\n", s[i]);
  return 0;       
}

