#include "node.h"
#include <string>

using std::string;

node::node()
{
    this->value = "";
    this->next = this;
    this->previous = this;
}

node::node(string const& value)
{
    this->value = value;
    this->next = this;
    this->previous = this;
}

node::node(string const& value, node *previous, node *next)
{
    this->value = value;
    this->previous = previous;
    this->next = next;
}

node::node(const node &other)
{
    this->value = other.value;
    this->next = other.next;
    this->previous = other.previous;
}

node& node::operator = (const node &other)
{
    this->value = other.value;
    this->next = other.next;
    this->previous = other.previous;
    return *this;
}
