#include "iterator.h"
#include <string>
#include <cassert>

iterator::iterator()
{
    this->current = 0;
}

iterator::iterator(node *current)
{
    this->current = current;
}

string& iterator::operator * () const
{
    return this->current->value;
}

iterator& iterator::operator ++ ()
{
    assert(this->current->next != nullptr);
    this->current = this->current->next;
    return *this;
}

iterator iterator::operator ++ (int)
{
    assert(this->current->next != nullptr);
    iterator res = *this;
    this->current = this->current->next;
    return res;
}

iterator& iterator::operator -- ()
{
    assert(this->current->previous != nullptr);
    this->current = this->current->previous;
    return *this;
}

iterator iterator::operator -- (int)
{
    assert(this->current->previous != nullptr);
    iterator res = *this;
    this->current = this->current->previous;
    return res;
}

bool iterator::operator == (const iterator &other) const
{
    return this->current == other.current;
}

bool iterator::operator != (const iterator &other) const
{
    return this->current != other.current;
}
