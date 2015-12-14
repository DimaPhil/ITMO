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

int sign(long long x) {
  return x < 0 ? -1 : (x == 0 ? 0 : 1);
}

bool intersect(pt L, pt R, pt l, pt r) {
  long long a, b, c;

  int ok = 0;
  a = R.y - L.y;
  b = L.x - R.x;
  c = -L.x * 1LL * a - L.y * 1LL * b;
  if (sign(a * 1LL * l.x + b * 1LL * l.y + c) != sign(a * 1LL * r.x + b * 1LL * r.y + c) && 
      sign(a * 1LL * r.x + b * 1LL * r.y + c) != 0) {
    ok++;
  }
  a = r.y - l.y;
  b = l.x - r.x;
  c = -l.x * 1LL * a - l.y * 1LL * b;
  if (sign(a * 1LL * L.x + b * 1LL * L.y + c) != sign(a * 1LL * R.x + b * 1LL * R.y + c)) {
    ok++;
  }
  return ok == 2;
}

int main() {
  freopen("point.in", "r", stdin);
  freopen("point.out", "w", stdout);
  int n;
  scanf("%d", &n);
  pt x;
  x.read();
  std::vector<pt> p(n);
  for (int i = 0; i < n; i++) {
    p[i].read();
  }
  for (int i = 0; i < n; i++) {
    if (vect(x - p[i], p[(i + 1) % n] - p[i]) == 0 && 
        scal(x - p[i], p[(i + 1) % n] - p[i]) >= 0 && 
        scal(x - p[(i + 1) % n], p[i] - p[(i + 1) % n]) >= 0) {
      puts("YES");
      return 0;
    }
  }
  pt L = x;
  pt R = pt((int)2e9, L.y);
  int intersections = 0;
  for (int i = 0; i < n; i++) {
    pt l = p[i];
    pt r = p[(i + 1) % n];
    if (l.y == r.y) {
      continue;
    }
    if (l.y > r.y) {
      std::swap(l.x, r.x);
      std::swap(l.y, r.y);
    }
    if (intersect(L, R, l, r)) {
      intersections++;
    }
  }
  puts((intersections & 1) ? "YES" : "NO");
  return 0;
}