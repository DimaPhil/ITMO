#include <bits/stdc++.h>

const int maxn = 1e6 + 10;

char s[maxn];

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    gets(s);
    int n = strlen(s);
    std::vector <int> prefix(n, 0);
    for (int i = 1; i < n; i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[j] != s[i]) {    
            j = prefix[j - 1];
        }
        if (s[j] == s[i]) {
            ++j;
        }
        prefix[i] = j;
    }           
    for (int i = 0; i < n; i++) {
        printf("%d%c", prefix[i], " \n"[i == n - 1]);
    }
}