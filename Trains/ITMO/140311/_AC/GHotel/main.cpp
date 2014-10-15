#define TASKNAME "hotel"
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

int n, q;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  int x;
  multiset <pii> s;
  vi fr(n, 0);
  vi get(100000, -1);
  vi w(100000, 0);
  for (int i = 0; i < n; i++)
    scanf("%d", &x), fr[i] = x, s.insert(mp(x, i));

  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    int x;
    scanf("%d", &x);
    if (x > 0)
    {
      multiset <pii>::iterator it = s.lower_bound(mp(x, -1));
      if (it == s.end())
      {
        printf("-1\n");
        continue;
      }
      pii fs = *it;
      printf("%d\n", fs.snd + 1);
      fr[fs.snd] -= x;
      s.erase(s.find(mp(fs.fst, fs.snd)));
      get[i] = fs.snd;
      w[i] = x;
      s.insert(mp(fs.fst - x, fs.snd));
    }
    else
    {
      x = -x;
      x -= 4;
      if (x >= 100000)
      { 
        puts("-1");
        continue;
      }
      int num = get[x];
      printf("%d\n", num == -1 ? -1 : num + 1);
      if (num == -1)
        continue;
      s.erase(s.find(mp(fr[num], num)));
      s.insert(mp(fr[num] + w[x], num));
      fr[num] += w[x]; 
      get[x] = -1;
    }
  }
  return 0;
}

