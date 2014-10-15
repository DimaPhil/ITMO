#define TASKNAME "paradox"
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

const int maxn = 1e5 + 10;

int n;
map <string, int> m;
string get[maxn * 2];
int a[maxn], b[maxn];
char s[100];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  int counter = 0;
  vi dp(n, 0);
  vi pr(n, -1);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", s);
    string one = "";
    string two = "";
    one += s[0], one += s[1], one += s[2];
    two += s[4], two += s[5], two += s[6];
    a[i] = m.find(one) == m.end() ? counter++ : m[one];
    m[one] = a[i];
    b[i] = m.find(two) == m.end() ? counter++ : m[two];
    m[two] = b[i];
    get[a[i]] = one;
    get[b[i]] = two;
  }
  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (b[i] == a[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1, pr[i] = j;
  }
  int idx = -1;
  int mx = 0;
  for (int i = 0; i < n; i++)
    if (mx < dp[i])
      mx = dp[i], idx = i;
  vi ans;
  while (idx != -1)
  {
    ans.pb(idx);
    idx = pr[idx];
  }
  printf("%d\n", sz(ans));
  printf("%s-%s", get[a[ans[0]]].c_str(), get[b[ans[0]]].c_str());
  for (int i = 1; i < sz(ans); i++)
    printf("-%s", get[b[ans[i]]].c_str());
  puts("");
  return 0;
}

