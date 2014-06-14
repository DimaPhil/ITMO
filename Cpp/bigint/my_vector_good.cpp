#include "my_vector_good.h"

my_vector::my_vector() 
{
  msk = 1;
  s.links = 0;
}

my_vector::my_vector(int size) 
{
  s.links = 0;
  if (size <= 1) 
  {
    msk = 1 + size * 2;
  }
  else 
  {
    vs = new vector<uint>(size);
    s.plinks = new uint(1);
    msk = 0;
  }
}

my_vector::my_vector(my_vector const& other) 
{
  if (other.msk) 
  {
    msk = other.msk;
    s.links = other.s.links;
  }
  else 
  {
    vs = other.vs;
    ++(*other.s.plinks);
    s.plinks = other.s.plinks;
    msk = 0;
  }
}

my_vector::~my_vector() 
{
  if (msk) 
  {
    //delete links;
  }
  else 
  {
    --(*s.plinks);
    if (*s.plinks == 0) 
    {
      delete s.plinks;
      delete vs;
    }
  }
}

void my_vector::make_own_copy() 
{
  if (msk)
    return;
  if ((*s.plinks) > 1) 
  {
    --(*s.plinks);
    s.plinks = new uint(1);
    vs = new vector<uint>(*vs);
  }
}

void my_vector::init() 
{
  if (!msk)
    return;
  vs = new vector<uint>();
  if (msk & 2)
    (*vs).push_back(s.links);
  s.plinks = new uint(1);
  msk = 0;
}


void my_vector::push_back(uint item) 
{
  if (msk == 1) 
  {
    s.links = item;
    msk |= 2;
  }
  else 
  {
    make_own_copy();
    init();
    (*vs).push_back(item);
  }
} 

void my_vector::pop_back() 
{
  if (msk) 
  {
    msk = 1;
    return;
  }
  make_own_copy();
  (*vs).pop_back();
}

void my_vector::resize(int size) 
{
  make_own_copy();
  init();
  (*vs).resize(size);
}

void my_vector::clear() 
{
  resize(0);
}

size_t my_vector::size() const 
{
  if (msk)
    return (msk & 2) > 0;
  return (*vs).size();
} 

uint const& my_vector::operator [] (int i) const 
{
  if (msk)
    return s.links;
  return (*vs)[i];
}

uint& my_vector::operator [] (int i) 
{
  if (msk)
    return s.links;
  make_own_copy();
  return (*vs)[i];
}

my_vector& my_vector::operator = (my_vector const& other) 
{
  if (this == &other)
    return *this;
  make_own_copy();
  if (other.msk) 
  {
    if (msk) 
    {
      msk = other.msk;
      s.links = other.s.links;
    }
    else 
    {
      (*vs).clear();
      if (other.msk > 1)
      (*vs).push_back(other.s.links);
    }
  }
  else 
  {
    if (!msk) 
    {
      --(*s.plinks);
      if (*s.plinks == 0) 
      {
        delete vs;
        delete s.plinks;
      }
    }
    else 
    {
      msk = 0;
      //delete links;
    }
    vs = other.vs;
    s.plinks = other.s.plinks;
    ++(*s.plinks);
  }
  return *this;
}

uint const& my_vector::back() const 
{
  if (msk)
    return s.links;
  return (*vs).back();
}

bool operator == (my_vector const& a, my_vector const& b) 
{
  if (!a.msk && !b.msk)
    return *(a.vs) == *(b.vs);
  if (a.msk && b.msk)
    return a.msk == b.msk && a.s.links == b.s.links;
  if (a.msk && !b.msk) 
  {
    if (bool(a.msk & 2) != (*b.vs).size())
      return false;
    if (bool(a.msk & 2) == 0)
      return true;
    return a.s.links == (*b.vs)[0];
  }
  if (b.msk && !a.msk) 
  {
    if (bool(b.msk & 2) != (*a.vs).size())
      return false;
    if (bool(b.msk & 2) == 0)
      return true;
    return b.s.links == (*a.vs)[0];
  }
  return false;
}

void reverse(my_vector& a) 
{
  if (a.msk)
    return;
  a.make_own_copy();
  reverse((*a.vs).begin(), (*a.vs).end());
}
