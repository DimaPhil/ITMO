#define TASKNAME "absmarkchain"
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

int n, m;


int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  int loops = 0;
  vb loop(n, 0);
  vi v(m), u(m);
  vector <double> p(m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%lf", &v[i], &u[i], &p[i]);
    --v[i], --u[i];
    if (v[i] == u[i] && fabs(p[i] - 1) <= EPS)
      loop[v[i]] = 1, ++loops;
  }
  int bad_moves = 0;
  int good_moves = 0;
  vi pos(n);
  for (int i = 0; i < n; i++)
  {
    if (loop[i])
      pos[i] = good_moves++;
    else
      pos[i] = bad_moves++;
  }

  vector < vector <double> > goR(n + 10, vector <double>(n + 10));
  vector < vector <double> > goQ(n + 10, vector <double>(n + 10));
  for (int i = 0; i < m; i++)
  {
    if (loop[u[i]] && !loop[v[i]])
      goR[pos[v[i]]][pos[u[i]]] = p[i];
    else
    if (!loop[u[i]])
      goQ[pos[v[i]]][pos[u[i]]] = p[i];
  }

  /*printf("goR:\n");
  for (int i = 0; i < n; i++, printf("\n"))
    for (int j = 0; j < n; j++)
      printf("%.5lf ", goR[i][j]);
  printf("\ngoQ:\n");
  for (int i = 0; i < n; i++, printf("\n"))
    for (int j = 0; j < n; j++)
      printf("%.5lf ", goQ[i][j]);
  printf("\n");*/
  
  vector < vector <double> > E(n + 10, vector <double>(n + 10));
  vector < vector <double> > diff(n + 10, vector <double>(n + 10));
  for (int i = 0; i < n - loops; i++)
  {
    E[i][i] = 1;
    diff[i][i] = 1;
    for (int j = 0; j < n - loops; j++)
      diff[i][j] -= goQ[i][j];
  }    

  for (int i = 0; i < n - loops; i++)
  {
    if (fabs(diff[i][i] - 1) > EPS)
    {
      double d = diff[i][i];
      for (int j = 0; j < n - loops; j++)
        diff[i][j] /= d, E[i][j] /= d; 
    }
    for (int j = 0; j < n - loops; j++)
      if (i != j)
      {
        double d = diff[j][i];
        for (int k = 0; k < n - loops; k++)
        {
          diff[j][k] -= d * diff[i][k];
          E[j][k] -= d * E[i][k];
        }
      }
  }

  vector < vector <double> > mul(n + 10, vector <double>(n + 10));
  for (int i = 0; i < n - loops; i++)
    for (int j = 0; j < loops; j++)
    {
      mul[i][j] = 0;
      for (int k = 0; k < n - loops; k++)
        mul[i][j] += E[i][k] * goR[k][j];
    }
  for (int i = 0; i < n; i++)
  {
    double ans = 0;
    if (loop[i])
    {
      for (int j = 0; j < n - loops; j++)
        ans += mul[j][pos[i]];
      ans = (ans + 1) / n; 
    }
    printf("%.20lf\n", ans);
  }
  return 0;
}

