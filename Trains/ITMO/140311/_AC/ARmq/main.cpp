#define TASKNAME "rmq"
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

ll rdtsc()
{
  ll tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

struct node;
typedef node *pnode;

struct node
{
  static pnode Null;
  pnode l, r;
  int y, value, size, min_value;

  node() : l(this), r(this), size(0), min_value(INF) {}
  node(int value) : l(Null), r(Null), y(rand()), value(value)
  {
    this->calc();
  }

  inline void calc()
  {
    size = l->size + r->size + 1;
    min_value = min(min(l->min_value, r->min_value), value);
  }
};

pnode node::Null = new node();

inline void split(pnode t, pnode &l, pnode &r, int k)
{
  if (t == node::Null)
    l = r = node::Null;
  else
  if (t->l->size >= k)
    split(t->l, l, t->l, k), (r = t)->calc();
  else
    split(t->r, t->r, r, k - t->l->size - 1), (l = t)->calc();
}

inline void merge(pnode &t, pnode l, pnode r)
{
  if (l == node::Null)
    t = r;
  else
  if (r == node::Null)
    t = l;
  else
  if (l->y < r->y)
    merge(l->r, l->r, r), (t = l)->calc();
  else                          
    merge(r->l, l, r->l), (t = r)->calc();
}

pnode root = node::Null;

inline void add_after(int pos, int x)
{
  pnode t, t1;
  split(root, t, t1, pos);
  pnode Node = new node(x);
  merge(t, t, Node);
  merge(root, t, t1);
}

inline void push_back(int x)
{
  pnode Node = new node(x);
  merge(root, root, Node);
}

inline int get_min(int l, int r)
{
  pnode t, t1;
  split(root, t, root, r);
  split(t, t1, t, l - 1);

  int ans = t->min_value;

  merge(t, t1, t);
  merge(root, t, root);
  return ans;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  srand(rdtsc());
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    char c;
    int l, r;
    scanf(" %c%d%d", &c, &l, &r);
    assert(c == '+' || c == '?');
    if (c == '+')
      add_after(l, r);
    else
      printf("%d\n", get_min(l, r));
  }
  return 0;
}