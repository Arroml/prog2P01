#include "stack.h"

Stack::Stack() {}

void Stack::push(std::string zeichen)
{
    stack_.push_back(zeichen);
}

std::string Stack::pop()
{
    if (this->isEmpty()) {
        std::cout << "Sack ist leer\n";
        return "";
    }
    std::string end = stack_.back();
    stack_.pop_back();
    return end;
}

bool Stack::isEmpty()
{
    if (stack_.empty()) {
        return true;
    }
    return false;
}
