#define TASKNAME "snakesandladders"
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

const int maxn = 2e7 + 100;

int a, b, c;
int p[maxn];
int go[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 0; i <= 100; i++)
    go[i] = i;
  for (int i = 0; i < b; i++)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    //go[r] = l;
    go[l] = r;
  }
  for (int i = 0; i < a; i++)
    p[i] = 1;
  int now = 0;
  for (int i = 0; i < c; i++)
  {
    int x;
    scanf("%d", &x);
    p[now] += x;
    if (p[now] >= 100)
    {
      p[now] = 100;
      break;
    }
    p[now] = go[p[now]];
    if (++now == a)
      now = 0;
  }
  for (int i = 0; i < a; i++)
    printf("Position of player %d is %d.\n", i + 1, p[i]);
  return 0;
}
