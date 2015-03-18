#include <bits/stdc++.h>

const int maxn = 1e6 + 10;

char s[maxn];

const long long p = 239017, MOD = 1e9 + 7;

long long hash[maxn], powers[maxn];

long long mmod(long long x) {
    return (x % MOD + MOD) % MOD;
}

long long get(int l, int r) {
    return mmod(hash[r + 1] - hash[l] * powers[r - l + 1]);
}

int main() {
    freopen("period.in", "r", stdin);
    freopen("period.out", "w", stdout);
    gets(s);
    powers[0] = 1;
    for (int i = 1; i < maxn; i++)
        powers[i] = mmod(powers[i - 1] * p);
    int n = strlen(s);
    hash[0] = 0;
    for (int i = 0; i < n; i++)
        hash[i + 1] = mmod(hash[i] * p + s[i]);
    for (int len = 1; len <= n; len++) {
        if (n % len) continue;
        bool ok = true;
        for (int j = 0; j < n; j += len) {
            if (get(j, j + len - 1) != get(0, len - 1))
                ok = false;
        }
        if (ok) {
            printf("%d\n", len);
            return 0;
        }
    }
    return 0;
}
