#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Iterator {
public:
    Iterator(ListNode* node);

    int operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& it);
    bool operator==(const Iterator& it);

private:
    ListNode* node_ = nullptr;
};

class MyList{
    friend std::ostream & operator<<(std::ostream & os , MyList &a);

public:
    MyList();
    MyList(const std::string& src);
    ~MyList();

    void add_node(int value);
    void add_node(const std::vector<int>& values);
    void add_node(const std::vector<std::string>& values);
    void destory();
    MyList operator+(MyList &a);
    MyList& operator<<(const std::string& src);
    MyList& operator-();

    Iterator begin() {
        return Iterator(head_);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

private:
    void reverse();

private:
    ListNode *head_ = nullptr;
    ListNode* tail_ = nullptr;
};



#endif // LIST_MODE_H
