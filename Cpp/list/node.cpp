#include "list.h"

list::node::node() {
    this->value = 0;
    this->next = this->prev = this;
}

list::node::node(int value) {
    this->value = value;
    this->next = this->prev = this;
}

list::node::node(int value, list::node *prev, list::node *next) {
    this->value = value;
    this->prev = prev;
    this->next = next;
}

list::node::node(const list::node &n) {
    this->value = n.value;
    this->next = n.next;
    this->prev = n.prev;
}

list::node::~node() {

}

list::node& list::node::operator= (const node &n) {
    this->value = n.value;
    this->next = n.next;
    this->prev = n.prev;   
    return *this; 
}
