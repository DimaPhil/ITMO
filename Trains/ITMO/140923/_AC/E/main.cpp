
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
 
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pw(x) (1ll << (x))
 
using namespace std;
typedef pair<int, int> pt;
 
#define TASK "1"
 
const int maxn = (int)3e5 + 10;
 
struct FenwickTree {
    int n;
    vector <int> t;
 
    FenwickTree() { n = 0, t.clear(); }
    FenwickTree(int _n) {
        n = _n;
        t.resize(n);
    }
 
    void update(int v, int x) {
        for (int i = v; i < n; i |= (i + 1))
            t[i] += x;
    }
 
    int get(int v) {
        int res = 0;
        for (int i = v; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }
};
 
int n, m;
vector < pair <int, int> > primes;
 
void buildFactorization(int x, vector < pair <int, int> > &primes) {
    primes.clear();
    for (int i = 2; i * i <= x; i++) {
        int power = 0;
        while (!(x % i))
            ++power, x /= i;
        if (power)
            primes.push_back(make_pair(i, power));
    }
    if (x > 1)
        primes.push_back(make_pair(x, 1));
}
 
long long divisor;
vector <int> powers;
int phi;
 
long long pv(int x, int k, int m) {
    if (!k)
        return 1 % m;
    if (k & 1)
        return (1LL * pv(x, k - 1, m) * x) % m;
    int res = pv(x, k >> 1, m);
    return (1LL * res * res) % m;
}
 
long long calc() {
    long long ans = divisor;
    for (int i = 0; i < (int)primes.size(); i++) {
        ans *= pv(primes[i].first, powers[i], m);
        ans %= m;
    }
    return ans;
}
 
void mult(int x) {
    for (int i = 0; i < (int)primes.size(); i++) {
        while (x % primes[i].first == 0)
            x /= primes[i].first, ++powers[i];
    }
    divisor *= x;
    divisor %= m;
}
 
void divv(int x) {
    for (int i = 0; i < (int)primes.size(); i++) {
        while (x % primes[i].first == 0)
            x /= primes[i].first, --powers[i];
    }
    divisor *= pv(x, phi - 1, m);
    divisor %= m;
}
             
int main() {
    //assert(freopen(TASK".in", "r", stdin));
    //assert(freopen(TASK".out", "w", stdout));
    scanf("%d%d", &n, &m);
    phi = m;
    buildFactorization(m, primes);
    for (int i = 0; i < (int)primes.size(); i++) {    
        phi = phi / primes[i].first * (primes[i].first - 1);
    }
 
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
 
    divisor = 1;
    powers.resize((int)primes.size());
    long long ans = 0;
    FenwickTree tree(maxn);
    for (int i = n - 1; i >= 0; i--) {
        int sum = tree.get(a[i] - 1);
        if (sum)
            mult(sum);
        divv(tree.get(a[i]) - tree.get(a[i] - 1) + 1);
        if (sum)
            ans += calc();
        if (sum)
            divv(sum);
        ans %= m;
        tree.update(a[i], 1);
        mult(n - i);
    }
    cout << (ans + 1) % m << '\n';
    return 0;
}