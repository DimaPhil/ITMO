#include <bits/stdc++.h>

const int maxn = 4e5 + 100;
const int alphabet = 30;

char s[maxn];
int p[maxn], p0[maxn];
int cnt[maxn];
int classNum[maxn], classNum0[maxn];
std::string stmp;

bool lesscmp(int i, int j) {
	return stmp.substr(i, stmp.size() - 1) < stmp.substr(j, stmp.size() - 1);
}

std::vector <int> slow(char *s, int n) {
	stmp = (std::string)s;
	std::vector <int> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i;
	std::sort(p.begin(), p.end(), lesscmp);
	return p;
}

void genRandom(char *s) {
	int n = rand() % 10 + 1;
	for (int i = 0; i < n; i++)
		s[i] = rand() % 26 + 'a';
	s[n] = 0;
}

int main() {
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	//srand(239017);
	//int testc = 0;
	//for (;;) {
	//	++testc;
	//	std::cerr << testc << std::endl;
	gets(s);
	//genRandom(s);
	int n = strlen(s);
	s[n++] = 'a' - 1;
	for (int i = 0; i < std::max(alphabet, n); i++)
		cnt[i] = 0, p[i] = 0, p0[0] = 0, classNum[i] = 0, classNum0[i] = 0;
	for (int i = 0; i < n; i++) 
		++cnt[s[i] - 'a' + 1];
	for (int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i] - 'a' + 1]] = i;
	classNum[p[0]] = 0;
	int classesCount = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]])
			++classesCount;
		classNum[p[i]] = classesCount - 1;
	}
	for (int len = 1; len < n; len <<= 1) {
		for (int i = 0; i < n; i++) {
			p0[i] = (p[i] - len + n) % n;
		}
		for (int i = 0; i < classesCount; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++)
			++cnt[classNum[p0[i]]];
		for (int i = 1; i < classesCount; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[classNum[p0[i]]]] = p0[i];
		classNum0[p[0]] = 0;
		classesCount = 1;
		for (int i = 1; i < n; i++) {
			if (classNum[p[i]] != classNum[p[i - 1]] || classNum[(p[i] + len) % n] != classNum[(p[i - 1] + len) % n])
				++classesCount;
			classNum0[p[i]] = classesCount - 1;
		}
		for (int i = 0; i < n; i++)
			classNum[i] = classNum0[i];
	}
	//printf("%s\n", s);
	//std::vector<int> res = slow(s, n);
	for (int i = 1; i < n; i++)
		printf("%d%c", p[i] + 1, " \n"[i == n - 1]);
	//for (int i = 0; i < n; i++)
	//	printf("%d%c", res[i] + 1, " \n"[i == n - 1]);
	//fflush(stdout);
	//for (int i = 0; i < n; i++)
	//	assert(p[i] == res[i]);
	//}
	return 0;
}
