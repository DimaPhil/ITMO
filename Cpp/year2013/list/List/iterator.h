#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include <node.h>

using std::string;

struct iterator
{
    iterator();
    iterator(node *current);

    string& operator * () const;
    iterator& operator ++ ();
    iterator operator ++ (int);
    iterator& operator -- ();
    iterator operator -- (int);
    bool operator == (const iterator &other) const;
    bool operator != (const iterator &other) const;

    node *current;
};

#endif // ITERATOR_H
