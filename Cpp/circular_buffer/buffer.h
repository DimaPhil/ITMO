#ifndef BUFFER_H
#define BUFFER_H
#include <vector>

using namespace std;

struct buffer
{
  struct iterator;
  struct const_iterator;
  struct reverse_iterator;
  struct const_reverse_iterator;
  struct node;
    
  buffer();
  buffer(const buffer &l);
  buffer& operator = (buffer l);
  ~buffer();

  bool empty() const;

  void push_back(int value);
  int& back();
  const int& back() const;
  void pop_back();
  void push_front(int value);

  int& front();
  const int& front() const;
  void pop_front();

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  void insert(iterator pos, int value);
  void erase(iterator pos);
    
  void print();
private:
  vector <int> elements;
  int pbegin, pend;
  
  friend void swap(buffer &a, buffer &b);
    
  void deleteBuffer();
};

struct buffer::node 
{
  int value;
  int prev, next;
    
  node();
  node(int value);
  node(int value, int prev, int next);
  node(const node &n);
  ~node();

  node& operator = (const node &n);
};

struct buffer::iterator 
{
  iterator();
  int& operator * () const;
  iterator& operator ++ ();
  iterator operator ++ (int);
  iterator& operator -- ();
  iterator operator -- (int);
  
  bool operator == (const iterator &it) const;
  bool operator != (const iterator &it) const;

  node *now;
  iterator(node *now);
};

struct buffer::const_iterator 
{
  const_iterator();
  int const& operator * () const;
  const_iterator& operator ++ ();
  const_iterator operator ++ (int);
  const_iterator& operator -- ();
  const_iterator operator -- (int);
    
  bool operator == (const const_iterator &it) const;
  bool operator != (const const_iterator &it) const; 

  node *now;
  const_iterator(node *now);
};

struct buffer::reverse_iterator
{
  reverse_iterator();
  int& operator * () const;
  reverse_iterator& operator ++ ();
  reverse_iterator operator ++ (int);
  reverse_iterator& operator -- ();
  reverse_iterator operator -- (int);
  
  bool operator == (const reverse_iterator &it) const;
  bool operator != (const reverse_iterator &it) const;

  node *now;
  reverse_iterator(node *now);
};

struct buffer::const_reverse_iterator 
{
  const_reverse_iterator();
  int const& operator * () const;
  const_reverse_iterator& operator ++ ();
  const_reverse_iterator operator ++ (int);
  const_reverse_iterator& operator -- ();
  const_reverse_iterator operator -- (int);
    
  bool operator == (const const_reverse_iterator &it) const;
  bool operator != (const const_reverse_iterator &it) const; 

  node *now;
  const_reverse_iterator(node *now);
};

#endif // BUFFER_H
