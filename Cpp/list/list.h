#ifndef LIST_H
#define LIST_H

struct list 
{
  struct iterator;
  struct const_iterator;
    
  list();
  list(const int &value);
  list(const list &l);
  list& operator = (list l);
  ~list();

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

  void insert(iterator pos, int value);
  void erase(iterator pos);
  void splice(iterator pos, list &other, iterator first, iterator last);
    
  void print();
private:
  struct node;
  node *pbegin, *pend;
  
  friend void swap(list &a, list &b);
    
  void deleteList();
};

struct list::node 
{
  int value;
  node *prev, *next;
    
  node();
  node(int value);
  node(int value, node *prev, node *next);
  node(const node &n);
  ~node();

  node& operator = (const node &n);
};

struct list::iterator 
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

struct list::const_iterator 
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

#endif // LIST_H
