#include <bits/stdc++.h>

const int maxn = 1e6 + 100;

char s[2][maxn];

const long long p = 239017, mod = 1e9 + 7;

long long hash[2][maxn], powers[maxn];

long long mmod(long long x) {
    return (x % mod + mod) % mod;
}

long long get(int num, int l, int r) {
    return mmod(hash[num][r + 1] - hash[num][l] * powers[r - l + 1]);
}

int findLcp(int p0, int p1, int lens, int lent) {
    if (s[0][p0] != s[1][p1])
        return 0;
    int l = 1, r = std::min(lens - p0, lent - p1) + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (hash[0][m] == get(1, p1, p1 + m - 1))
            l = m;
        else
            r = m;
    }
    return l;
}

int main() {
    freopen("search3.in", "r", stdin);
    freopen("search3.out", "w", stdout);
    gets(s[0]);
    gets(s[1]);
    int lens = strlen(s[0]);
    int lent = strlen(s[1]);
    powers[0] = 1;
    for (int i = 1; i < maxn; i++)
        powers[i] = mmod(powers[i - 1] * p);
    std::vector<int> result;
    for (int i = 0; i < 2; i++) {
        int len = strlen(s[i]);
        hash[i][0] = 0;
        for (int j = 0; j < len; j++)
            hash[i][j + 1] = mmod(hash[i][j] * p + s[i][j]);
    }
    for (int i = 0; i <= lent - lens; i++) {
        int lcp = findLcp(0, i, lens, lent);
        if (lcp >= lens - 1) {
            result.push_back(i + 1);
            continue;
        }
        if (get(1, i + lcp + 1, i + lens - 1) == get(0, lcp + 1, lens - 1)) {
            result.push_back(i + 1);
        }
    }
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); i++) {
        printf("%d%c", result[i], " \n"[i == (int)result.size() - 1]);
    }
    return 0;
}
