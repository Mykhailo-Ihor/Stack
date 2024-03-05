#include "Stack.h"

Stack::Stack(int val) : topNode(nullptr)
{
    push(val);
}

Stack::Stack(const Stack& other)
{
    if (other.topNode == nullptr) {
        topNode = nullptr;
        return;
    }

    topNode = new Node(other.topNode->data);
    Node* current = topNode;
    Node* otherCurrent = other.topNode->next;

    while (otherCurrent != nullptr) {
        current->next = new Node(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

Stack::~Stack()
{
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int val)
{
    Node* newNode = new Node(val);
    newNode->next = topNode;
    topNode = newNode;
}

void Stack::pop() 
{
    if (!isEmpty()) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    else {
        throw std::runtime_error("Stack is empty! Cannot pop.");
    }
}
int Stack::top() const 
{
    if (!isEmpty()) {
        return topNode->data;
    }
    else {
        throw std::runtime_error("Stack is empty! Cannot return top element.");
    }
}

bool Stack::isEmpty() const
{
    return topNode == nullptr;
}