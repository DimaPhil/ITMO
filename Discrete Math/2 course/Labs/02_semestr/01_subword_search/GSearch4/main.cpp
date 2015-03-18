#include <bits/stdc++.h>

const int alphabet = 30;

struct node {
    node *parent, *link, *up;
    node *children[alphabet];
    node *next[alphabet];
    char toParent;
    bool isLeaf;
    std::vector <int> id;

    void cleanNode() {
        parent = 0;
        link = 0;
        up = 0;
        for (int i = 0; i < alphabet; i++) {
            children[i] = 0;
            next[i] = 0;
        }
        id.clear();
    }
};

node *root = new node();

node *getLink(node *vertex);
node *get(node *vertex, char symbol);

node *getLink(node *vertex) {
    if (vertex->link == 0) {
        if (vertex == root || vertex->parent == root) {
            vertex->link = root;
        } else {
            vertex->link = get(getLink(vertex->parent), vertex->toParent);
        }
    }
    return vertex->link;
}

node *get(node *vertex, char symbol) {
    int c = (int)symbol;
    if (vertex->next[c] == 0) {
        if (vertex->children[c] != 0) {
            vertex->next[c] = vertex->children[c];
        } else {
            vertex->next[c] = (vertex == root) ? root : get(getLink(vertex), c);
        }
    }
    return vertex->next[c];
}

node *getUp(node *vertex) {
    if (vertex->up == 0) {
        if (getLink(vertex)->isLeaf) {
            vertex->up = getLink(vertex);
        } else if (getLink(vertex) == root) {
            vertex->up = root;
        } else {
            vertex->up = getUp(getLink(vertex));
        }
    }
    return vertex->up;
}

void add(char *s, int id) {
    node *now = root;          
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        int c = s[i] - 'a';
        if (now->children[c] == 0) {
            now->children[c] = new node();
            now->children[c]->cleanNode();
            now->children[c]->parent = now;
            now->children[c]->toParent = c;
            now->children[c]->isLeaf = false;
        }
        now = now->children[c];
    }
    now->isLeaf = true;
    now->id.push_back(id);
}

const int maxn = 1e6 + 10;

char s[maxn], t[maxn];

int main() {
    freopen("search4.in", "r", stdin);
    freopen("search4.out", "w", stdout);
    root->cleanNode();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        add(s, i);
    }                
    scanf("%s", t);
    int length = strlen(t);
    std::vector <bool> ok(n, false);
    node *now = root;
    for (int i = 0; i < length; i++) {
        int c = t[i] - 'a';
        now = get(now, c);
        node *tmp = now;
        for (size_t j = 0; j < now->id.size(); j++) {
            ok[now->id[j]] = true;
        }
        now->id.clear();
        while (tmp != root) {
            node *tmp2 = getUp(tmp);
            tmp->up = root;
            tmp = tmp2;
            for (size_t j = 0; j < tmp->id.size(); j++) {
                ok[tmp->id[j]] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", ok[i] ? "YES" : "NO");
    }
}