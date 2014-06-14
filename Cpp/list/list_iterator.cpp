#include "list.h"

list::iterator::iterator() {
    this->cur = 0;
}

list::iterator::iterator(node *cur) {
    this->cur = cur;
}

int& list::iterator::operator*() const {
    return this->cur->value;
}

list::iterator& list::iterator::operator++() {
    this->cur = this->cur->next;
    return *this;    
}

list::iterator list::iterator::operator++(int) {
    iterator res = *this;
    this->cur = this->cur->next;
    return res;
}

list::iterator& list::iterator::operator--() {
    this->cur = this->cur->prev;
    return *this; 
}

list::iterator list::iterator::operator--(int) {
    iterator res = *this;
    this->cur = this->cur->prev;
    return res;
}

bool list::iterator::operator==(const list::iterator &a) const {
    return this->cur == a.cur;
}

bool list::iterator::operator!=(const list::iterator &a) const {
    return this->cur != a.cur;
}
