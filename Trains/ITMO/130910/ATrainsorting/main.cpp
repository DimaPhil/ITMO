#define TASKNAME "trainsorting"
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
pii a[maxn];
int p[maxn];
                           
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i].fst), a[i].snd = i;
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    p[i] = a[i].snd;
  vi dp1(n, 1), dp2(n, 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (p[i] > p[j] && dp1[i] < dp1[j] + 1)
        dp1[i] = dp1[j] + 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (p[i] < p[j] && dp2[i] < dp2[j] + 1)
        dp2[i] = dp2[j] + 1;
  int mx1 = 0, mx2 = 0;
  for (int i = 0; i < n; i++)
    mx1 = max(mx1, dp1[i]), mx2 = max(mx2, dp2[i]);
  printf("%d\n", max(0, mx1 + mx2 - 1));
  return 0;        
}

