/*Shovkoplyas Grigory in the house*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

#define name "brackets2num"

int main()
{
  freopen(name".in", "r", stdin);
  freopen(name".out", "w", stdout);
  long long k = 0;
  string s;
  cin >> s;
  vector<vector<long long> > d;
  d.assign(s.size() + 1, vector<long long>(s.size() / 2 + 1, 0));
  d[0][0] = 1;
  for(int i = 0; i < (int)s.size(); i++)
  {
    for(int j = 0; j <= (int)s.size() / 2; j++)
    {
      if(j + 1 <= (int)s.size() / 2)
        d[i + 1][j + 1] += d[i][j];
      if(j - 1 >= 0)
        d[i + 1][j - 1] += d[i][j]; 
    }
  }
  int l = 0;
  for(int i = 0; i < (int)s.size(); i++)
  {  
    if(s[i] == '(')
      l++;
    else
    {
      if(l + 1 <= (int)s.size())
        k += d[s.size() - i - 1][l + 1];
      l--;
    }
  }
  cout << k << endl;
  return 0;
}

