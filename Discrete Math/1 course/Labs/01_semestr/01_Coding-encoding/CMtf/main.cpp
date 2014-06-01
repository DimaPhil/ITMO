#define TASKNAME "mtf"
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

const int maxn = 1010;
const int max_alphabet = 30;

char s[maxn];
int code[max_alphabet];
char symbols[max_alphabet];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  gets(s);
  int n = strlen(s);
  for (int i = 0; i < max_alphabet; i++)
    code[i] = i, symbols[i] = char(i + 'a');
  for (int i = 0; i < n; i++)
  {
    int c = s[i] - 'a';
    int now_code = code[c];
    printf("%d%c", now_code + 1, " \n"[i == n - 1]);
    char tmp = symbols[now_code];
    for (int j = now_code - 1; j >= 0; j--)
      symbols[j + 1] = symbols[j], code[symbols[j + 1] - 'a'] = j + 1;
    code[tmp - 'a'] = 0;
    symbols[0] = tmp;
  }
  return 0;
}

