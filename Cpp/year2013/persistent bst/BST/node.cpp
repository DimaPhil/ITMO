#include "set.h"

set::node::node() {
    value = "";
    left = nullptr;
    right = nullptr;
}

set::node::node(std::string const& value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
}

set::node::node(node const& other) {
    value = other.value;
    left = other.left;
    right = other.right;
}

set::node::node(node *other) {
    value = other->value;
    priority = other->priority;
    left = other->left;
    right = other->right;
}
