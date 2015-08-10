#include "list.h"
#include <vector>
#include <iostream>

using std::vector;

list::list()
{
    tail = new node();
    tail->next = tail;
    tail->previous = tail;
    head = tail;
}

list::list(string const& value) {
    tail = new node();
    try
    {
        head = new node();
    }
    catch(...)
    {
        delete tail;
        throw;
    }
    tail->next = tail;
    tail->previous = head;
    head->next = tail;
    head->previous = head;
    head->value = value;
}

void list::delete_list()
{
    node *current = head;
    while (true)
    {
        node *to_delete = current;
        if (current == tail) {
            delete to_delete;
            break;
        }
        current = current->next;
        delete to_delete;
    }
}

list::~list()
{
  this->delete_list();
}

list::list(const list &l)
{
    node *old_head = head;
    node *old_tail = tail;
    try
    {
        head = new node(*l.head);
        node *now_node = head;
        tail = now_node;
        now_node->next = now_node;
        node *l_now_node = l.head;
        if (l_now_node == l.tail)
            return;
        l_now_node = l_now_node->next;
        while (true)
        {
            now_node->next = new node(*l_now_node);
            now_node->next->previous = now_node;
            now_node = now_node->next;
            tail = now_node;
            now_node->next = now_node;
            if (l_now_node == l.tail)
                break;
            l_now_node = l_now_node->next;
        }
    }
    catch (...)
    {
        head = old_head;
        tail = old_tail;
        delete_list();
        throw;
    }
}

void swap(list &a, list &b)
{
    std::swap(a.head, b.head);
    std::swap(a.tail, b.tail);
}

list& list::operator = (list const& l)
{
    list lcopy = l;
    swap(lcopy, *this);
    return *this;
}

bool list::empty() const
{
    return head == tail;
}

void list::push_back(string const& value)
{
    if (empty())
    {
        head = new node(value);
        tail->previous = head;
        head->next = tail;
    }
    else
    {
        tail->previous->next = new node(value, tail->previous, tail);
        tail->previous = tail->previous->next;
    }
}

iterator list::begin()
{
    return iterator(head);
}

const_iterator list::cbegin() const
{
    return const_iterator(head);
}

iterator list::end()
{
    return iterator(tail);
}

const_iterator list::cend() const
{
    return const_iterator(tail);
}

string& list::back()
{
    return tail->previous->value;
}

const string& list::back() const
{
    return tail->previous->value;
}

void list::pop_back()
{
    node *x = tail->previous;
    if (x == head)
    {
        tail->previous = tail;
        head = tail;
    }
    else
    {
        tail->previous = tail->previous->previous;
        tail->previous->next = tail;
    }
    delete x;
}

void list::push_front(string const& value)
{
    if (empty())
    {
        head = new node(value);
        tail->previous = head;
        head->next = tail;
    }
    else
    {
        node *old_head = head;
        head = new node(value);
        head->next = old_head;
        old_head->previous = head;
    }
}

string& list::front()
{
    return head->value;
}

const string& list::front() const
{
    return head->value;
}

void list::pop_front() {
    node *x = head;
    if (x->next == tail)
    {
        tail->previous = tail;
        head = this->tail;
    }
    else
    {
        head = head->next;
        head->previous = head;
    }
    delete x;
}

iterator list::insert(iterator pos, string const& value)
{
    node *new_node = new node(value);
    node *now_node = pos.current;
    if (now_node != head)
    {
        new_node->previous = now_node->previous;
        new_node->next = now_node;
        now_node->previous->next = new_node;
        now_node->previous = new_node;
    }
    else
    {
        head = new_node;
        new_node->next = now_node;
        now_node->previous = new_node;
    }
    return iterator(new_node);
}

iterator list::erase(iterator pos)
{
    node *now_node = pos.current;
    if (now_node != head)
    {
        now_node->next->previous = now_node->previous;
        now_node->previous->next = now_node->next;
    }
    else
    {
        head = head->next;
    }
    node *result = now_node->next;
    delete now_node;
    return iterator(result);
}

iterator list::splice(iterator pos, list &other, iterator first, iterator last)
{
    node *now_node = pos.current;
    node *left_node = first.current;
    node *right_node = last.current;

    node *old_right = right_node->previous;
    if (left_node == other.head)
    {
        other.head = right_node;
        right_node->previous = right_node;
    }
    else
    {
        left_node->previous->next = right_node;
        right_node->previous = left_node->previous;
    }

    right_node = old_right;
    if (now_node == head)
    {
        head = left_node;
        left_node->previous = left_node;
    }
    else
    {
        now_node->previous->next = left_node;
        left_node->previous = now_node->previous;
    }
    now_node->previous = right_node;
    right_node->next = now_node;
    return iterator(now_node);
}
