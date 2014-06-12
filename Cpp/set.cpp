#include "set.h"
#include "set_iterator.cpp"
#include "node.cpp"
#include <iostream>
#include <vector>

set::set() 
{
  root = new node();
  root->value = 42;
  root->l = NULL;
  root->r = NULL;
}

set::set(set const& other) 
{
  try 
  {
    root = new node();
  } 
  catch(...) 
  {
    delete root;
    throw "did'n create";
  }
  root = other.root;
}

set& set::operator = (set const& other)
{
  try 
  {
    root = new node();
  } 
  catch(...) 
  {
    delete root;
    throw "did'n create";
  }
  this->root.value = other->root.value;
  this->root->l = other->root->l;
  this->root->r = other->root->r;

  return *this;
}

size_t set::size()
{
  int ans = 0;
  for (set::iterator it = begin(); it != end(); ++it)
    ++ans;
  return ans;
}

bool set::empty()
{
  return begin() == end();
}

void set::del()
{
  std::vector<node*> v;
  v.push_back(this->root);
  size_t pt = 0;
  while (pt < v.size())
  {
    if (v[pt]->l != NULL)
      v.push_back(v[pt]->l);
    if (v[pt]->r != NULL)
      v.push_back(v[pt]->r);
    ++pt;
  }
  for (size_t i = 0; i < v.size(); ++i)
    delete v[i];
}

set::~set() {
  this->del();
}

set::iterator set::begin() const
{
  node *cur = this->root;
  while (cur->l != NULL)
    cur = cur->l;
  return cur;
}

set::iterator set::end() const 
{
  node *cur = this->root;
  while (cur->r != NULL)
    cur = cur->r;
  return cur;
}

set::iterator set::find(int value) 
{
  if (empty()) 
    return end();
  node *cur = this->root;
  while (cur != NULL && cur->value != value)
  {
    if (cur->value < value)
      cur = cur->r;
    else
      cur = cur->l;
  }
  if (cur != NULL)
    return cur;
}

set::iterator set::insert(int value)
{
  return begin();
}

set::iterator set::erase(set::iterator it)
{
  return begin();
}

/*void set::insert(int value) 
{
  node *nw = new node(value);
  node *cur = pos.cur;
  if (cur != this->_begin) 
  {
    nw->prev = cur->prev;
    nw->next = cur;
    cur->prev->next = nw;
    cur->prev = nw;
  } 
  else 
  {
    this->_begin = nw;
    nw->next = cur;
    cur->prev = nw;
  }
}

void set::erase(set::iterator pos) {
    node *cur = pos.cur;
    if (cur != this->_begin) {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    } else {
        this->_begin = this->_begin->next;
    }
    delete cur;
}

void set::splice(set::iterator pos, set &other, set::iterator first, set::iterator last) {
    node *cur = pos.cur;
    node *l = first.cur;
    node *r = last.cur;
    
    node *rr = r->prev;
    if (l == other._begin) {
        other._begin = r;
        r->prev = r;
    } else {
        l->prev->next = r;
        r->prev = l->prev;
    }
    
    r = rr;
    if (cur == this->_begin) {
        this->_begin = l;
        l->prev = l;
    } else {
        cur->prev->next = l;
        l->prev = cur->prev;
    }
    cur->prev = r;
    r->next = cur;
} */
