#include <iostream>
#include <stack>
#include "Stack.h"

int main() {
    Stack myStack;
    std::stack<int> STLStack;
    myStack.push(1);
    myStack.push(2);
    STLStack.push(1);
    STLStack.push(2);
    std::cout << "My Stack:\nTop element of stack: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    Stack copyStack(myStack);

    std::cout << "Top element in copied stack: " << copyStack.top() << std::endl;
    std::cout << "Deleting stack...\n";
    myStack.~Stack();
    std::cout << "Stack is empty: " << std::boolalpha << myStack.isEmpty();
    std::cout << "\nSTL Stack:\nTop element of stack: " << STLStack.top() << std::endl;
    STLStack.pop();
    std::cout << "Top element after pop: " << STLStack.top() << std::endl;
    std::cout << "Stack is empty: " << std::boolalpha << STLStack.empty();
    return 0;
}