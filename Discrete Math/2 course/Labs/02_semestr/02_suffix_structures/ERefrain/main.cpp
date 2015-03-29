#include <bits/stdc++.h>

const int maxn = 2e5 + 10;
const int alphabet = 15;
            
struct Node {
	int l, r, parent, link;
	int go[alphabet];

	Node() {
		l = r = parent = link = -1;
		for (int i = 0; i < alphabet; i++)
			go[i] = -1;
	}
	
	Node(int l, int r, int parent) : l(l), r(r), parent(parent), link(-1) {
		for (int i = 0; i < alphabet; i++)
			go[i] = -1;
	}
	
	int len() {
		return r - l;
	}
};

struct Position {
	int v, l;
	Position() {}
	Position(int v, int l) : v(v), l(l) {}
};

int s[maxn * 2];
int treeSize, szs;
Node tree[maxn * 2 + 10];
Node root;

int addToParent(int l, int r, int parent) {
  int newIndex = treeSize++;
  tree[newIndex] = Node(l, r, parent);
  return tree[parent].go[s[l]] = newIndex;
}

int splitToEdge(Position pos) {
  int v = pos.v;

  int up = pos.l;
  int down = tree[v].len() - up;
  if (up == 0)
    return v;
  if (down == 0)
    return tree[v].parent;
  int middle = addToParent(tree[v].l, tree[v].l + down, tree[v].parent);
  tree[v].l += down;
  tree[v].parent = middle;
  tree[middle].go[s[tree[v].l]] = v;
  return middle;
}

Position readChar(Position pos, char c) {
  int v =  pos.v, up = pos.l;
  if (up != 0)
    return s[tree[v].r - up] == c ? Position(v, up - 1) : Position(-1, -1);
  bool found = 0;
  found = tree[v].go[c] != -1;
  int w = found ? tree[v].go[c] : -1;
  return (w != -1) ? Position(w, tree[w].len() - 1) : Position(-1, -1);
}

Position goDownFast(int v, int l, int r) {
  if (l == r)            
    return Position(v, 0);
  while (1) {
    v = tree[v].go[s[l]];
    if (tree[v].len() >= r - l)
      return Position(v, tree[v].len() - r + l);
    else
      l += tree[v].len();
  }
}

int getLink(int v)
{
  if (tree[v].link != -1)
    return tree[v].link;
  if (tree[v].parent == -1)
    return 0;
  int to = getLink(tree[v].parent);
  return tree[v].link = splitToEdge(goDownFast(to, tree[v].l + (tree[v].parent == 0), tree[v].r));
}

Position addChar(Position pos, int i) {
  while (true) {
    Position newPosition = readChar(pos, s[i]);
    if (newPosition.v != -1)
      return newPosition;
    int middle = splitToEdge(pos);
    addToParent(i, szs, middle);
    int link = getLink(middle);
    pos = Position(link, 0);
    if (middle == 0)
      return pos;
  }
}

int main() {
    freopen("refrain.in", "r", stdin);
    freopen("refrain.out", "w", stdout);
	root.link = 0;
	tree[treeSize++] = root;
	Position pos = Position(0, 0);
	int n;
	scanf("%d%*d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
    szs = n;
	for (int i = 0; i < szs; i++)
		pos = addChar(pos, i);
	
	return 0;
}
