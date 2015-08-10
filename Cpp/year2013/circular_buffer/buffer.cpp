#include "buffer.h"
#include <algorithm>
#include <iostream>

using namespace std;

buffer::buffer() {
  elements.clear();
  pbegin = pend = 0;
}

void buffer::deleteBuffer()
{
  std::vector<buffer::iterator> nodes;
  buffer::iterator now = buffer::begin();
  while (now != buffer::end())
  {
    nodes.push_back(now);
    now++;
  }
  //for (size_t i = 0; i < nodes.size(); i++)
  //  delete nodes[i];
}

buffer::~buffer()
{
  this->deleteBuffer();
}

/*buffer::buffer(const buffer &l)
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
    this->deleteBuffer();
    throw;
  }
}

void swap(buffer &a, buffer &b) 
{
  std::swap(a.pbegin, b.pbegin);
  std::swap(a.pend, b.pend);
}

buffer& buffer::operator = (buffer l) 
{
  swap(l, *this);
  return *this;
}

bool buffer::empty() const 
{
  return this->pbegin == this->pend;
}

void buffer::push_back(int value) 
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

int& buffer::back() 
{
  return this->pend->prev->value;
}

const int& buffer::back() const
{
  return this->pend->prev->value;
}

void buffer::pop_back() 
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

void buffer::push_front(int value) 
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

int& buffer::front() 
{
  return this->pbegin->value;
}

const int& buffer::front() const 
{
  return this->pbegin->value;
}

void buffer::pop_front() {
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


buffer::iterator buffer::begin() 
{
  return buffer::iterator(elements[pbegin]);
}

buffer::const_iterator buffer::begin() const 
{
  return buffer::const_iterator(this->pbegin);
}

buffer::reverse_iterator buffer::rbegin()
{
  return buffer::reverse_iterator(this->pend);
}

buffer::const_reverse_iterator buffer::rbegin() const
{
  return buffer::const_reverse_iterator(this->pend);
}

buffer::iterator buffer::end() 
{
  return buffer::iterator(this->pend);
}

buffer::const_iterator buffer::end() const 
{
  return buffer::const_iterator(this->pend);
}

buffer::reverse_iterator buffer::rend()
{
  return buffer::reverse_iterator(this->pbegin);
}

buffer::const_reverse_iterator buffer::rend() const
{
  return buffer::const_reverse_iterator(this->pbegin);
}

void buffer::insert(buffer::iterator pos, int value)
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

void buffer::erase(buffer::iterator pos) 
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

void buffer::splice(buffer::iterator pos, buffer &other, buffer::iterator first, buffer::iterator last) 
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
} */
  