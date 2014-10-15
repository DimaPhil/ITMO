#define TASKNAME "vars"
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

string ss;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  map <string, int> cnt;
  while (getline(cin, ss))
  {
    int len = sz(ss);
    string s = "";
    for (int i = 0; i < len; i++)
      if (ss[i] != 32)
        s += ss[i];
    len = sz(s);
    int i = 0;  
    int vars = 0;
    while (i < len)
    {
      string name = "";
      while (i < len && (isalpha(s[i]) || isdigit(s[i]) || s[i] == '_'))
        name += s[i++];
      ++vars;
      if (s[i] == ',')
        ++i;
      else
      {
        assert(s[i] == ':');
        ++i;
        string type = "";
        while (i < len && (isalpha(s[i]) || isdigit(s[i])))
          type += s[i++];
        cnt[type] += vars;
        vars = 0;
        break;
      }
    }     
  }
  printf("boolean: %d\n", cnt["boolean"]);
  printf("char: %d\n", cnt["char"]);
  printf("double: %d\n", cnt["double"]);
  printf("integer: %d\n", cnt["integer"]);
  return 0;
}

