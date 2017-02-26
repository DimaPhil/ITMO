#include <bits/stdc++.h>

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}

  void read() {
    scanf("%d%d", &x, &y);
  }

  void print() {
    printf("%d %d\n", x, y);
  }

  pt& operator -= (const pt &p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  pt& operator += (const pt &p) {
    x += p.x;
    y += p.y;
    return *this;
  }

  long long len2() {
    return 1LL * x * x + 1LL * y * y;
  }

  double len() {
    return sqrt(len2() + 0.);
  }
};

bool operator < (const pt &a, const pt &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

pt operator - (pt a, const pt &b) {
  return a -= b;
}

pt operator + (pt a, const pt &b) {
  return a += b;
}

long long vect(pt a, pt b) {
  return a.x * 1LL * b.y - a.y * 1LL * b.x;
}

long long scal(pt a, pt b) {
  return a.x * 1LL * b.x + a.y * 1LL * b.y;
}

bool less_cmp(pt a, pt b) {
  return vect(a, b) > 0 || (vect(a, b) == 0 && a.len2() < b.len2());
}

//p in [0, i, i + 1]
bool inside(const std::vector<pt> &ngon, pt p, int i) {
  long long three_s = std::abs(vect(ngon[i], p)) + 
                      std::abs(vect(p, ngon[i + 1])) + 
                      std::abs(vect(ngon[i] - p, ngon[i + 1] - p));
  long long s = std::abs(vect(ngon[i], ngon[i + 1]));
  return s == three_s;
}

int get_type(std::vector<pt> &ngon, pt p) {
  if (vect(ngon[1], p) < 0) {
    return -1;
  }
  if (vect(ngon.back(), p) > 0) {
    return -1;
  }
  if (vect(ngon[1], p) == 0) {
    return ngon[1].len2() >= p.len2() ? 0 : -1;
  }
  if (vect(ngon.back(), p) == 0) {
    return ngon.back().len2() >= p.len2() ? 0 : -1;
  }
  size_t l = 1, r = ngon.size();
  while (l < r - 1) {
    size_t m = (l + r) / 2;
    if (vect(ngon[m], p) >= 0) {
      l = m;
    } else {
      r = m;
    }
  }
  if (vect(p - ngon[l], ngon[l + 1] - ngon[l]) == 0) {
    return 0;
  }
  return inside(ngon, p, l) ? 1 : -1;
}

int main() {
  freopen("inside.in", "r", stdin);
  freopen("inside.out", "w", stdout);
  int n;
  scanf("%d", &n);
  std::vector<pt> p(n);
  for (int i = 0; i < n; i++) {
    p[i].read();
  }
  int min_index = -1;
  for (int i = 0; i < n; i++) {
    if (min_index == -1 || p[min_index] < p[i]) {
      min_index = i;
    }
  }
  std::swap(p[0], p[min_index]);
  pt min_point = p[0];
  for (int i = 0; i < n; i++) {
    p[i] -= min_point;
  }
  std::sort(p.begin() + 1, p.end(), less_cmp);
  
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    pt x;
    x.read();
    x -= min_point;
    int type = get_type(p, x);
    puts(type < 0 ? "OUTSIDE" : (type == 0 ? "BORDER" : "INSIDE"));
  }
  return 0;
}