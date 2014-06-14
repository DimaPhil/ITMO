#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct list {
    struct iterator;
    struct const_iterator;
    
    list();
    list(const int &value);
    list(const list &l);
    list& operator=(list l);
    ~list();
    void doCopy(const list &l);
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
    void insert(iterator pos, int value); // insert before pos
    void erase(iterator pos);
    void splice(iterator pos, list &other, iterator first, iterator last);
    
    void print();
    friend void swap(list &a, list &b);
private:
    struct node;
    node *_begin, *_end;
    
    void del();
};

struct list::node {
    int value;
    node *prev, *next;
    
    node();
    node(int value);
    node(int value, node *prev, node *next);
    node(const node &n);
    ~node();
    node& operator= (const node &n);
};

struct list::iterator {
    iterator();
    int& operator*() const;
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    
    bool operator==(const iterator &a) const;
    bool operator!=(const iterator &a) const;

    node *cur;
    iterator(node *cur);
};

struct list::const_iterator {
    const_iterator();
    int const& operator*() const;
    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);
    
    bool operator==(const const_iterator &a) const;
    bool operator!=(const const_iterator &a) const; 

    node *cur;
    const_iterator(node *cur);
};

#endif // LIST_H_INCLUDED
