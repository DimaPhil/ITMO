#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

const int maxn = 3e7 + 100;
const ll MOD = (1ll << 32);
const ll INF = (1ll << 31) - 1;
                
int n, m, k;
ll a, b, c;
ll x[maxn];

inline ll f(ll x)
{
  ll mod = (x % MOD + MOD) % MOD;
  if (mod <= INF)
    return mod;
  return mod - MOD;
}

int main()
{
  freopen("queuemin2.in", "r", stdin);
  freopen("stress.out", "w", stdout);

  cin >> n >> m >> k;
  cin >> a >> b >> c;
  for (int i = 0; i < k; i++)
    cin >> x[i];
  for (int i = k; i < n; i++)
    x[i] = f(a * x[i - 2] + b * x[i - 1] + c), assert(x[i] >= -INF - 1 && x[i] <= INF);

  ll s = 0;
  for (int i = 0; i <= n - m; i++)
  {
    ll ans = INF;
    for (int j = i; j < i + m; j++)
      ans = min(ans, x[j]);
    s += ans;
  }
  printf("%I64d\n", s);
}