#define TASKNAME "text"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
 
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

string circle, point;

string readInputString() {
    string tmp;
    cin >> tmp >> tmp;
    return tmp;
}

vector <string> getID() {
    string tmp;
    cin >> tmp;
    if (tmp == "{}")
        return vector<string>();
    tmp.erase(0, 1);
    vector <string> ans;
    if (tmp[sz(tmp) - 1] == ',') {
        tmp.erase(sz(tmp) - 1, 1);
        ans.pb(tmp);
        cin >> tmp;
        tmp.erase(sz(tmp) - 1, 1);
        ans.pb(tmp);
    } else {
        tmp.erase(sz(tmp) - 1, 1);
        ans.pb(tmp);
    }
    return ans;
}

void touch(string a) {
    printf("TOUCH %s\n", a.c_str());
    fflush(stdout);
}

void line(string a, string b) {
    printf("LINE %s %s\n", a.c_str(), b.c_str());
    fflush(stdout);
}

void intersect(string a, string b) {
    printf("INTERSECT %s %s\n", a.c_str(), b.c_str());
    fflush(stdout);
}

void tangent(string a) {
    printf("TANGENT %s\n", a.c_str());
    fflush(stdout);
    exit(0);
}

void pushBack(vector <string> &a, vector <string> b) {
    for (int i = 0; i < sz(b); i++)
        a.pb(b[i]);
}

void solve() {
    vector <string> points;
    touch(circle);
    pushBack(points, getID());
    touch(circle);
    pushBack(points, getID());

    vector <string> lines;
    line(point, points[0]);
    pushBack(lines, getID());
    line(point, points[1]);
    pushBack(lines, getID());

    vector <string> newPoints;
    intersect(lines[0], circle);
    vector <string> add = getID();
    if (sz(add) == 1) {
        tangent(lines[0]);
        exit(0);
    }
    pushBack(newPoints, add);
    intersect(lines[1], circle);
    add = getID();
    if (sz(add) == 1) {
        tangent(lines[1]);
        exit(0);
    }
    pushBack(newPoints, add);
    if (newPoints[0] != points[0])
        swap(newPoints[0], newPoints[1]);
    if (newPoints[2] != points[1])
        swap(newPoints[2], newPoints[3]);
    
    vector <string> newLines;
    line(newPoints[0], newPoints[2]);
    pushBack(newLines, getID());
    line(newPoints[1], newPoints[3]);
    pushBack(newLines, getID());
    line(newPoints[0], newPoints[3]);
    pushBack(newLines, getID());
    line(newPoints[1], newPoints[2]);
    pushBack(newLines, getID());

    vector <string> npoints;
    intersect(newLines[0], newLines[1]);
    add = getID();
    if (!sz(add))
        solve();
    pushBack(npoints, add);
    intersect(newLines[2], newLines[3]);
    pushBack(npoints, getID());
    assert(sz(npoints) == 2);

    vector <string> ls;
    line(npoints[0], npoints[1]);
    pushBack(ls, getID());

    vector <string> ansPoints;
    intersect(ls[0], circle);
    pushBack(ansPoints, getID());

    ls.clear();
    assert(sz(ansPoints));
    line(ansPoints[0], point);
    pushBack(ls, getID());
    tangent(ls[0]);
}                                  

int main()
{
  /*#ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif*/
  circle = readInputString();
  point = readInputString();
  solve();
  return 0;
}
