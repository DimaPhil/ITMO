#define TASKNAME "binsearch"
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

int firstIndex(vi &a, int x) {
  int l = 0, r = sz(a);
  while (l < r - 1) {
    int m = (l + r) >> 1;
    if (a[m] < x)
      l = m;
    else
      r = m;
  }
  return l + 1;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vi a(n + 2);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  a[0] = -1;
  a[n + 1] = 2147483647;

  int q, x;
  scanf("%d", &q);
  for (int it = 0; it < q; it++) {
    scanf("%d", &x);
    int leftIndex = firstIndex(a, x);
    int rightIndex = firstIndex(a, x + 1) - 1;
    if (a[leftIndex] != x)
      printf("-1 -1\n");
    else
      printf("%d %d\n", leftIndex, rightIndex);
  }
  return 0;
}

