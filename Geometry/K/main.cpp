#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

int sign(long long value) {
    return value < 0 ? -1 : (value == 0 ? 0 : 1);
}

struct point {
  int x, y, a, b, c;
  
  point() {}
  point(int x, int y) : x(x), y(y) {}

  inline void read() {
    scanf("%d%d", &x, &y);
  }
  
  bool operator < (point p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
  
  point& operator += (const point &p) {
    x += p.x;
    y += p.y;
    return *this;
  }
  
  long long len2() {
    return x * 1LL * x + y * 1LL * y;
  }
  
  point& operator -= (const point &p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  int where(point p)
  {
    long long value = a * 1LL * p.x + b * 1LL * p.y + c;
    return sign(value);
  }
};

long long operator * (point a, point b) {
    return a.x * 1LL * b.y - a.y * 1LL * b.x;
}

long long operator ^ (point a, point b) {
    return a.x * 1LL * b.x + a.y * 1LL * b.y;
}

point operator + (point a, point b) {
    return a += b;
}

point operator - (point a, point b) {
    return a -= b;
}

bool lesscmp(point a, point b) {
  long long v = a * b;
  return v > 0 || (v == 0 && a.len2() < b.len2());
}

void build(std::vector<point>& ps, std::vector<point>& hull) {
  int n = ps.size();
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (ps[i] < ps[id]) {
      id = i;
    }
  }
  point minp = ps[id];
  for (int i = 0; i < n; i++) {
    ps[i] -= minp;
  }
  std::sort(ps.begin(), ps.end(), lesscmp);
  hull.push_back(ps[0]);
  for (int i = 1; i < n; i++) {
    while (hull.size() > 1 && (hull.back() - hull[hull.size() - 2]) * (ps[i] - hull.back()) <= 0) {
        hull.pop_back();
    }
    hull.push_back(ps[i]);
  }
  for (size_t i = 0; i < hull.size(); i++) {
    hull[i] += minp;
  }
}

std::vector<point> ps, v, road;
int n, psz;
std::vector<bool> pay;

double angle(point s, point t) {
  long long cp = s * t;
  long long sp = s ^ t;
  if (cp == 0 && sp > 0) {
    return 0.0;
  }
  if (cp == 0 && sp < 0) {
    return M_PI;
  }
  double len = sqrt(s.x * s.x * 1.0 + s.y * s.y * 1.0) * sqrt(t.x * t.x * 1.0 + t.y * t.y * 1.0);
  if (cp > 0) {
    return acos(sp / len);
  }
  return 2 * M_PI - acos(sp / len);
}

int find_change_sign(int l, int r, point p) {
  int mid;
  if (l > r) {
    r += psz;
  }
  int sg = sign(p * (ps[l + 1] - ps[l]));
  while (l < r - 1)
  {
    mid = (l + r) / 2;
    if (sg == sign(p * (ps[mid + 1] - ps[mid]))) {
        l = mid;
    } else {
        r = mid;
    }
  }
  if (r >= psz) {
    r -= psz;
  }
  return r;
}

bool inside(point p) {
  if (psz == 1) {
    return p.where(ps[0]) == 0;
  }
  if (psz == 2) {
    return p.where(ps[0]) * p.where(ps[1]) <= 0;
  }
  int l = 0, r = psz, mid, sgn = sign(p * (ps[1] - ps[0]));
  int it;
  for (it = 0; it < 100; it++) {
    mid = (l + r) / 2;
    point p2 = ps[mid + 1] - ps[mid];
    point p1 = ps[l + 1] - ps[l];
    if (sgn != sign(p * p2)) {
        break;
    }
    if (angle(p, p1) < angle(p, p2)) {
        l = mid;
    } else {
        r = mid;
    }
  }
  if (it == 100) {
    return true;
  }
  int p1 = find_change_sign(l, mid, p);
  int p2 = find_change_sign(mid, l, p);
  return p.where(ps[p1]) * p.where(ps[p2]) <= 0;
}

int main()
{
  freopen("highways.in", "r", stdin);
  freopen("highways.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  road.resize(n);
  pay.resize(n);
  for (int i = 0; i < n; i++) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    road[i] = point(B, -A);
    road[i].a = A;
    road[i].b = B;
    road[i].c = C;
  }
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].read();
  }
  build(v, ps);
  size_t l = ps.size();
  psz = ps.size();
  for (size_t i = 0; i < l; i++) {
    ps.push_back(ps[i]);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (inside(road[i]))
    {
      pay[i] = true;
      cnt++;
    }
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    if (pay[i]) {
        printf("%d ", i + 1);
    }
  }
  return 0;
}