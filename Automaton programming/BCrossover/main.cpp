#include <bits/stdc++.h>

int main() {
	freopen("crossover.in", "r", stdin);
	freopen("crossover.out", "w", stdout);
	int m, n;
	std::cin >> m >> n;
	std::vector<std::string> t(m);
	for (int i = 0; i < m; i++) {
		std::cin >> t[i];
	}
	std::string s;
	std::cin >> s;

	bool one = false;
	bool two = false;
	bool uniform = false;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			bool is_uniform = true;
			for (int it = 0; it < n; it++) {
				is_uniform &= (s[it] == t[i][it] || s[it] == t[j][it]);
			}		
			uniform |= is_uniform;
			for (int split = 0; split <= n; split++) {
				bool F = true;
				bool S = true;
				for (int it = 0; it < split; it++) {
					if (t[i][it] != s[it]) {
						F = false;
					}
					if (t[j][it] != s[it]) {
						S = false;
					}
					if (!F && !S) {
						break;
					}
				}
				if (!F && !S) {
					continue;
				}
				for (int it = split; it < n; it++) {
					if (t[j][it] != s[it]) {
						F = false;
					}
					if (t[i][it] != s[it]) {
						S = false;
					}
					if (!F && !S) {
						break;
					}
				}
				one |= F || S;
				if (one) {
					break;
				}
			}	
			for (int splitL = 0; splitL <= n && !two; splitL++) {
				bool F = true;
				bool S = true;
				for (int it = 0; it < splitL; it++) {
					if (t[i][it] != s[it]) {
						F = false;
					}
					if (t[j][it] != s[it]) {
						S = false;
					}
					if (!F && !S) {
						break;
					}
				}
				if (!F && !S) {
					continue;
				}
				bool FL = F;
				bool SL = S;
				for (int splitR = splitL; splitR <= n; splitR++) {
					F = FL;
					S = SL;
					for (int it = splitL; it < splitR; it++) {
						if (t[j][it] != s[it]) {
							F = false;
						}
						if (t[i][it] != s[it]) {
							S = false;
						}
						if (!F && !S) {
							break;
						}
					}
					if (!F && !S) {
						continue;
					}
					for (int it = splitR; it < n; it++) {
						if (t[i][it] != s[it]) {
							F = false;
						}
						if (t[j][it] != s[it]) {
							S = false;
						}
						if (!F && !S) {
							break;
						}
					}
					two |= F || S;
					if (two) {
						break;
					}
				}
			}
		}
	}
	std::cout << (one ? "YES" : "NO") << '\n';
	std::cout << (two ? "YES" : "NO") << '\n';
	std::cout << (uniform ? "YES" : "NO") << '\n';
	return 0;
}