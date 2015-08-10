#ifndef SET_H
#define SET_H

#include <string>
#include <memory>

struct set {
    set();
    set(set const& other);
    set& operator = (set const& other);
    ~set();

    bool empty() const;
    void insert(std::string const& value);
    void erase(std::string const& value);
    bool contains(std::string const&  value);

private:
    struct node;
    std::shared_ptr<node> root;
    bool exceptionRaised = false;

    void split(std::shared_ptr<node> root, std::shared_ptr<node> &left, std::shared_ptr<node> &right, std::string const& x);
    void split_less(std::shared_ptr<node> root, std::shared_ptr<node> &left, std::shared_ptr<node> &right, std::string const& x);
    std::shared_ptr<node> merge(std::shared_ptr<node> left, std::shared_ptr<node> right);
};

struct set::node {
    node();
    node(std::string const& value);
    node(node const& other);
    node(node *other);

    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
    std::string value;
    int priority;
};

#endif // SET_H
