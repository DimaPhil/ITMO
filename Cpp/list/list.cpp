#include "list.h"
#include <vector>
#include <iostream>

list::list() {
    _end = new node();
    _end->next = _end;
    _end->prev = _end;
    _begin = _end;
}

list::list(const int &value) {
    _end = new node();
    try {
        _begin = new node();
    } catch(...) {
        delete _end;
        throw "did'n create";
    }
    _end->next = _end;
    _end->prev = _begin;
    _begin->next = _end;
    _begin->prev = _begin;
    _begin->value = value;
}

void list::doCopy(const list &l) {
    this->_begin = new node(*l._begin);
    node *cur1 = this->_begin;
    this->_end = cur1;
    cur1->next = cur1;
    node *cur2 = l._begin;
    if (cur2 == l._end) return;
    cur2 = cur2->next;
    while (true) {
        cur1->next = new node(*cur2);
        cur1->next->prev = cur1;
        cur1 = cur1->next;
        this->_end = cur1;
        cur1->next = cur1;
        if (cur2 == l._end) break;
        cur2 = cur2->next;
    }
    if (*l.begin() == 3) {
        throw "fail";
    }  
}

list::list(const list &l) {
    try {
        doCopy(l);
    } catch (...) {
        del();
        throw "didn't create";
    }
}

void list::del() {
    std::vector<node*> v;
    node *cur = this->_begin;
    while (true) {
        v.push_back(cur);
        if (cur == this->_end) break;
        cur = cur->next;
    }
    for (int i = 0; i < (int)v.size(); i++) {
        delete v[i];
    }
}

void list::print() {
    std::vector<node*> v;
    node *cur = this->_begin;
    while (true) {
        v.push_back(cur);
        if (cur == this->_end) break;
        cur = cur->next;
    }
    if (v.size() == 1) std::cout << "empty";
    for (int i = 0; i < (int)v.size() - 1; i++) {
        std::cout << v[i]->value << " ";
    }
    std::cout << std::endl;
}

list::~list() {
    this->del();
}

void swap(list &a, list &b) {
    std::swap(a._begin, b._begin);
    std::swap(a._end, b._end);
}

list& list::operator=(list l) {
    swap(l, *this);
    return *this;
}

bool list::empty() const {
    return this->_begin == this->_end;
}

void list::push_back(int value) {
    if (empty()) {
        this->_begin = new node(value);
        this->_end->prev = this->_begin;
        this->_begin->next = this->_end;
    } else {
        this->_end->prev->next = new node(value, this->_end->prev, this->_end);
        this->_end->prev = this->_end->prev->next;
    }
}

// list is not empty
int& list::back() {
    return this->_end->prev->value;
}

const int& list::back() const {
    return this->_end->prev->value;
}

//list is not empty
void list::pop_back() {
    node *todel = this->_end->prev;
    if (todel == this->_begin) {
        this->_end->prev = this->_end;
        this->_begin = this->_end;
    } else {
        this->_end->prev = this->_end->prev->prev;
        this->_end->prev->next = this->_end;
    }
    delete todel;
}

void list::push_front(int value) {
    if (empty()) {
        this->_begin = new node(value);
        this->_end->prev = this->_begin;
        this->_begin->next = this->_end;
    } else {
        node *old = this->_begin;
        this->_begin = new node(value);
        this->_begin->next = old;
        old->prev = this->_begin;
    }
}

// list is not empty
int& list::front() {
    return this->_begin->value;
}

const int& list::front() const {
    return this->_begin->value;
}

//list is not empty
void list::pop_front() {
    node *todel = this->_begin;
    if (todel->next == this->_end) {
        this->_end->prev = this->_end;
        this->_begin = this->_end;
    } else {
        this->_begin = this->_begin->next;
        this->_begin->prev = this->_begin;
    }
    delete todel;
}


list::iterator list::begin() {
    return list::iterator(this->_begin);
}

list::const_iterator list::begin() const {
    return list::const_iterator(this->_begin);
}

list::iterator list::end() {
    return list::iterator(this->_end);
}

list::const_iterator list::end() const {
    return list::const_iterator(this->_end);
}

void list::insert(list::iterator pos, int value) {
    node *nw = new node(value);
    node *cur = pos.cur;
    if (cur != this->_begin) {
        nw->prev = cur->prev;
        nw->next = cur;
        cur->prev->next = nw;
        cur->prev = nw;
    } else {
        this->_begin = nw;
        nw->next = cur;
        cur->prev = nw;
    }
}

void list::erase(list::iterator pos) {
    node *cur = pos.cur;
    if (cur != this->_begin) {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    } else {
        this->_begin = this->_begin->next;
    }
    delete cur;
}

void list::splice(list::iterator pos, list &other, list::iterator first, list::iterator last) {
    node *cur = pos.cur;
    node *l = first.cur;
    node *r = last.cur;
    
    node *rr = r->prev;
    if (l == other._begin) {
        other._begin = r;
        r->prev = r;
    } else {
        l->prev->next = r;
        r->prev = l->prev;
    }
    
    r = rr;
    if (cur == this->_begin) {
        this->_begin = l;
        l->prev = l;
    } else {
        cur->prev->next = l;
        l->prev = cur->prev;
    }
    cur->prev = r;
    r->next = cur;
}
