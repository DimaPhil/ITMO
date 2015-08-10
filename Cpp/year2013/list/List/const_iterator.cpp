#include "const_iterator.h"
#include <string>
#include <cassert>

const_iterator::const_iterator()
{
    this->current = 0;
}

const_iterator::const_iterator(node *current)
{
    this->current = current;
}

string const& const_iterator::operator * () const
{
    return this->current->value;
}

const_iterator& const_iterator::operator ++ ()
{
    assert(this->current->next != nullptr);
    this->current = this->current->next;
    return *this;
}

const_iterator const_iterator::operator ++ (int)
{
    assert(this->current->next != nullptr);
    const_iterator res = *this;
    this->current = this->current->next;
    return res;
}

const_iterator& const_iterator::operator -- ()
{
    assert(this->current->previous != nullptr);
    this->current = this->current->previous;
    return *this;
}

const_iterator const_iterator::operator -- (int)
{
    assert(this->current->previous != nullptr);
    const_iterator res = *this;
    this->current = this->current->previous;
    return res;
}

bool const_iterator::operator == (const const_iterator &other) const
{
    return this->current == other.current;
}

bool const_iterator::operator != (const const_iterator &other) const
{
    return this->current != other.current;
}

