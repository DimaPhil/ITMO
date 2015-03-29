#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int P = 239017;
const int maxn = 4e5 + 10;

int hash[maxn], powers[maxn];

int mmod(int x) {
    return x;
	/*int value = x % mod + mod;
	if (value >= mod)
		value -= mod;
	return value;*/
}

int get(int l, int r) {
	return mmod(hash[r + 1] - hash[l] * powers[r - l + 1]);
}

int n;
char s[maxn];
int p[maxn];

int lcp(int p1, int p2) {
	if (s[p1] != s[p2])
		return 0;
	int l = 1, r = std::min(n - p1, n - p2) + 1;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (get(p1, p1 + m - 1) == get(p2, p2 + m - 1))
			l = m;
		else
			r = m;
	}
	return l;
}

bool lesscmp(int p1, int p2) {
	int len = lcp(p1, p2);
	return s[p1 + len] < s[p2 + len];
}

int main() {
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	powers[0] = 1;
	for (int i = 1; i < maxn; i++)
		powers[i] = mmod(powers[i - 1] * P);
	gets(s);
	n = strlen(s);
	s[n++] = '$';
	hash[0] = 0;
	for (int i = 0; i < n; i++)
		hash[i + 1] = mmod(hash[i] * P + s[i]);
	for (int i = 0; i < n; i++)
		p[i] = i;
	std::sort(p, p + n, lesscmp);
	for (int i = 1; i < n; i++)
		printf("%d%c", p[i] + 1, " \n"[i == n - 1]);
	return 0;
}
