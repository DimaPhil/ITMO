#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

int n;
int counter = 0;

inline bool check(string &s)
{
  vector <char> st;
  for (int i = 0; i < sz(s); i++)
  {
    if (s[i] == '(' || s[i] == '[')
      st.pb(s[i]);
    else
    if (s[i] == ')')
    {
      if (!sz(st) || st.back() != '(')
        return 0;
      st.pop_back();
    }
    else
    {
      if (!sz(st) || st.back() != '[')
        return 0;
      st.pop_back();
    }
  }
  return !sz(st);
}

string now;

inline void gen(int pos)
{
  if (pos == n)
  {
    if (check(now))
      printf("%s\n", now.c_str());
    return;
  }
  now += '(';
  gen(pos + 1);
  now = now.substr(0, sz(now) - 1);
  now += ')';
  gen(pos + 1);
  now = now.substr(0, sz(now) - 1);
  now += '[';
  gen(pos + 1);
  now = now.substr(0, sz(now) - 1);
  now += ']';
  gen(pos + 1);
  now = now.substr(0, sz(now) - 1);
}

int main()
{
  freopen("__out", "w", stdout);
  //n = 2;
  //gen(0);
  //n = 4;
  //gen(0);
  n = 8;
  gen(0);
}