#ifndef SET_H
#define SET_H

#include <iostream>

struct set 
{
  struct iterator;
  //struct const_iterator;
    
  set();
  set(set const& other);
  ~set();
  set& operator = (set const& other);

  size_t size() const;
  bool empty() const;

  iterator begin() const;
  iterator end() const;

  iterator find(int value) const;
  iterator insert(int value) const;
  iterator erase(iterator pos) const;

private:
  struct node;
  node *root;
};

struct set::node 
{
  int value;
  node *l, *r, *p;
   
  node();
  node(int value);
  node(int value, node *l, node *r);
  node(const node &n);
  ~node();
  node& operator = (const node &n);
};

struct set::iterator 
{
    iterator();
    iterator& operator ++ ();
    iterator operator ++ (int);
    iterator& operator -- ();
    iterator operator -- (int);
    int& operator * () const;
    
    bool operator == (const iterator &a) const;
    bool operator != (const iterator &a) const;

    node *cur;
    iterator(node *cur);
};

#endif
