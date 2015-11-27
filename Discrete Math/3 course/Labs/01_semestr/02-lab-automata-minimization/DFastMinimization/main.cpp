#include <bits/stdc++.h>

const int alphabet = 26;

void markReachable(int v, const std::vector<std::vector<int>> &go, std::vector<bool> &reachable) {
    reachable[v] = true;
    for (int c = 0; c < alphabet; c++) {
        if (!reachable[go[v][c]]) {
            markReachable(go[v][c], go, reachable);
        }
    }
}

template<typename F, typename S>
struct Pair {
    F first;
    S second;

    Pair(F first, S second) {
        this->first = first;
        this->second = second;
    }
};

int getSize(const std::unordered_set<int> &hs) {
    return (int)hs.size();
}

int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void solve() {
    int n = nextInt();
    int m = nextInt();
    int k = nextInt();
    std::vector<bool> isTerminal(n + 1, false);
    std::vector<std::vector<int>> go(n + 1, std::vector<int>(alphabet));
    std::vector<std::vector<std::vector<int>>> goRev(n + 1, std::vector<std::vector<int>>(26));
    std::vector<bool> reachable(n + 1, false);
    for (int i = 0; i < k; i++) {
        isTerminal[nextInt()] = true;
    }
    for (int i = 0; i < m; i++) {
        int v = nextInt();
        int u = nextInt();
        char c;
        scanf(" %c", &c);
        go[v][c - 'a'] = u;
    }
    n++;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < alphabet; c++) {
            goRev[go[i][c]][c].push_back(i);
        }
    }

    std::unordered_set<int> terminals;
    std::unordered_set<int> notTerminals;
    std::vector<std::unordered_set<int>> states;
    std::vector<std::unordered_set<int>> partition;
    std::vector<Pair<size_t, int>> queue;
    size_t head = 0;

    markReachable(1, go, reachable);
    std::vector<int> cs(n + 1, -1);
    std::vector<int> css(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (isTerminal[i]) {
            terminals.insert(i);
        } else {
            notTerminals.insert(i);
            css[i] = 1;
        }
    }
    states.push_back(terminals);
    states.push_back(notTerminals);
    partition.push_back(terminals);
    partition.push_back(notTerminals);
    for (int c = 0; c < alphabet; c++) {
        queue.push_back(Pair<size_t, int>(0, c));
        queue.push_back(Pair<size_t, int>(1, c));
    }
    while (head < queue.size()) {
        Pair<size_t, int> current = queue[head++];
        size_t u = current.first;
        int v = current.second;
        std::map<int, std::vector<int>> stateRev;
        for (int state : partition[u]) {
            for (int rev : goRev[state][v]) {
                stateRev[css[rev]].push_back(rev);
            }
        }
        for (auto &e : stateRev) {
            const int cls = e.first;
            const std::vector<int> &state = e.second;
            if (state.size() == 0) {
                continue;
            }
            if (state.size() < getSize(states[cls])) {
                states.push_back(std::unordered_set<int>());
                size_t endPos = states.size() - 1;
                for (int rev : stateRev[cls]) {
                    states[cls].erase(rev);
                    states[endPos].insert(rev);
                }
                if (states[endPos].size() > states[cls].size()) {
                    std::swap(states[endPos], states[cls]);
                }
                for (int rev : states[endPos]) {
                    css[rev] = (int)endPos;
                }
                partition.push_back(states[endPos]);
                for (int c = 0; c < alphabet; c++) {
                    queue.push_back(Pair<size_t, int>(partition.size() - 1, c));
                }
            }
        }
    }

    int classes = 0;
    for (auto state : states) {
        if (state.find(0) != state.end()) {
            for (int v : state) {
                cs[v] = 0;
            }
        }
        if (state.find(1) != state.end() && cs[1] == -1) {
            ++classes;
            for (int v : state) {
                cs[v] = 1;
            }
        }
    }

    for (auto state : states) {
        int v = *state.begin();
        if (!reachable[v] || cs[v] != -1) {
            continue;
        }
        ++classes;
        cs[v] = classes;
        for (int vertex : state) {
            cs[vertex] = classes;
        }
    }

    std::vector<bool> newTerminal(classes + 1, false);
    int newK = 0;
    for (int i = 0; i < n; i++) {
        if (isTerminal[i] && cs[i] != -1 && !newTerminal[cs[i]]) {
            newK++;
            newTerminal[cs[i]] = true;
        }
    }
    if (newTerminal[0]) {
        newK--;
    }
    std::vector<std::vector<int>> newGo(classes + 1, std::vector<int>(alphabet, 0));
    int newM = 0;
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < alphabet; c++) {
            int j = go[i][c];
            if (cs[i] > 0 && cs[j] > 0 && newGo[cs[i]][c] == 0) {
                newGo[cs[i]][c] = cs[j];
                newM++;
            }
        }
    }

    printf("%d %d %d\n", classes, newM, newK);
    for (int i = 1; i <= classes; i++) {
        if (newTerminal[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 1; i <= classes; i++) {
        for (int c = 0; c < alphabet; c++) {
            if (newGo[i][c] != 0) {
                printf("%d %d %c\n", i, newGo[i][c], (char)(c + 'a'));
            }
        }
    }
}

int main() {
    freopen("fastminimization.in", "r", stdin);
    freopen("fastminimization.out", "w", stdout);
    solve();
    return 0;
}