#define TASKNAME "bstsimple"
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
  
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
  
using namespace std;
  
const int None = -2e9;
 
struct vertex;
typedef vertex *pvertex;
 
struct vertex
{
  static pvertex Null;
  pvertex l, r, p;
  int value;
 
  vertex() : l(this), r(this), p(this) {}
  vertex(int value) : l(Null), r(Null), p(Null), value(value) {}
};
 
pvertex vertex::Null = new vertex();
pvertex root = vertex::Null;
 
pvertex find(int number) {
  pvertex nowVertex = root;
  while (nowVertex != vertex::Null) {
    if (nowVertex->value == number) 
      return nowVertex;
    if (nowVertex->value < number)
      nowVertex = nowVertex->r;
    else
      nowVertex = nowVertex->l;
  }
  return vertex::Null;
}
 
pvertex findMax(pvertex root) {
  pvertex nowVertex = root;
  while (nowVertex->r != vertex::Null)
    nowVertex = nowVertex->r;
  return nowVertex;
}
 
int findMaxValue(pvertex root) {
  pvertex maxVertex = findMax(root);
  return maxVertex == vertex::Null ? None : maxVertex->value;
}
 
void updateParent(pvertex parent, int value, pvertex newVertex) {
  if (parent->value < value)
    parent->r = newVertex;
  else
    parent->l = newVertex;
}
 
bool exists(int number) {
  return find(number) != vertex::Null;
}
 
void insert(int number) {
  if (exists(number))
    return;
  if (root == vertex::Null) {
    root = new vertex(number);
    return;
  }
  pvertex nowVertex = root, parent = vertex::Null;
  while (nowVertex != vertex::Null) {
    parent = nowVertex;
    if (nowVertex->value < number)
      nowVertex = nowVertex->r;
    else
      nowVertex = nowVertex->l;
  }
  pvertex newVertex = new vertex(number);
  newVertex->p = parent;
  updateParent(parent, newVertex->value, newVertex);
}
 
void deleteVertex(int number) {
  pvertex position = find(number);
  if (position == vertex::Null)
    return;
  if (position->l == vertex::Null && position->r == vertex::Null) {
    if (position->p == vertex::Null) {
      root = vertex::Null;
      delete position;
      return;
    }
    updateParent(position->p, position->value, vertex::Null);
    delete position;
    return;
  }
  if (position->l == vertex::Null) {
    if (position->p != vertex::Null)
      updateParent(position->p, position->r->value, position->r);
    else
      root = position->r;
    position->r->p = position->p;
    delete position;
    return;
  }
  pvertex maxVertex = findMax(position->l);
  position->value = maxVertex->value;
  if (maxVertex->l != vertex::Null)
    maxVertex->l->p = maxVertex->p;
  updateParent(maxVertex->p, maxVertex->value, maxVertex->l);
  delete maxVertex;
}
 
pvertex next(int number) {
  pvertex nowVertex = root, parent = vertex::Null;
  while (nowVertex != vertex::Null) {
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
  pvertex nextVertex = next(number);
  return nextVertex == vertex::Null ? None : nextVertex->value;
}
 
pvertex prev(int number) {
  pvertex nowVertex = root, parent = vertex::Null;
  while (nowVertex != vertex::Null) {
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
  pvertex prevVertex = prev(number);
  return prevVertex == vertex::Null ? None : prevVertex->value;
}
 
void printTree(pvertex root) {
  if (root == vertex::Null)
    return;
  printf("V: %d\n", root->value);
  printf("L: \n");
  printTree(root->l);
  printf("R: \n");
  printTree(root->r);
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
  }
  return 0;
}