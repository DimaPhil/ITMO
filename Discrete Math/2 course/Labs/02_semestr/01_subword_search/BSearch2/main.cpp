#include <bits/stdc++.h>

const int maxn = 1e6 + 10;

char t[maxn], pp[maxn];

const long long p = 239017, MOD = 1e9 + 7;

long long hash[maxn], powers[maxn];

long long mmod(long long x) {
    return (x % MOD + MOD) % MOD;
}

long long get(int l, int r) {
    return mmod(hash[r + 1] - hash[l] * powers[r - l + 1]);
}

int main() {
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    gets(pp);
    long long needHash = 0;
    int length = strlen(pp);
    for (int i = 0; i < length; i++) {
        needHash = mmod(needHash * p + pp[i]);
    }
    gets(t);
    powers[0] = 1;
    for (int i = 1; i < maxn; i++)
        powers[i] = mmod(powers[i - 1] * p);
    int n = strlen(t);
    hash[0] = 0;
    for (int i = 0; i < n; i++)
        hash[i + 1] = mmod(hash[i] * p + t[i]);
    std::vector <int> answer;
    for (int i = 0; i <= n - length; i++) {
        if (get(i, i + length - 1) == needHash) {
            answer.push_back(i + 1);
        }
    }
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < (int)answer.size(); i++) {    
        printf("%d%c", answer[i], " \n"[i == (int)answer.size() - 1]);
    }
    return 0;
}
