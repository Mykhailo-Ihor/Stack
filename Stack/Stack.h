#pragma once
#include <iostream>
class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}
    Stack(int val);
    Stack(const Stack& other);
    ~Stack();
    void push(int val);
    void pop();
    int top() const;
    bool isEmpty() const;
};
