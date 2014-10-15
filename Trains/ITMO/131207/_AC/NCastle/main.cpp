#define TASKNAME "castle"
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

struct pt
{
  double x, y;
  pt() {}
  pt(double x, double y) : x(x), y(y) {}
};

inline pt operator - (const pt &a, const pt &b) {return pt(a.x - b.x, a.y - b.y);}
inline pt operator + (const pt &a, const pt &b) {return pt(a.x + b.x, a.y + b.y);}
inline pt operator * (const pt &a, double b) {return pt(a.x * b, a.y * b);}
inline pt operator / (const pt &a, double b) {return pt(a.x / b, a.y / b);}
//inline bool operator != (const double &a, const double &b) {return fabs(a - b) > EPS;}
                                            
const double None = 1e18;
pt p[10];

inline void parse(double &x, string &s)
{
  if (s[0] == '?')
    x = None;
  else
  {
    int ans = 0, sign = 0;
    int i = 0;
    if (s[i] == '-')
      sign = 1, ++i;
    for (; i < sz(s); i++)
      ans = ans * 10 + s[i] - '0';
    x = ans * (sign ? -1 : 1);
  }
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  for (int i = 0; i < 6; i++)
  {
    string s1, s2;
    cin >> s1 >> s2;
    parse(p[i].x, s1);
    parse(p[i].y, s2);
  }
  if (p[0].x != None && p[2].x != None && p[4].x != None)
  {
    puts("POSSIBLE");
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[1].x != None && p[3].x != None && p[5].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[1] + (p[5] - p[3]);
    p[2] = p[3] + (p[1] - p[5]);
    p[4] = p[5] + (p[3] - p[1]);
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }

  if (p[1].x != None && p[3].x != None && p[2].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[1] + (p[1] - p[2]);
    p[4] = p[3] + (p[3] - p[2]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[3].x != None && p[5].x != None && p[4].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[5] + (p[5] - p[4]);
    p[2] = p[3] + (p[3] - p[4]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[1].x != None && p[5].x != None && p[0].x != None)
  {
    puts("POSSIBLE");
    p[2] = p[1] + (p[1] - p[0]);
    p[4] = p[5] + (p[5] - p[0]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }

  if (p[0].x != None && p[2].x != None && p[3].x != None)
  {
    puts("POSSIBLE");
    p[4] = p[3] + (p[3] - p[2]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[0].x != None && p[2].x != None && p[5].x != None)
  {
    puts("POSSIBLE");
    p[4] = p[5] + (p[5] - p[0]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[0].x != None && p[4].x != None && p[3].x != None)
  {
    puts("POSSIBLE");
    p[2] = p[3] + (p[3] - p[4]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[0].x != None && p[4].x != None && p[1].x != None)
  {
    puts("POSSIBLE");
    p[2] = p[1] + (p[1] - p[0]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[2].x != None && p[4].x != None && p[1].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[1] + (p[1] - p[2]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[2].x != None && p[4].x != None && p[5].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[5] + (p[5] - p[4]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }

  if (p[1].x != None && p[3].x != None && p[0].x != None)
  {
    puts("POSSIBLE");
    p[2] = p[1] + (p[1] - p[0]);
    p[4] = p[3] + (p[3] - p[2]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[1].x != None && p[3].x != None && p[4].x != None)
  {
    puts("POSSIBLE");
    p[2] = p[3] + (p[3] - p[4]);
    p[0] = p[1] + (p[1] - p[2]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[1].x != None && p[5].x != None && p[2].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[1] + (p[1] - p[2]);
    p[4] = p[5] + (p[5] - p[0]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[1].x != None && p[5].x != None && p[4].x != None)
  {
    puts("POSSIBLE");
    p[0] = p[5] + (p[5] - p[4]);
    p[2] = p[1] + (p[1] - p[0]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[3].x != None && p[5].x != None && p[0].x != None)
  {
    puts("POSSIBLE");
    p[4] = p[5] + (p[5] - p[0]);
    p[2] = p[3] + (p[3] - p[4]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  if (p[3].x != None && p[5].x != None && p[2].x != None)
  {
    puts("POSSIBLE");
    p[4] = p[3] + (p[3] - p[2]);
    p[0] = p[5] + (p[5] - p[4]);
    p[1] = (p[0] + p[2]) / 2.0;
    p[3] = (p[4] + p[2]) / 2.0;
    p[5] = (p[4] + p[0]) / 2.0;
    for (int i = 0; i < 6; i++)
      printf("%.10lf %.10lf\n", p[i].x, p[i].y);
    return 0;
  }
  puts("IMPOSSIBLE");
  return 0;
}

