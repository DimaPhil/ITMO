#define TASKNAME "huffman"
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

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vi p(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i]);
  sort(all(p));
  ll ans = 0;
  vll q;
  int i = 0, j = 0;
  for (int it = 0; it < n - 1; it++)
  {
    ll mn1 = (i < n - 1 ? p[i] + p[i + 1] : INFLONG);
    ll mn2 = (j < sz(q) - 1 ? q[j] + q[j + 1] : INFLONG);
    ll mn3 = ((j < sz(q) && i < n) ? p[i] + q[j] : INFLONG);
    ll mn = min(min(mn1, mn2), mn3);
    ans += mn;
    if (mn == mn1)
      i += 2;
    else
    if (mn == mn2)
      j += 2;
    else
      i++, j++;
    q.pb(mn);
  }
  printf("%I64d\n", ans);
  return 0;
}

