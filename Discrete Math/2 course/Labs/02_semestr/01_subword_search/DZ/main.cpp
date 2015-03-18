#include <bits/stdc++.h>

const int maxn = 1e6 + 10;

char s[maxn];

int main() {
    freopen("z.in", "r", stdin);
    freopen("z.out", "w", stdout);
    gets(s);
    int n = strlen(s);
    std::vector <int> z(n, 0);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++)
    {
        if (r > i) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
    for (int i = 1; i < n; i++) {
        printf("%d%c", z[i], " \n"[i == n - 1]);
    }
    return 0;
}