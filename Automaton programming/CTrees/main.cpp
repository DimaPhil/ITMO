#include <bits/stdc++.h>

const int maxn = 4e5 + 100;

int leftSon[maxn], rightSon[maxn];
int predicate[maxn];
std::map<int, int> taken_predicates;
int newTree[maxn][3];
int newTreeSize = 0;

int dfs(int v) {
    if (leftSon[v] == -1 && rightSon[v] == -1) {
        newTree[newTreeSize][0] = predicate[v];
        newTree[newTreeSize][1] = -1;
        newTree[newTreeSize][2] = -1;
        newTreeSize++;
        return newTreeSize - 1;
    }
    if (taken_predicates.find(predicate[v]) != taken_predicates.end()) {
        if (taken_predicates[predicate[v]] == 1) {
            return dfs(rightSon[v]);
        } else {
            return dfs(leftSon[v]);
        }
    } else {
        int sz = newTreeSize;
        newTreeSize++;
        newTree[sz][0] = predicate[v];
        taken_predicates[predicate[v]] = 0;
        newTree[sz][1] = dfs(leftSon[v]);
        taken_predicates[predicate[v]] = 1;
        newTree[sz][2] = dfs(rightSon[v]);
        taken_predicates.erase(predicate[v]);
        return sz;
    }
}

int main() {
    freopen("trees.in", "r", stdin);
    freopen("trees.out", "w", stdout);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string vertexType;
        std::cin >> vertexType;
        if (vertexType == "leaf") {
            int value;
            std::cin >> value;
            leftSon[i] = -1;
            rightSon[i] = -1;
            predicate[i] = value;
        } else {
            int _predicate, left, right;
            std::cin >> _predicate >> left >> right;
            --left, --right;
            leftSon[i] = left;
            rightSon[i] = right;
            predicate[i] = _predicate; 
        }
    }
    dfs(0);
    std::cout << newTreeSize << '\n';
    for (int i = 0; i < newTreeSize; i++) {
        int* vertex = newTree[i];
        if (vertex[1] == -1 && vertex[2] == -1) {
            std::cout << "leaf " << vertex[0] << '\n';
        } else {
            std::cout << "choice " << vertex[0] << ' ' << vertex[1] + 1 << ' ' << vertex[2] + 1 << '\n';
        }
    }
    return 0;
}