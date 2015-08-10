#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

struct node
{
    string value;
    node *next, *previous;

    node();
    node(string const& value);
    node(string const& value, node *previous, node *next);
    node(const node &other);
    node& operator = (const node &other);
};

#endif // NODE_H
