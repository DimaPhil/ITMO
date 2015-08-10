#include "list.h"
#include <cassert>
#include <cstdio>
#include <iostream>

using std::cout;

void hand_tests()
{
    printf("Checking test 1...\n");
    list a;
    a.push_back("5");
    a.push_back("3");
    iterator it = a.end();
    --it;
    assert(*it == "3");

    printf("Checking test 2...\n");
    list b;
    b.push_back("5");
    b.push_front("3");
    b.push_front("1");
    it = b.begin();
    assert(*it == "1");
    ++it;
    assert(*it == "3");
    ++it;
    assert(*it == "5");

    printf("Checking test 3...\n");
    list c;
    c.push_back("5");
    c.insert(c.begin(), "3");
    c.insert(c.end(), "1");
    it = c.begin();
    assert(*it == "3");
    ++it;
    assert(*it == "5");
    ++it;
    assert(*it == "1");

    printf("Checking test 4\n");
    list d;
    d.push_back("1");
    d.push_back("2");
    d.push_back("3");
    d.push_back("4");
    d.push_front("0");
    d.push_front("-1");
    for (iterator it = d.begin(); it != d.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    it = d.begin();
    ++it;
    ++it;
    d.erase(it);
    d.erase(d.begin());
    for (iterator it = d.begin(); it != d.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    printf("Checking test 5\n");
    list e;
    e.push_back("1");
    e.push_back("4");
    e.push_back("5");
    list to_insert;
    to_insert.push_back("2");
    to_insert.push_back("3");
   iterator ite = e.begin();
    ++ite;
    e.splice(ite, to_insert, to_insert.begin(), to_insert.end());
    for (iterator it = e.begin(); it != e.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    e.pop_back();
    e.pop_back();
}

int main()
{
  hand_tests();
}
