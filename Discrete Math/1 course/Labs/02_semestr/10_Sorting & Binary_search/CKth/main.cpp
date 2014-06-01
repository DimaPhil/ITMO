#define TASKNAME "kth"
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
  
int qSort(vi &a, int l, int r, int k) {
  if (l > r)
    return 0;
  if (l == r)
    return a[l];
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
 
  if (l <= k && k <= j)
    return qSort(a, l, j, k);
  if (i <= k && k <= r)
    return qSort(a, i, r, k);
  return x;
}
  
int main()
{
  srand(239017);
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, k;
  scanf("%d%d", &n, &k);
  --k;
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  vi a(n);
  scanf("%d%d", &a[0], &a[1]);
  for (int i = 2; i < n; i++)
    a[i] = A * a[i - 2] + B * a[i - 1] + C;
  int answer = qSort(a, 0, n - 1, k);
  printf("%d\n", answer);
  return 0;
}