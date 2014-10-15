#define TASKNAME "xo"
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

const int maxn = 200;

int n;
char s[maxn];
int len[maxn];
char a[maxn][maxn];
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

inline void incorrect()
{
  puts("INCORRECT");
  exit(0);
}

inline void correct()
{
  puts("CORRECT");
  exit(0);
}

map <pii, bool> was[maxn][maxn];

inline vector <vpii> find_fives(char c)
{
  vector <vpii> fives;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < len[i]; j++)
      for (int it = 0; it < 8; it++)
      {
        int nx = i, ny = j;
        vpii five;
        while (nx >= 0 && nx < n && ny >= 0 && ny < len[nx] && a[nx][ny] == c)
        {
          nx += dx[it];
          ny += dy[it];
        }
        nx -= dx[it];
        ny -= dy[it];
        int lnx = nx, lny = ny;
        while (nx >= 0 && nx < n && ny >= 0 && ny < len[nx] && a[nx][ny] == c)
        {
          five.pb(mp(nx, ny));
          nx -= dx[it];
          ny -= dy[it];
        }
        nx += dx[it];
        ny += dy[it];
        if (sz(five) >= 10)
          incorrect();
        if (sz(five) >= 5 && !was[nx][ny][mp(-dx[it], -dy[it])] && !was[lnx][lny][mp(dx[it], dy[it])])
        {
          fives.pb(five);
          was[nx][ny][mp(-dx[it], -dy[it])] = 1;
          was[lnx][lny][mp(dx[it], dy[it])] = 1;
        }
      }
  return fives;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  map <char, int> cnt;
  n = 0;
  while (gets(s))
  {
    len[n] = strlen(s);
    for (int i = 0; i < len[n]; i++)
      a[n][i] = s[i], ++cnt[s[i]];
    ++n;                     
  }
  if (cnt['X'] == cnt['O'])
  {
    //turn X
    vector < vpii > all_fives = find_fives('X');
    if (sz(all_fives))
      incorrect();
    all_fives = find_fives('O');
    if (!sz(all_fives))
      correct();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < len[i]; j++)
        if (a[i][j] == 'O')
        {
          a[i][j] = '.';
          all_fives = find_fives('O');
          if (!sz(all_fives))
            correct();
          a[i][j] = 'O';
        }
    incorrect();
  }
  else
  if (cnt['X'] == cnt['O'] + 1)
  {
    //turn O
    vector < vpii > all_fives = find_fives('O');
    if (sz(all_fives))                     
      incorrect();
    all_fives = find_fives('X');
    if (!sz(all_fives))
      correct();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < len[i]; j++)
        if (a[i][j] == 'X')
        {
          a[i][j] = '.';
          all_fives = find_fives('X');
          if (!sz(all_fives))
            correct();
          a[i][j] = 'X';
        }
    incorrect();
  }
  else
    incorrect();
  correct();
  return 0;
}

