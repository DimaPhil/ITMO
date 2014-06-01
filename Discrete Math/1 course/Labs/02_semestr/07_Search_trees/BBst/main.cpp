#define TASKNAME "bst"
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
 
#define red true
#define black false
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
const int None = -2e9;

struct Node;
typedef Node *pNode;

struct Node
{
  static pNode Null;
  pNode l, r, p;
  bool color;
  int value;

  Node() : l(this), r(this), p(this) {}
  Node(int value) : l(Null), r(Null), p(Null), color(red), value(value) {}
};

pNode Node::Null = new Node();
pNode root = Node::Null;

pNode find(int number) {
  pNode nowVertex = root;
  while (nowVertex != Node::Null) {
    if (nowVertex->value == number) 
      return nowVertex;
    if (nowVertex->value < number)
      nowVertex = nowVertex->r;
    else
      nowVertex = nowVertex->l;
  }
  return Node::Null;
}

pNode findMax(pNode root) {
  pNode nowVertex = root;
  while (nowVertex->r != Node::Null)
    nowVertex = nowVertex->r;
  return nowVertex;
}

int findMaxValue(pNode root) {
  pNode maxVertex = findMax(root);
  return maxVertex == Node::Null ? None : maxVertex->value;
}

void updateParent(pNode parent, int value, pNode newVertex) {
  if (parent->value < value)
    parent->r = newVertex;
  else
    parent->l = newVertex;
}

bool exists(int number) {
  return find(number) != Node::Null;
}

void changeRoot() {
  root->color = black;
}

bool isLeftSon(pNode v) {
  return v->value < v->p->value;
}

pNode brother(pNode v) {
  if (isLeftSon(v))
    return v->p->r;
  return v->p->l;
}

void leftRotate(pNode v) {
  pNode tmp = v->l;
  v->l = v->p;
  v->p = v->p->p;

  tmp->p = v->l;
  v->l->r = tmp;
  v->l->p = v;
}

void rightRotate(pNode v) {
  pNode tmp = v->r;
  v->r = v->p;
  v->p = v->p->p;
  
  tmp->p = v->r;
  v->r->l = tmp;
  v->r->p = v;
}

bool isRoot(pNode v) {
  return v != Node::Null && v->value == root->value;
}

void insert(int number) {
  if (exists(number))
    return;
  if (root == Node::Null) {
    root = new Node(number);
    return;
  }
  pNode nowVertex = root, parent = Node::Null;
  while (nowVertex != Node::Null) {
    parent = nowVertex;
    if (nowVertex->value < number)
      nowVertex = nowVertex->r;
    else
      nowVertex = nowVertex->l;
  }
  pNode newVertex = new Node(number);
  newVertex->p = parent;
  updateParent(parent, newVertex->value, newVertex);
  while (parent != Node::Null && parent->color == red) {
    pNode uncleVertex = brother(parent);
    if (uncleVertex != Node::Null && uncleVertex->color == red) {
      parent->color = black;
      uncleVertex->color = black;
      parent->p->color = red;
      newVertex = parent->p;
      parent = parent->p->p;
    } else {
      if (isLeftSon(parent)) {
        if (!isLeftSon(newVertex)) {
          parent->p->l = newVertex;
          leftRotate(newVertex);
          newVertex = parent;
          parent = parent->p;
        }  

        pNode tmp = parent->r;
        parent->r = parent->p;
        parent->p = parent->p->p;
        parent->color = black;

        if (tmp != Node::Null)
          tmp->p = parent->r;
        parent->r->l = tmp;
        parent->r->p = parent;
        parent->r->color = red;
        if (parent->p != Node::Null)
          updateParent(parent->p, parent->value, parent);
        else
          root = parent;
      } else {
        if (isLeftSon(newVertex)) {
          parent->p->r = newVertex;
          rightRotate(newVertex);
          newVertex = parent;
          parent = parent->p;
        }

        pNode tmp = parent->l;
        parent->l = parent->p;
        parent->p = parent->p->p;
        parent->color = black;
  
        if (tmp != Node::Null)
          tmp->p = parent->l;
        parent->l->r = tmp;
        parent->l->p = parent;
        parent->l->color = red;
        if (parent->p != Node::Null)
          updateParent(parent->p, parent->value, parent);
        else
          root = parent;
      }
      return;
    } 
  } 
}

