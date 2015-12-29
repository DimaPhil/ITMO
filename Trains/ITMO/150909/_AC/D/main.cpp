#include <bits/stdc++.h>

const std::string letters = "IVXLCDM";

int cost[] = {1, 5, 10, 50, 100, 500, 1000};

int find(char c) {
    return std::find(letters.begin(), letters.end(), c) - letters.begin();
}

bool go(std::vector<int> &ans, const std::vector<int> &cnt, int pos, int now) {
    if (pos == -1) {
        return now == 0;
    }
    for (int i = 0; i <= cnt[pos]; i++) {   
        if (go(ans, cnt, pos - 1, now - (cnt[pos] - i) * cost[pos])) {
            ans[pos] = cnt[pos] - i;
            return true;
        }
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> cnt(letters.size());
    for (size_t i = 0; i < s.size(); i++) {
        cnt[find(s[i])]++;
    }
    int S = 0;
    for (size_t i = 0; i < letters.size(); i++) {
        S += cost[i] * cnt[i];
    }
    int r = n + S;
    if (r % 2 == 1) {
        printf("NO\n");
        return 0;
    }
    r >>= 1;
    int max = 100;
    for (size_t i = letters.size() - 1; i >= 0; i--) {
        if (cnt[i] > 0) {
            max = i;
            break;
        }
    }
    r -= cnt[max] * cost[max];

    std::vector<int> ans(10);
    if (!go(ans, cnt, max - 1, r)) {
        printf("NO\n");
        return 0;
    }
    for (int i = max - 1; i >= 0; i--) {
        for (int j = 0; j < cnt[i] - ans[i]; j++) {
            std::cout << letters[i];
        }
    }
    for (int i = 0; i < cnt[max]; i++) {
        std::cout << letters[max];
    }
    for (int i = max - 1; i >= 0; i--) {
        for (int j = 0; j < ans[i]; j++) {
            std::cout << letters[i];
        }
    }
    std::cout << '\n';
    return 0;
}