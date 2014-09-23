#include <bits/stdc++.h>

void calcKMP(std::string &s, std::vector <int> &pi) {
    size_t n = s.size();
    pi.resize(n);
    pi[0] = 0;
    for (size_t i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }            
}
