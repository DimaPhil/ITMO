#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include <string>
#include <node.h>

using std::string;

struct const_iterator
{
    const_iterator();
    string const& operator * () const;
    const_iterator& operator ++ ();
    const_iterator operator ++ (int);
    const_iterator& operator -- ();
    const_iterator operator -- (int);
    bool operator == (const const_iterator &other) const;
    bool operator != (const const_iterator &other) const;

    node *current;
    const_iterator(node *current);
};

#endif // CONST_ITERATOR_H
