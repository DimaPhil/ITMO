#ifndef LIST_H
#define LIST_H

#include <string>
#include <iterator.h>
#include <const_iterator.h>
#include <node.h>

using std::string;

struct list
{
    list();
    list(string const& value);
    list(list const& other);
    ~list();

    list& operator = (list const& other);
    void push_back(string const& value);
    void push_front(string const& value);
    void pop_back();
    void pop_front();
    string& front();
    string const& front() const;
    string& back();
    string const& back() const;
    bool empty() const;
    iterator begin();
    const_iterator cbegin() const;
    iterator end();
    const_iterator cend() const;
    iterator erase(iterator pos);
    iterator insert(iterator pos, string const& value);
    iterator splice(iterator pos, list& other, iterator first, iterator last);
private:
    void delete_list();
    friend void swap(list &a, list &b);
    node *head, *tail;
};

#endif // LIST_H

