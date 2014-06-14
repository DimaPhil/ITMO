#include "list.h"

list::const_iterator::const_iterator() {
    this->cur = 0;
}

list::const_iterator::const_iterator(node *cur) {
    this->cur = cur;
}

int const& list::const_iterator::operator*() const {
    return this->cur->value;
}

list::const_iterator& list::const_iterator::operator++() {
    this->cur = this->cur->next;
    return *this;    
}

list::const_iterator list::const_iterator::operator++(int) {
    const_iterator res = *this;
    this->cur = this->cur->next;
    return res;
}

list::const_iterator& list::const_iterator::operator--() {
    this->cur = this->cur->prev;
    return *this; 
}

list::const_iterator list::const_iterator::operator--(int) {
    const_iterator res = *this;
    this->cur = this->cur->prev;
    return res;
}

bool list::const_iterator::operator==(const list::const_iterator &a) const {
    return this->cur == a.cur;
}

bool list::const_iterator::operator!=(const list::const_iterator &a) const {
    return this->cur != a.cur;
}