void leftRotate2(pNode x) {
    pNode y = x->r;

    x->r = y->l;
    if (y->l != Node::Null)
      y->l->p = x;

    if (y != Node::Null) y->p = x->p;
    if (x->p != Node::Null) {
        if (x == x->p->l)
            x->p->l = y;
        else
            x->p->r = y;
    } else {
        root = y;
    }

    y->l = x;
    if (x != Node::Null) x->p = y;
}

void rightRotate2(pNode x) {
    pNode y = x->l;

    x->l = y->r;
    if (y->r != Node::Null) y->r->p = x;

    if (y != Node::Null) y->p = x->p;
    if (x->p != Node::Null) {
        if (x == x->p->r)
            x->p->r = y;
        else
            x->p->l = y;
    } else {
        root = y;
    }  

    y->r = x;
    if (x != Node::Null) x->p = y;
}

void deleteVertex(int number) {
  pNode position = find(number);
  if (position == Node::Null)
    return;
  pNode x, y;
  if (position->l == Node::Null || position->r == Node::Null)
    y = position;
  else {
    y = position->r;
    while (y->l != Node::Null)
      y = y->l;
  }

  if (y->l == Node::Null)
    x = y->r;
  else
    x = y->l;

  x->p = y->p;
  if (y->p != Node::Null) {
    if (y == y->p->l)
      y->p->l = x;
    else
      y->p->r = x;
    //updateParent(y->p, y->value, x);
  }
  else
    root = x;

  if (position != y)
    position->value = y->value;

  if (y->color == black) {
    while (x != root && x->color == black) {
      if (isLeftSon(x)) {
        pNode w = x->p->r;
        if (w->color == red) {
          w->color = black;
          x->p->color = red;
          leftRotate2(x->p);
          w = x->p->r;
        }
        if (w->l->color == black && w->r->color == black) {
          w->color = red;
          x = x->p;
        } else {
          if (w->r->color == black) {
            w->l->color = black;
            w->color = red;
            rightRotate2(w);
            w = x->p->r;
          }
          w->color = x->p->color;
          x->p->color = black;
          w->r->color = black;
          leftRotate2(x->p);
          x = root;
        } 
      } else {
        pNode w = x->p->l;
        if (w->color == red) {
          w->color = black;
          x->p->color = red;
          rightRotate2(x->p);
          w = x->p->l;
        }
        if (w->r->color == black && w->l->color == black) {
          w->color = red;
          x = x->p;
        } else {
          if (w->l->color == black) {
            w->r->color = black;
            w->color = red;
            leftRotate2(w);
            w = x->p->l;
          }
          w->color = x->p->color;
          x->p->color = black;
          w->l->color = black;
          rightRotate2(x->p);
          x = root;
        }
      }
    }
    x->color = black;
  } 

  delete y;
}

pNode next(int number) {
  pNode nowVertex = root, parent = Node::Null;
  while (nowVertex != Node::Null) {
    if (nowVertex->value > number) {
      parent = nowVertex;
      nowVertex = nowVertex->l;
    } else {
      nowVertex = nowVertex->r;
    }
  }
  return parent;
}

int nextValue(int number) {
  pNode nextVertex = next(number);
  return nextVertex == Node::Null ? None : nextVertex->value;
}

pNode prev(int number) {
  pNode nowVertex = root, parent = Node::Null;
  while (nowVertex != Node::Null) {
    if (nowVertex->value < number) {
      parent = nowVertex;
      nowVertex = nowVertex->r;
    } else {
      nowVertex = nowVertex->l;
    }
  }
  return parent;
}

int prevValue(int number) {
  pNode prevVertex = prev(number);
  return prevVertex == Node::Null ? None : prevVertex->value;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  char s[20];
  int number;
  while (scanf("%s%d", s, &number) >= 1) {
    if (!strcmp(s, "insert"))
      insert(number);
    if (!strcmp(s, "delete"))
      deleteVertex(number);
    if (!strcmp(s, "exists"))
      printf("%s\n", exists(number) ? "true" : "false");
    if (!strcmp(s, "next")) {
      int nextNumber = nextValue(number);
      if (nextNumber == None)
        printf("none\n");
      else
        printf("%d\n", nextNumber);
    }
    if (!strcmp(s, "prev")) {
      int prevNumber = prevValue(number);
      if (prevNumber == None)
        printf("none\n");
      else
        printf("%d\n", prevNumber);
    }
    changeRoot();
  }
  return 0;
}
