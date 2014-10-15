#define TASKNAME "square"
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

int a[3], b[3];

inline void yes()
{
  puts("YES");
  exit(0);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  for (int i = 0; i < 3; i++)
    scanf("%d%d", &a[i], &b[i]);
  if (a[0] + a[1] + a[2] == b[0] && b[0] == b[1] && b[1] == b[2])
    yes();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
        continue;
      int other = -1;
      for (int k = 0; k < 3; k++)
        if (k != i && k != j)
          other = k;
      if (a[i] + a[j] == a[other] && a[i] + a[j] == b[other] + b[i] && b[i] == b[j])
        yes();
    }
  if (b[0] + b[1] + b[2] == a[0] && a[0] == a[1] && a[1] == a[2])
    yes();
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
        continue;
      int other = -1;
      for (int k = 0; k < 3; k++)
        if (k != i && k != j)
          other = k;
      if (b[i] + b[j] == b[other] && b[i] + b[j] == a[other] + a[i] && a[i] == a[j])
        yes();
    }
  puts("NO");
  return 0;                                                            
}


