#define TASKNAME "nextsetpartition"
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

const int maxn = 3e5 + 100;

int n, k;
char s[maxn];
vvi a;

inline bool last(vvi &a)
{
  int p1 = 1, p2 = n;
  for (int i = 0; i < sz(a); i++)
  {
    if (sz(a[i]) > 2 || a[i][0] != p1 || a[i].back() != p2)
      return 0;
    ++p1, --p2;
  }
  return 1;
}

inline void do_less(int idx, set <pii> &nums)
{
  int length = sz(a);
  for (int i = idx; i < length; i++)
    a.pop_back();
  for (set <pii>::iterator it = nums.begin(); it != nums.end(); it++)
  {
    if (!(*it).fst)
      continue;
    vi to_add;
    to_add.pb((*it).fst);
    a.pb(to_add);
  }
}   

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int test_num = 0;
  while (scanf("%d%d\n", &n, &k) >= 1)
  {
    if (!n && !k)
      return 0;
    if (++test_num > 1)
      puts("");
    a.clear();
    a.resize(k);
    for (int i = 0; i < k; i++)
    {
      gets(s);
      int len = strlen(s);
      s[len++] = 32;
      int now = 0;
      for (int j = 0; j < len; j++)
      {
        if (isdigit(s[j]))
          now *= 10, now += s[j] - '0';
        else
          a[i].pb(now), now = 0;
      }
    }
    if (n == 1)
    {
      puts("1 1\n1");
      continue;
    }
    if (k == 1)
    {
      printf("%d 2\n", n);
      int need = (n == 2 ? 2 : n - 1);
      int N = (n == 2 ? 1 : n);
      for (int i = 1; i <= n; i++)
        if (i != need)
          printf("%d%c", i, " \n"[i == N]);
      printf("%d\n", need);
      continue;
    }
    
    if (last(a))
    {
      printf("%d %d\n", n, n);
      for (int i = 1; i <= n; i++)
        printf("%d\n", i);
      continue;
    }

    if (sz(a[k - 1]) > 2)
    {
      int x = a[k - 1][sz(a[k - 1]) - 2];
      a[k - 1][sz(a[k - 1]) - 2] = a[k - 1].back();
      a[k - 1].pop_back();
      vi to_add;
      to_add.pb(x);
      a.pb(to_add);
      printf("%d %d\n", n, sz(a));
      for (int i = 0; i < sz(a); i++)
      {
        if (!sz(a[i]))
          assert(0);
        for (int j = 0; j < sz(a[i]); j++)
          printf("%d%c", a[i][j], " \n"[j == sz(a[i]) - 1]);
      }
      continue;
    }

    set <pii> nums;
    for (int i = 0; i < sz(a[k - 1]); i++)
      nums.insert(mp(a[k - 1][i], k - 1));
    nums.insert(mp(0, k));
    for (int i = k - 2; i >= 0; i--)
    {
      set <pii>::iterator it = nums.end();
      int mx = 0, mx_set_num = 0;
      bool found = 0;
      do
      {
        --it;
        int x = (*it).fst;
        int set_num = (*it).snd;
        if (x > a[i].back())
          mx = x, mx_set_num = set_num;
        else
        if (mx)
        {
          a[i].pb(mx);
          nums.erase(mp(mx, mx_set_num));
          do_less(i + 1, nums);
          found = 1;
          break;
        }
        else
        {
          if (sz(a[i]) <= 2)
            break;
          if (x > a[i][sz(a[i]) - 2])
          {
            while (1)
            {
              --it;
              x = (*it).fst;
              if (x < a[i][sz(a[i]) - 2])
                break;
            }
            ++it;
            x = (*it).fst;
            set_num = (*it).snd;
            nums.insert(mp(a[i][sz(a[i]) - 2], i));
            a[i][sz(a[i]) - 2] = x;
            nums.insert(mp(a[i].back(), i));
            nums.erase(mp(x, set_num));
            do_less(i + 1, nums);
            a[i].pop_back();
            found = 1;
            break;
          }
          else
          {
            nums.insert(mp(a[i][sz(a[i]) - 2], i));
            a[i][sz(a[i]) - 2] = a[i].back();
            a[i].pop_back();
            do_less(i + 1, nums);
            found = 1;
            break;
          }
        }        
      }
      while (it != nums.begin());
      if (found)
        break;
      for (int j = 0; j < sz(a[i]); j++)
        nums.insert(mp(a[i][j], i));
    }

    int cnt = 0;
    for (int i = 0; i < sz(a); i++)
      if (sz(a[i]))
        ++cnt;
    printf("%d %d\n", n, cnt);
    for (int i = 0; i < sz(a); i++)
    {
      if (!sz(a[i]))
        continue;
      for (int j = 0; j < sz(a[i]); j++)
        printf("%d%c", a[i][j], " \n"[j == sz(a[i]) - 1]);
    }
  }
  return 0;
}

                  