#include "list.h"
#include "node.cpp"
#include "list_iterator.cpp"
#include "list_const_iterator.cpp"
#include <vector>
#include <iostream>

list::list() {
  pend = new node();
  pend->next = pend;
  pend->prev = pend;
  pbegin = pend;
}

/*list::list(const int &value) {
  pend = new node();
  try {
    pbegin = new node();
  } catch(...) {
    delete pend;
    throw;
  }
  pend->next = pend;
  pend->prev = pbegin;
  pbegin->next = pend;
  pbegin->prev = pbegin;
  pbegin->value = value;
}

void list::deleteList()
{
  std::vector<node*> nodes;
  node *now = this->pbegin;
  while (1)
  {
    nodes.push_back(now);
    if (now == this->pend)
      break;
    now = now->next;
  }
  for (size_t i = 0; i < nodes.size(); i++)
    delete nodes[i];
}

list::~list()
{
  this->deleteList();
}

list::list(const list &l)
{
  try 
  {
    this->pbegin = new node(*l.pbegin);
    node *tmp1 = this->pbegin;
    this->pend = tmp1;
    tmp1->next = tmp1;
    node *tmp2 = l.pbegin;
    if (tmp2 == l.pend)
      return;
    tmp2 = tmp2->next;
    while (1)
    {
      tmp1->next = new node(*tmp2);
      tmp1->next->prev = tmp1;
      tmp1 = tmp1->next;
      this->pend = tmp1;
      tmp1->next = tmp1;
      if (tmp2 == l.pend)
        break;
      tmp2 = tmp2->next;
    }
  } catch (...) {
    this->deleteList();
    throw;
  }
}

list& list::operator = (list l) 
{
  swap(l->pbegin, *this->pbegin);
  swap(l->pend, *this->pend);
  return *this;
}

bool list::empty() const 
{
  return this->pbegin == this->pend;
}

void list::push_back(int value) 
{
  if (empty()) 
  {
    this->pbegin = new node(value);
    this->pend->prev = this->pbegin;
    this->pbegin->next = this->pend;
  } 
  else
  {
    this->pend->prev->next = new node(value, this->pend->prev, this->pend);
    this->pend->prev = this->pend->prev->next;
  }
}

int& list::back() 
{
  return this->pend->prev->value;
}

const int& list::back() const
{
  return this->pend->prev->value;
}

void list::pop_back() 
{
  node *elem = this->pend->prev;
  if (elem == this->pbegin) 
  {
    this->pend->prev = this->pend;
    this->pbegin = this->pend;
  } 
  else 
  {
    this->pend->prev = this->pend->prev->prev;
    this->pend->prev->next = this->pend;
  }
  delete elem;
}

void list::push_front(int value) 
{
  if (empty()) 
  {
    this->pbegin = new node(value);
    this->pend->prev = this->pbegin;
    this->pbegin->next = this->pend;
  } 
  else 
  {
    node *lastBegin = this->pbegin;
    this->pbegin = new node(value);
    this->pbegin->next = lastBegin;
    lastBegin->prev = this->pbegin;
  }
}

int& list::front() 
{
  return this->pbegin->value;
}

const int& list::front() const 
{
  return this->pbegin->value;
}

void list::pop_front() {
  node *elem = this->pbegin;
  if (elem->next == this->pend) 
  {
    this->pend->prev = this->pend;
    this->pbegin = this->pend;
  } 
  else 
  {
    this->pbegin = this->pbegin->next;
    this->pbegin->prev = this->pbegin;
  }
  delete elem;
}


list::iterator list::begin() 
{
  return list::iterator(this->pbegin);
}

list::const_iterator list::begin() const 
{
  return list::const_iterator(this->pbegin);
}

list::iterator list::end() 
{
  return list::iterator(this->pend);
}

list::const_iterator list::end() const 
{
  return list::const_iterator(this->pend);
}

void list::insert(list::iterator pos, int value)
{
  node *newNode = new node(value);
  node *now = pos.now;
  if (now != this->pbegin) 
  {
    newNode->prev = now->prev;
    newNode->next = now;
    now->prev->next = newNode;
    now->prev = newNode;
  } 
  else 
  {
    this->pbegin = newNode;
    newNode->next = now;
    now->prev = newNode;
  }
}

void list::erase(list::iterator pos) 
{
  node *now = pos.now;
  if (now != this->pbegin) 
  {
    now->next->prev = now->prev;
    now->prev->next = now->next;
  } 
  else 
  {
    this->pbegin = this->pbegin->next;
  }
  delete now;
}

void list::splice(list::iterator pos, list &other, list::iterator first, list::iterator last) 
{
  node *now = pos.now;
  node *l = first.now;
  node *r = last.now;
    
  node *prevR = r->prev;
  if (l == other.pbegin) 
  {
    other.pbegin = r;
    r->prev = r;
  } 
  else 
  {
    l->prev->next = r;
    r->prev = l->prev;
  }
    
  r = prevR;
  if (now == this->pbegin) 
  {
    this->pbegin = l;
    l->prev = l;
  } 
  else 
  {
    now->prev->next = l;
    l->prev = now->prev;
  }
  now->prev = r;
  r->next = now;
}*/
