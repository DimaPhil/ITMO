#define TASKNAME "queue2"
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
#define INFLONG ((long long)(1e18))
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

struct element;
typedef element *pelement;

struct element
{
  static pelement Null;
  pelement next;
  int value;

  element() : next(this) {}
  element(int value) : next(Null), value(value) {}
};

pelement head, tail;

pelement element::Null = new element();

inline int pop()
{
  int ans = head->value;
  head = head->next;
  if (head == element::Null)
    tail = element::Null;
  return ans;
}

inline void push(int x)
{
  pelement elem = new element(x);
  if (tail != element::Null)
    tail->next = elem;
  else
    head = elem;
  tail = elem;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int q;
  scanf("%d", &q);

  head = element::Null, tail = element::Null;
  for (int i = 0; i < q; i++)
  {
    char c;
    scanf(" %c", &c);
    if (c == '-')
      printf("%d\n", pop());
    else
    {
      int x;
      scanf("%d", &x);
      push(x);
    }
  }
  return 0;
}
