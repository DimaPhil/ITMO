#include <bits/stdc++.h>

int main() {
	freopen("mutation.in", "r", stdin);
	freopen("mutation.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	char* s = new char[n + 1];
	char* t = new char[n + 1];
	long double p = 1. / n;
	for (int it = 0; it < m; it++) {
		scanf("%s%s", s, t);
		long double probability = 1.;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) {
				probability *= 1 - p;
			} else {
				probability *= p;
			}
		}
		printf("%.20f\n", (double)probability);5
	}
	return 0;
}