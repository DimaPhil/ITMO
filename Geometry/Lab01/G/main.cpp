#include <bits/stdc++.h>

struct point {
    int x, y;

    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}

    point& operator -= (const point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
};

point operator - (point a, const point &b) {
    return a -= b;
}

int sign(long long x) {
    return x > 0 ? 1 : (x == 0 ? 0 : -1);
}

struct segment {
    point l, r;
    int index;

    segment() : index(0) {}
    segment(const point &l, const point &r, int index) : l(l), r(r), index(index) {}

    std::pair<int, int> gety(int x) const {
        if (l.x == r.x) {
            return std::make_pair(l.y, 1);
        }
        return std::make_pair(l.y * (r.x - l.x) + (r.y - l.y) * (x - l.x), (r.x - l.x));
    }

    bool operator < (const segment &s) const {
        int x = std::max(std::min(l.x, r.x), std::min(s.l.x, s.r.x));
        std::pair<int, int> a = gety(x);
        std::pair<int, int> b = s.gety(x);
        long long diff = a.first * 1LL * b.second - a.second * 1LL * b.first;
        long long mul = a.second * 1LL * b.second;
        return sign(diff) * sign(mul) < 0;
    }
};

bool has_intersection_line(int l1, int r1, int l2, int r2) {
    if (l1 > r1)
        std::swap(l1, r1);
    if (l2 > r2)
        std::swap(l2, r2);
    return std::max(l1, l2) <= std::min(r1, r2);
}

int sign_cross(const point &a, const point &b, const point &c) {
    point ab = b - a;
    point ac = c - a;
    int s = ab.x * ac.y - ab.y * ac.x;
    return s == 0 ? 0 : (s > 0 ? 1 : -1);
}

bool intersect(const segment &s1, const segment &s2) {
    return has_intersection_line(s1.l.x, s1.r.x, s2.l.x, s2.r.x) &&
           has_intersection_line(s1.l.y, s1.r.y, s2.l.y, s2.r.y) &&
           sign_cross(s1.l, s1.r, s2.l) * sign_cross(s1.l, s1.r, s2.r) <= 0 &&
           sign_cross(s2.l, s2.r, s1.l) * sign_cross(s2.l, s2.r, s1.r) <= 0;
}

struct event {
    int x;
    int type;
    int index;

    event() : x(0), type(0), index(0) {}
    event(int x, int type, int index) : x(x), type(type), index(index) {}

    bool operator < (const event &e) const {
        if (x != e.x) return x < e.x;
        return type > e.type;
    }
};

std::set<segment>::iterator next(std::set<segment> &segments, std::set<segment>::iterator it) {
    return ++it;
}

std::set<segment>::iterator previous(std::set<segment> &segments, std::set<segment>::iterator it) {
    return it == segments.begin() ? segments.end() : --it;
}

int main() {
    //freopen("segments.in", "r", stdin);
    //freopen("segments.out", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<segment> segs;
    std::vector<event> events;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        segs.push_back(segment(point(x1, y1), point(x2, y2), i));
        //events.emplace_back(std::min(segs[i].l.x, segs[i].r.x), 1, i);
        //events.emplace_back(std::max(segs[i].l.x, segs[i].r.x), -1, i);
        events.push_back(event(std::min(segs[i].l.x, segs[i].r.x), 1, i));
        events.push_back(event(std::max(segs[i].l.x, segs[i].r.x), -1, i));
    }
    std::sort(events.begin(), events.end());

    std::set<segment> segments;
    std::vector<std::set<segment>::iterator> where(segs.size());
    std::pair<int, int> answer = std::make_pair(-1, -1);
    for (size_t i = 0; i < events.size(); i++) {
        int index = events[i].index;
        if (events[i].type == 1) {
            auto it = segments.lower_bound(segs[index]);
            auto it_prev = previous(segments, it);
            if (it != segments.end() && intersect(*it, segs[index])) {
                answer = std::make_pair(it->index, index);
                break;
            }
            if (it_prev != segments.end() && intersect(*it_prev, segs[index])) {
                answer = std::make_pair(it_prev->index, index);
                break;
            }
            where[index] = segments.insert(it, segs[index]);
        } else {
            auto it = next(segments, where[index]);
            auto it_prev = previous(segments, where[index]);
            if (it != segments.end() && it_prev != segments.end() && intersect(*it, *it_prev)) {
                answer = std::make_pair(it_prev->index, it->index);
                break;
            }
            segments.erase(where[index]);
        }
    }
    if (answer != std::make_pair(-1, -1)) {
        printf("YES\n");
        if (!intersect(segs[answer.first], segs[answer.second])) {
            while (1) {}
        }
        printf("%d %d\n", answer.first + 1, answer.second + 1);
    } else {
        printf("NO\n");
    }
    return 0;
}