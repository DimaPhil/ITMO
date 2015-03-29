#include <bits/stdc++.h>

const int alphabet = 26;
const int maxn = 100 * 100 * 10;

int vertexCounter = 2;
int edgesCount = 0;
int go[maxn][alphabet];
int root = 1;

void addSymbol(int &v, int c) {
	if (go[v][c] == 0) {
		go[v][c] = vertexCounter++;
		edgesCount++;
	}
	v = go[v][c];
}

void addString(std::string &s, size_t l, size_t r) {
	int nowVertex = root;
	for (size_t i = l; i <= r; i++) {
		addSymbol(nowVertex, s[i] - 'a');
	}
}

int main() {
	freopen("trie.in", "r", stdin);
	freopen("trie.out", "w", stdout);
	std::string s;
	std::cin >> s;
	for (size_t i = 0; i < s.size(); i++) {
		addString(s, i, s.size() - 1);
	}

	std::cout << vertexCounter - 1 << ' ' << edgesCount << '\n';
	for (int v = 1; v < vertexCounter; v++) {
		for (int c = 0; c < alphabet; c++) {
			if (go[v][c] != 0) {
				std::cout << v << ' ' << go[v][c] << ' ' << char(c + 'a') << '\n';
			}
		}
	}
	return 0;
}
