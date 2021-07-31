#include "list.h"
#include "utils.h"

Iterator::Iterator(ListNode* node) : node_(node) {}

int Iterator::operator*() {
    return node_->val;
}

Iterator& Iterator::operator++() {
    node_ = node_->next;
    return *this;
}

bool Iterator::operator!=(const Iterator& it){
    return it.node_ != node_;
}

bool Iterator::operator==(const Iterator& it){
    return it.node_ == node_;
}

std::ostream & operator<<(std::ostream & os , MyList &list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        os << *it << " ";
    }
    return os;
}

MyList::MyList() {}

MyList::MyList(const std::string& src) {
    auto str_values = std::move(utils::split(src, ' '));
    add_node(str_values);
}

MyList::~MyList() {
    destory();
}

void MyList::add_node(int value) {
    ListNode* new_node = new ListNode(value);

    if (!head_) {
        head_ = new_node;
        tail_ = head_;
        return;
    }

    tail_->next = new_node;
    tail_ = new_node;
}

void MyList::add_node(const std::vector<int>& values) {
    for (size_t i = 0; i < values.size(); i++) {
        add_node(values[i]);
    }
}

void MyList::add_node(const std::vector<std::string>& values) {
    for (size_t i = 0; i < values.size(); i++) {
        add_node(std::atoi(values[i].data()));
    }
}

void MyList::destory() {
    if (!head_) return;

    ListNode* cur = head_;
    while(cur) {
        auto tmp = cur->next;
        delete cur;
        cur = tmp;
    }
    head_ = tail_ = nullptr;
}

MyList MyList::operator+(MyList &list) {
    MyList ret;

    for (auto it = begin(); it != end(); ++it) {
        ret.add_node(*it);
    }

    for (auto it = list.begin(); it != list.end(); ++it) {
        ret.add_node(*it);
    }
    return ret;
}

MyList& MyList::operator<<(const std::string& src) {
    destory();

    auto str_values = std::move(utils::split(src, ' '));
    add_node(str_values);
    return *this;
}

MyList& MyList::operator-() {
    reverse();
    return *this;
}

void MyList::reverse() {
    ListNode* cur = head_;
    ListNode* pre = nullptr;

    while (cur) {
        auto next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    tail_ = head_;
    head_ = pre;
}