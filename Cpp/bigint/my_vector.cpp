#include "my_vector.h"

my_vector::my_vector() 
{
  msk = 1;
  n = new uint(0);
}

my_vector::my_vector(int size) 
{
  n = new uint(0);
  if (size <= 1) 
    msk = 1 + size * 2;
  else 
  {
    vect = new std::vector<uint>(size);
    *n = 1;
    msk = 0;
  }
}

my_vector::my_vector(my_vector const& other) 
{
  if (other.msk) 
  {
    msk = other.msk;
    n = new uint(*other.n);
  }
  else 
  {
    vect = other.vect;
    ++(*other.n);
    n = other.n;
    msk = 0;
  }
}

my_vector::~my_vector() 
{
  if (msk)
    delete n;
  else 
  {
    --(*n);
    if (*n == 0) 
    {
      delete n;
      delete vect;
    }
  }
}

void my_vector::make_copy() 
{
  if (msk)
    return;
  if ((*n) > 1) 
  {
    --(*n);
    n = new uint(1);
    vect = new std::vector<uint>(*vect);
  }
}

void my_vector::init_ptns() 
{
  if (!msk)
    return;
  vect = new std::vector<uint>();
  if (msk & 2)
    (*vect).push_back(*n);
  *n = 1;
  msk = 0;
}

void my_vector::push_back(uint item) 
{
  if (msk == 1) 
  {
    *n = item;
    msk |= 2;
  }
  else 
  {
    make_copy();
    init_ptns();
    (*vect).push_back(item);
  }
} 

void my_vector::pop_back() 
{
  if (msk) 
  {
    msk = 1;
    return;
  }
  make_copy();
  (*vect).pop_back();
}

void my_vector::resize(int size) 
{
  make_copy();
  init_ptns();
  (*vect).resize(size);
}

void my_vector::clear()
{
  resize(0);
}

int my_vector::size() const 
{
  if (msk)
    return (msk & 2) > 0;
  return (*vect).size();
} 

uint const& my_vector::operator [] (int i) const 
{  
  if (msk)
    return *n;
  return (*vect)[i];
}
uint& my_vector::operator[] (int i) 
{
  if (msk)
    return *n;
  make_copy();
  return (*vect)[i];
}

my_vector& my_vector::operator = (my_vector const& other) 
{
  make_copy();
  if (other.msk) 
  {
    if (msk) 
    {
      msk = other.msk;
      *n = *other.n;
    }
    else
    {
      (*vect).clear();
      if (other.msk > 1)
        (*vect).push_back(*other.n);
    }
  }
  else 
  {
    if (!msk) 
    {
      --(*n);
      if (*n == 0) 
      {
        delete vect;
        delete n;
      }
    }
    else 
    {
      msk = 0;
      delete n;
    }
    vect = other.vect;
    n = other.n;
    ++(*n);
  }
  return *this;
}

uint const& my_vector::back() const 
{
  if (msk)
    return *n;
  return (*vect).back();
}

bool operator == (my_vector const& a, my_vector const& b) 
{
  if (!a.msk && !b.msk)
    return *(a.vect) == *(b.vect);
  if (a.msk && b.msk)
    return a.msk == b.msk && *a.n == *b.n;
  if (a.msk && !b.msk) 
  {
    if (!!(a.msk & 2) != (*b.vect).size())
      return false;
    if (!!(a.msk & 2) == 0)
      return true;
    return *a.n == (*b.vect)[0];
  }
  if (b.msk && !a.msk) 
  {
    if (!!(b.msk & 2) != (*a.vect).size())
      return false;
    if (!!(b.msk & 2) == 0)
      return true;
    return *b.n == (*a.vect)[0];
  }
  return false;
}

void reverse(my_vector& a) 
{
  if (a.msk)
    return;
  a.make_copy();
  reverse((*a.vect).begin(), (*a.vect).end());
}
