#include "list.h"
#include <cassert>
#include <cstdio>

void hand_tests()
{
  printf("Checking test 1\n");
  list a;
  a.push_back(5);
  a.push_back(3);
  list::iterator it = a.end();
  --it;
  assert(*it == 3);

  printf("Checking test 2\n");
  list b;
  b.push_back(5);
  b.push_front(3);
  b.push_front(1);
  it = b.begin();
  assert(*it == 1);
  ++it;
  assert(*it == 3);
  ++it;
  assert(*it == 5);

  printf("Checking test 3\n");
  list c;
  c.push_back(5);
  c.insert(c.begin(), 3);
  c.insert(c.end(), 1);
  it = c.begin();
  assert(*it == 3);
  ++it;
  assert(*it == 5);
  ++it;
  assert(*it == 1);
}

void random_tests()
{
}

int main()
{
  hand_tests();
  random_tests();     
}
