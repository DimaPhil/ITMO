#define TASKNAME "sort"
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

void qSort(vi &a, int l, int r) {
  if (l >= r)
    return;
  int x = a[l + rand() % (r - l + 1)];
  int i = l, j = r;
  do {
    while (a[i] < x)
      ++i;
    while (a[j] > x)
      --j;
    if (i <= j)
      swap(a[i++], a[j--]);
  } while (i <= j);
  qSort(a, l, j);
  qSort(a, i, r);
}

int main()
{
  srand(239017);
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vi a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  qSort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], " \n"[i == n - 1]);
  return 0;
}

