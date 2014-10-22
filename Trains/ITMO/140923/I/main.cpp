#define TASKNAME "text"

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
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

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

template <typename T>
T sqr(T x) {
    return x * x;
}

template <typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

struct pt {
    int x, y;
    pt() { x = y = 0; }
    pt(int x, int y) : x(x), y(y) {}

    ll len2() {
        return 1LL * x * x + 1LL * y * y;
    }
};

bool operator < (const pt &a, const pt &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
pt operator - (const pt &a, const pt &b) { return pt(a.x - b.x, a.y - b.y); }
pt operator + (const pt &a, const pt &b) { return pt(a.x + b.x, a.y + b.y); }

const int maxn = 1e5 + 10;

int n;
pt p[maxn];

ll cross_product(pt p1, pt p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

bool less_cross(pt p1, pt p2) {
    int cp = cross_product(p1, p2);
    return cp > 0 || (cp == 0 && p1.len2() < p2.len2()); 
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
      scanf("%d%d", &p[i].x, &p[i].y);
  ll answer = 0;
  for (int it = 0; it < n - 2; it++) {
      pt mn = pt(INF, INF);
      int idx = -1;
      for (int i = it; i < n; i++)
          if (p[i] < mn)
              mn = p[i], idx = i;
      swap(p[it], p[idx]);
      for (int i = it; i < n; i++)
          p[i] = p[i] - mn;
      sort(p + it + 1, p + n, &less_cross);
      pt sum;
      for (int i = it + 1; i < n; i++)
          sum = sum + p[i];  
      for (int i = it + 1; i < n; i++) {
          answer += abs(cross_product(p[i], sum - p[i]));
          sum = sum - p[i];
      }
      for (int i = it; i < n; i++)
          p[i] = p[i] - mn;
  }
  printf("%lld.%lld\n", answer / 2, answer % 2);
  return 0;
}
