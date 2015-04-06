#include <bits/stdc++.h>

const int maxn = 4e5 + 100;
const int alphabet = 30;

char s[maxn], t[maxn];
int p[maxn], p0[maxn];
int cnt[maxn];
int classNum[maxn], classNum0[maxn];
int lcp[maxn], pos[maxn];

int check(int n, int m, int len) {
    int N = strlen(s);
    for (int i = 0; i < N - 1;) {
        bool have1 = 0, have2 = 0;
        while (i < N - 1 && lcp[i] >= len) {
            have1 |= p[i] < n;
            have2 |= (p[i] > n && p[i] <= n + m);
            i++;
        }
        have1 |= p[i] < n;
        have2 |= (p[i] > n && p[i] <= n + m);
        if (have1 && have2)
            return p[i];        
        i++;
    }
    return -1;
}

int main() {
    freopen("common.in", "r", stdin);
    freopen("common.out", "w", stdout);
    gets(s);
    gets(t);
    int n = strlen(s);
    int n0 = n;
    int m = strlen(t);
    s[n++] = 'a' - 2;
    for (int i = 0; i < m; i++)
        s[n++] = t[i];
    s[n++] = 'a' - 1;
    for (int i = 0; i < std::max(alphabet, n); i++)
        cnt[i] = 0, p[i] = 0, p0[0] = 0, classNum[i] = 0, classNum0[i] = 0;
    for (int i = 0; i < n; i++) 
        ++cnt[s[i] - 'a' + 2];
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i] - 'a' + 2]] = i;
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
    /*printf("%s\n", s);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", lcp[i]);
    printf("\n");*/

    int L = 0, R = std::max(n0, m) + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (check(n0, m, M) != -1)
            L = M;
        else
            R = M;
    }
    int pos = check(n0, m, L);
    for (int i = pos; i < pos + L; i++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}
