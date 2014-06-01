
#define TASKNAME "movetofront"
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
  
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
  
using namespace std;
 
typedef long long ll;
 
ll rdtsc() {
  ll tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
  
struct Node;
typedef Node *pNode;
 
struct Node {
  static pNode Null;
  pNode l, r;
  int y, size, value;
 
  Node() : l(this), r(this), size(0) {}
  Node(int value) : l(Null), r(Null), y(rand()), value(value) {
    this->calc();
  }
     
  void calc() {
    size = l->size + r->size + 1;
  }
};
 
pNode Node::Null = new Node();
pNode root = Node::Null;
 
void split(pNode t, pNode &l, pNode &r, int k) {
  if (t == Node::Null) {
    l = r = Node::Null;
  } else if (t->l->size >= k) {
    split(t->l, l, t->l, k), (r = t)->calc();
  } else {
    split(t->r, t->r, r, k - t->l->size - 1), (l = t)->calc();
  }
}
 
void merge(pNode &t, pNode l, pNode r) {
  if (l == Node::Null) {
    t = r;
  } else if (r == Node::Null) {
    t = l;
  } else if (l->y < r->y) {
    merge(l->r, l->r, r), (t = l)->calc();
  } else {
    merge(r->l, l, r->l), (t = r)->calc();
  }
}
 
void pushBack(int x) {
  pNode node = new Node(x);
  merge(root, root, node);
}
 
void moveToFront(int l, int r) {
  pNode t, t1;
  split(root, t, root, r);
  split(t, t1, t, l - 1);
 
  merge(t, t, t1);
  merge(root, t, root);
}
 
void printTree(pNode node) {
  if (node == Node::Null)
    return;
  printTree(node->l);
  printf("%d ", node->value);
  printTree(node->r);
}
 
int main() {
  srand(rdtsc());
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    pushBack(i + 1);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    moveToFront(l, r);
  }
  printTree(root);
  return 0;
}   