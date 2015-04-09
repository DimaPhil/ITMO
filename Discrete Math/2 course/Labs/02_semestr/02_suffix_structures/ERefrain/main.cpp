#include <bits/stdc++.h>

const int maxn = 4e5 + 100;
const int alphabet = 15;

int s[maxn];
int p[maxn], p0[maxn];
int cnt[maxn];
int classNum[maxn], classNum0[maxn];
int pos[maxn], lcp[maxn];

bool lesscmp(int a, int b) {
    return lcp[a] < lcp[b];
}

int main() {
    freopen("refrain.in", "r", stdin);
    freopen("refrain.out", "w", stdout);
    int n;
    scanf("%d%*d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    s[n++] = 0;
    for (int i = 0; i < std::max(alphabet, n); i++)
        cnt[i] = 0, p[i] = 0, p0[0] = 0, classNum[i] = 0, classNum0[i] = 0;
    for (int i = 0; i < n; i++) 
        ++cnt[s[i] + 1];
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i] + 1]] = i;
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
    for (int i = 0; i < n; i++)
        pos[p[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k > 0) {
            k--;
        }
        if (pos[i] == n - 1) {
            lcp[n - 1] = -1;
            k = 0;
        } else {
            int j = p[pos[i] + 1];
            while (std::max(i + k, j + k) < n && s[i + k] == s[j + k])
                ++k;
            lcp[pos[i]] = k;
        }
    }
    lcp[n - 1] = 1000000000;

    std::vector <int> ps(n - 1);
    for (int i = 0; i < n - 1; i++) {
        ps[i] = i;
    }
    std::sort(ps.begin(), ps.end(), lesscmp);
    long long maxAns = n - 1;
    int maxLen = n - 1;
    int maxIndex = 0;
    std::set<int> is;
    is.insert(0);
    is.insert(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int k = lcp[ps[i]];
        is.insert(ps[i]);
        auto l = is.lower_bound(ps[i]);
        int L = *l;
        if (l != is.begin())
            L = *(--l) + 1;
        auto r = is.lower_bound(ps[i]);
        int R = *r;
        if (++r != is.end())
            R = *r - 1;
        if (maxAns < (R - L + 2) * 1LL * k) {
            maxAns = (R - L + 2) * 1LL * k;
            maxLen = k;
            maxIndex = p[ps[i]];
        }
    }
    std::cout << maxAns << '\n';
    std::cout << maxLen << '\n';
    for (int i = maxIndex; i < maxIndex + maxLen; i++)
        std::cout << s[i] << ' ';
    std::cout << '\n';
    return 0;
}
