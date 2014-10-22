#include "buffer.h"
#include <cassert>
#include <cstdio>
#include <iostream>

/*void hand_tests()
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

  printf("Checking test 4\n");
  list d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_back(4);
  d.push_front(0);
  d.push_front(-1);
  for (list::iterator it = d.begin(); it != d.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';
  for (list::reverse_iterator it = d.rbegin(); it != d.rend(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';

  printf("Checking test 5\n");
  list e;
  e.push_back(1);
  e.push_back(4);
  e.push_back(5);
  list toInsert;
  toInsert.push_back(2);
  toInsert.push_back(3);
  list::iterator itE = e.begin();
  ++itE;
  e.splice(itE, toInsert, toInsert.begin(), toInsert.end());
  for (list::iterator it = e.begin(); it != e.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';
}

void random_tests()
{
} */

int main()
{
  //hand_tests();
  //random_tests();     
}
