#ifndef STACK_H
#define STACK_H
#include <vector>
#include <iostream>

class Stack
{
    std::vector<std::string> stack_;
public:
    Stack();
    void push(std::string string);
    std::string pop();
    bool isEmpty();
};

#endif // STACK_H
