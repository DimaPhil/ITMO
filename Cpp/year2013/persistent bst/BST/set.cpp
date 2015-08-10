#include "set.h"
#include <cassert>

set::set() {
    root = nullptr;
}

set::set(const set &other) {
    root = std::make_shared<node>();
    root = other.root;
}

set &set::operator =(const set &other) {
    root = std::make_shared<node>();
    root->value = other.root->value;
    root->priority = rand();
    return *this;
}

set::~set() {
}

bool set::empty() const {
    return root == nullptr;
}

void set::split(std::shared_ptr<set::node> root, std::shared_ptr<set::node> &left, std::shared_ptr<set::node> &right, std::string const& x)
{
    if (root == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }
    std::shared_ptr<node> current(std::make_shared<node>(root.get()));
    if (x >= current->value) {
        split(current->right, current->right, right, x);
        left = current;
    } else {
        split(current->left, left, current->left, x);
        right = current;
    }
}

void set::split_less(std::shared_ptr<set::node> root, std::shared_ptr<set::node> &left, std::shared_ptr<set::node> &right, std::string const& x)
{
    if (root == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }
    std::shared_ptr<node> current(std::make_shared<node>(root.get()));
    if (x > current->value) {
        split_less(current->right, current->right, right, x);
        left = current;
    } else {
        split_less(current->left, left, current->left, x);
        right = current;
    }
}

std::shared_ptr<set::node> set::merge(std::shared_ptr<set::node> left, std::shared_ptr<set::node> right)
{
    std::shared_ptr<node> result = nullptr;
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    if (left->priority > right->priority) {
        result = std::shared_ptr<node>(std::make_shared<node>(left.get()));
        result->right = merge(left->right, right);
        return result;
    } else {
        result = std::shared_ptr<node>(std::make_shared<node>(right.get()));
        result->left = merge(left, right->left);
        return result;
    }
}

void set::insert(std::string const& value) {
    std::shared_ptr<node> new_node(std::make_shared<node>(value));
    std::shared_ptr<node> left = nullptr;
    std::shared_ptr<node> right = nullptr;
    split(root, left, right, value);
    std::shared_ptr<node> middle = nullptr;
    split_less(left, left, middle, value);
    if (middle != nullptr) {
        return;
    }
    root = merge(merge(left, new_node), right);
    assert(root != nullptr);
}

void set::erase(const std::string &value) {
    std::shared_ptr<node> left = nullptr;
    std::shared_ptr<node> right = nullptr;
    split(root, left, right, value);
    std::shared_ptr<node> middle = nullptr;
    split_less(left, left, middle, value);
    root = merge(left, right);
}

bool set::contains(std::string const& value) {
    std::shared_ptr<node> left = nullptr;
    std::shared_ptr<node> right = nullptr;
    split(root, left, right, value);
    std::shared_ptr<node> middle = nullptr;
    split_less(left, left, middle, value);
    return middle != nullptr;
}
