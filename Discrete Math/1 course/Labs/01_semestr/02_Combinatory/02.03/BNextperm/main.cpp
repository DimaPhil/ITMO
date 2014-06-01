#define TASKNAME "nextperm"
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

int n;

inline bool prev_perm(vi &a)
{
  int pos = -1;
  for (int i = n - 2; i >= 0; i--)
    if (a[i] > a[i + 1])
    {
      pos = i;
      break;      
    }
  if (pos == -1)
    return 0;
  int idx = -1, mx = 0;
  for (int i = pos + 1; i < n; i++)
    if (mx < a[i] && a[i] < a[pos])
      idx = i, mx = a[i];
  swap(a[idx], a[pos]);
  reverse(a.begin() + pos + 1, a.end());
  return 1;
}

inline bool next_perm(vi &a)
{
  int pos = -1;
  for (int i = n - 2; i >= 0; i--)
    if (a[i] < a[i + 1])
    {
      pos = i;
      break;
    }
  if (pos == -1)
    return 0;
  int idx = -1, mn = n + 1;
  for (int i = pos + 1; i < n; i++)
    if (mn > a[i] && a[i] > a[pos])
      idx = i, mn = a[i];
  swap(a[idx], a[pos]);
  reverse(a.begin() + pos + 1, a.end());
  return 1;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  vi a(n), la(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), la[i] = a[i];
  bool pp = prev_perm(a);
  if (!pp)
    for (int i = 0; i < n; i++)
      a[i] = 0;
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], " \n"[i == n - 1]);

  for (int i = 0; i < n; i++)
    a[i] = la[i];
  bool np = next_perm(a);
  if (!np)
    for (int i = 0; i < n; i++)
      a[i] = 0;
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], " \n"[i == n - 1]);
  return 0;
}

