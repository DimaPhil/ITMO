#define TASKNAME "j"

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define EPS (1e-9)
#define INF (1e9)
#define INFLONG (1e18)
#define all(a) (a).begin, (a).end()
#define sz(a) (int)a.size()
#define zero(a) memset(a, 0, sizeof(a))
#define sqr(a) ((a) * (a))
#define frs first
#define scn second
#define y1 dfkljaf
#define y0 flksdjf
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <bool> vb;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <vb> vvb;
typedef pair <int, int> pi;
typedef pair <ll, ll> pll;
typedef vector <pi> vpii;
typedef vector <pll> vpll;
ll mx[1001000];
vector<int> t[1001000];
int n, arr[1000010];
bool cmp(int a, int b) {
	return t[a].size() > t[b].size();
}
int exist[1000100], next[1001000];
ll sum(int y, int a, int b) {
	ll ans = 0;
	for (int i = a; i <= b; ++i)
		ans += t[y][i];
	return ans; 
}
int main() {
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int w, a;
		scanf("%d", &w);
		for (int j = 0; j < w; ++j)
			scanf("%d", &a), t[i].pb(a);
		reverse(t[i].begin(), t[i].end());
   	}
   	for (int i = 0; i < n; ++i)
   		arr[i] = i, exist[t[i].size()] = 1;

   	sort(arr, arr + n, cmp);
   	for (int i = 1; i <= t[arr[0]].size(); ++i)
   		mx[i] = -INFLONG;
   	int last = 0;
   	int sz = t[arr[0]].size();   	
   	for (int i = 1; i <= sz; ++i) {
   		if (!exist[i])
   			continue;
   		next[i] = last;
   		last = i;
   	}
   		
   	
   	for (int len = 1; len <= sz; ++len) 
   		for (int i = 0; i < n && t[arr[i]].size() >= len; ++i) {
   			if (!exist[len]) 
   				continue;
   			mx[len] = max(mx[next[len]] + sum(arr[i], t[arr[i]].size() - len, t[arr[i]].size() - next[len] - 1), mx[len]);
   		}   	
   	ll ans = -INFLONG;
   	for (int i = 1; i <= sz; ++i)
   		ans = max(ans, mx[i]);
   	printf("%I64d", ans); 	
    return 0;
}
