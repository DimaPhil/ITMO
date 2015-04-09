#include <bits/stdc++.h>

const int maxn = 4e5 + 100;

struct Node {
    static const int alphabet = 30;

    int length;
    int link;
    int go[alphabet];

    Node() {
        length = 0;
        link = -1;
        for (int i = 0; i < alphabet; i++)
            go[i] = -1;
    }
};

char s[maxn];
Node automaton[maxn * 2 + 1];
int size, last;

int main() {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    gets(s);
    int n = strlen(s);
    size++;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        int now = size++;
        automaton[now].length = automaton[last].length + 1;
        int ptr = last;
        while (ptr != -1 && automaton[ptr].go[c] == -1) {
            automaton[ptr].go[c] = now;
            ptr = automaton[ptr].link;
        }
        if (ptr == -1) {
            automaton[now].link = 0;
        } else {
            int goptr = automaton[ptr].go[c];
            if (automaton[ptr].length == automaton[goptr].length - 1) {
                automaton[now].link = goptr;
            } else {
                int newVertex = size++;
                automaton[newVertex].length = automaton[ptr].length + 1;
                for (int j = 0; j < 30; j++)
                    automaton[newVertex].go[j] = automaton[goptr].go[j];
                automaton[newVertex].link = automaton[goptr].link;
                while (ptr != -1 && automaton[ptr].go[c] == goptr) {
                    automaton[ptr].go[c] = newVertex;
                    ptr = automaton[ptr].link;
                }
                automaton[goptr].link = newVertex;
                automaton[now].link = newVertex;
            }
        }
        last = now;
    }

    int edges = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 30; j++)
            if (automaton[i].go[j] != -1)
                ++edges;
    }
    printf("%d %d\n", size, edges);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 30; j++)
            if (automaton[i].go[j] != -1)
                printf("%d %d %c\n", i + 1, automaton[i].go[j] + 1, char(j + 'a'));
    }
    int ptr = last;
    std::vector<int> terminal;
    while (ptr != -1) {
        terminal.push_back(ptr + 1);
        ptr = automaton[ptr].link;
    }
    printf("%d\n", (int)terminal.size());
    std::sort(terminal.begin(), terminal.end());
    for (size_t i = 0; i != terminal.size(); ++i) {
        printf("%d%c", terminal[i], " \n"[i + 1 == terminal.size()]);
    }
}                          