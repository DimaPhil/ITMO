#define TASKNAME "chess"
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

const int maxn = 20;

int n;
char a[maxn][maxn];
char s[100];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d\n", &n);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      a[i][j] = '.';
  for (int i = 0; i < 8; i++)
    a[i][1] = 'P', a[i][6] = 'p';
  a[0][0] = 'R';
  a[0][7] = 'r';
  a[1][0] = 'N';
  a[1][7] = 'n';
  a[2][0] = 'B';
  a[2][7] = 'b';
  a[3][0] = 'Q';
  a[3][7] = 'q';
  a[4][0] = 'K';
  a[4][7] = 'k';
  a[5][0] = 'B';
  a[5][7] = 'b';
  a[6][0] = 'N';
  a[6][7] = 'n';
  a[7][0] = 'R';
  a[7][7] = 'r';
       
  for (int i = 0; i < n; i++)
  {
    gets(s);
    int len = strlen(s);
    if (s[0] == '0')
    {
      if (len == 3)
      {
        if (!(i & 1))
          a[5][0] = 'R', a[6][0] = 'K', a[7][0] = '.', a[4][0] = '.';
        else
          a[5][7] = 'r', a[6][7] = 'k', a[7][7] = '.', a[4][7] = '.';
      }
      else
      {
        if (!(i & 1))
          a[3][0] = 'R', a[2][0] = 'K', a[4][0] = '.', a[0][0] = '.';
        else
          a[3][7] = 'r', a[2][7] = 'k', a[4][7] = '.', a[0][7] = '.';
      }
      continue;
    }
    int lx = s[1] - 'a';
    int ly = s[2] - '1';
    int nx = s[4] - 'a';
    int ny = s[5] - '1';
    a[nx][ny] = a[lx][ly];
    a[lx][ly] = '.';
    if (len == 7)
    {
      a[nx][ny] = s[6];
      if (toupper(s[0]) == s[0])
        a[nx][ny] = toupper(a[nx][ny]);
      else
        a[nx][ny] = tolower(a[nx][ny]);
    }
  }
  for (int i = 0; i < 8; i++, printf("\n"))
    for (int j = 0; j < 8; j++)
      printf("%c", a[j][7 - i]);
  return 0;
}

