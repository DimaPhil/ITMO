#include <bits/stdc++.h>

const char *tags[] = {"&lt;", "&gt;", "&amp;", "&apos;", "&quot;"};

bool find(const std::string &s, char c) {
    return std::find(s.begin(), s.end(), c) != s.end();
}

int substring_count(const std::string &s, const std::string &substring) {
    int result = 0;
    for (size_t i = 0; i <= s.size() - substring.size(); i++) {
        if (s.substr(i, substring.size()) == substring) {
            result++;
        }
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::string s;
    std::getline(std::cin, s);
    /*if (find(s, '>') || find(s, '<') || find(s, '\'') || find(s, '\"')) {
        printf("0\n");
        return 0;
    } */
    int answer = (int)1e9;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != '&') {
            if (s[i] == '>' || s[i] == '<' || s[i] == '\'' || s[i] == '\"') {
                printf("0\n");
                exit(0);
            }
            continue;
        }
        i++;
        int group = 0;
        while (i + 3 < s.size() && s.substr(i, 4) == "amp;") {
            i += 4;
            group++;
        }
        if (i + 2 < s.size() && s.substr(i, 3) == "lt;") {
            group++;
        }
        if (i + 2 < s.size() && s.substr(i, 3) == "gt;") {
            group++;
        }
        if (i + 4 < s.size() && s.substr(i, 5) == "apos;") {
            group++;
        }
        if (i + 4 < s.size() && s.substr(i, 5) == "quot;") {
            group++;
        }
        answer = std::min(answer, group);
    }
    std::cout << (answer == (int)1e9 ? -1 : answer) << '\n';
    return 0;
}