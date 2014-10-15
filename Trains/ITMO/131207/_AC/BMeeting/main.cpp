#define TASKNAME "meeting"
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

const int maxn = 4e5 + 10;

int n;
double a[maxn];
double pref[maxn];

inline double get(int l, int r)
{
  if (l > r)
    return 0;
  return !l ? pref[r] : pref[r] - pref[l - 1];
}                            

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lf", &a[i]);
  pref[0] = a[0];
  for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + a[i];

  double min_sum = 1e18;
  double ans = -1;
  for (int i = 0; i < n; i++)
  {
    double x = a[i];
    int pos = lower_bound(a, a + n, x - 180.0) - a;
    double sum = (i - pos) * x - get(pos, i - 1);
    sum += get(0, pos - 1);
    sum += (360 - x) * max(0, pos);
    pos = upper_bound(a, a + n, x + 180) - a - 1;
    sum += get(i + 1, pos);
    sum -= x * (pos - i);
    sum -= get(pos + 1, n - 1);
    sum += (360 + x) * max(n - 1 - pos, 0);
    if (min_sum > sum)
      min_sum = sum, ans = x;
  }
  printf("%.10lf\n", ans);
  return 0;
}

