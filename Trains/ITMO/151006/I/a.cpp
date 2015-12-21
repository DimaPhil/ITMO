#include <bits/stdc++.h>
#define node nnnode
using namespace std;

struct node {
    node(int i) : l(0), r(0) {
        x = i;
        y = rand();
        p = this;
        size = 1;
        reversed = 0;
        cycled = 0;
    }
    node* l;
    node* r;
    node* p;
    int x, y;
    int size;
    bool reversed;
    bool cycled;
};

node* to[200001];
int n, m, k;


void upd(node* v) {
    if (v == NULL) return ;
    if (v->reversed) {
        swap(v->l, v->r);
        if (v->l) v->l->reversed ^= 1;
        if (v->r) v->r->reversed ^= 1;
        v->reversed = 0;
    }
    int l = v->l ? v->l->size : 0;
    int r = v->r ? v->r->size : 0;
    v->size = l + r + 1;
}

node* unite(node* a, node* b) {
    upd(a);
    upd(b);
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->y > b->y) {
        a->r = unite(a->r, b);
        if (a->r) {
            a->r->p = a;
        }
        upd(a);
        return a;
    } else {
        b->l = unite(a, b->l);
        if (b->l) {
            b->l->p = b;
        }
        upd(b);
        return b;
    }
}

void split(node* v, node* &lt, node* &rt, int pos) {
    if (v == NULL) {
        return void(lt = rt = NULL);
    }
    upd(v);
    int l_size = v->l ? v->l->size : 0;
    if (l_size >= pos) {
        split(v->l, lt, rt, pos);
        v->l = rt;
        if (rt) rt->p = v;
        rt = v;
    } else {
        split(v->r, lt, rt, pos - l_size - 1);
        v->r = lt;
        if (lt) lt->p = v;
        lt = v;
    }
    if (lt) lt->p = lt;
    if (rt) rt->p = rt;
    upd(v);
}

void inv(node* v) {
    if (v == NULL) return;
    v->reversed ^= 1;
}

void get_pos0(node* v) {
    if (v->p == v) {
        upd(v);
        return;
    }
    get_pos0(v->p);
    upd(v);
}

int get_pos(node* v, node* from, node* &root) {
    if (v->p == v) {
        root = v;
        return (v->r == from && from) ? (v->l ? (v->l)->size : 0) + 1 : 0;
    }

    if (from && v->r == from) {
        return get_pos(v->p, v, root) + (v->l ? (v->l)->size : 0) + 1;
    }
    return get_pos(v->p, v, root);

}

void add_edge(node* a, node* b) {
    node* root_a, *root_b;
    get_pos0(a);
    get_pos0(b);
    int pos_a = get_pos(a, NULL, root_a)+(a->l ? a->l->size : 0);
    int pos_b = get_pos(b, NULL, root_b)+(b->l ? b->l->size : 0);
    if (root_a == root_b) {
        root_a->cycled = 1;
        return;
    }
    if (pos_a == 0)
        inv(a);
    if (pos_b != 0)
        inv(b);
    unite(a, b);
}

void remove_edge(node* a, node*b) {
    node* root_a, *root_b;
    get_pos0(a);
    get_pos0(b);
    int pos_a = get_pos(a, NULL, root_a)+(a->l ? a->l->size : 0);
    int pos_b = get_pos(b, NULL, root_b)+(b->l ? b->l->size : 0);
    if (root_a != root_b) {
        return;
    }
    if (pos_a > pos_b) {
        swap(a, b);
        swap(pos_a, pos_b);
        swap(root_a, root_b);
    }
    if (root_a->cycled) {
        root_a->cycled = false;
        if (pos_a == 0 && pos_b == root_a->size - 1) return;
        node *la, *ra;
        split(root_a, la, ra, pos_a+1);
        inv(la), inv(ra);
        unite(la, ra);
    } else {
        node *la, *ra;
        split(root_a, la, ra, pos_a + 1);
    }
}

/*void print(node* v, int d) {
    if (v == NULL) return;
    upd(v);
    print(v->l,d+1);
    for (int i = 0; i < d; ++i)
        cerr << "  ";
    cerr << v->x << "\n";
    print(v->r, d+1);
}*/


int find_ans(node* a, node* b) {
    node* root_a, *root_b;
    get_pos0(a);
    get_pos0(b);
    int pos_a = get_pos(a, NULL, root_a)+(a->l ? a->l->size : 0);
    int pos_b = get_pos(b, NULL, root_b)+(b->l ? b->l->size : 0);
    if (root_a != root_b) {
        return -1;
    }
    int ans = abs(pos_a - pos_b)-1;
    if (root_a->cycled)
        ans = min(ans, root_a->size - abs(pos_a - pos_b) - 1);

    return ans;
}



int main() {
    //srand(time(NULL));
    /*node* v[10];
    for (int i = 0; i < 10; ++i)
        v[i] = new node(i);
    node* root = v[0];
    for (int i = 1; i < 10; ++i) {
        root = unite(root, v[i]);
    }
    print(root, 0);
    cerr << "\n===\n";
    cerr << "!" << v[3]->p->x << "\n";
return 0;
    node* r1, *r2;
    split(root, r1, r2, 5);
    print(r1, 0);
    cerr << "\n";
    print(r2, 0);
    cerr << "\n===\n";
    node* tmp;
    cerr << v[3]->p->x;// << "\n" << get_pos(v[3], NULL, tmp);
return 0;*/
    freopen("roads.in", "r", stdin);
    freopen("roads.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        to[i] = new node(i);
    }

for (int it = 0; it < m; ++it) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        add_edge(to[a], to[b]);
    }
    scanf("\n");
    for (int i = 0; i < k; ++i) {
        char c;
        int a, b;
        scanf("%c %d%d\n", &c, &a, &b);
        a--,b--;
        if (c == '?') printf("%d\n", (a == b ? 0 : find_ans(to[a], to[b])));
        if (c == '+') add_edge(to[a], to[b]);
        if (c == '-') remove_edge(to[a], to[b]);
    }
    return 0;
}


