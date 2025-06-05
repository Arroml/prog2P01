//
// Created by Alexander Roman on 5/6/25.
//

#ifndef INVALIDOPERATIONEXCEPTION_H
#define INVALIDOPERATIONEXCEPTION_H
#include <exception>
#include <stdexcept>

class InvalidOperationException : public std::logic_error
{
public:
    InvalidOperationException(const std::string &msg)
        : logic_error(msg)
    {}
};

#endif //INVALIDOPERATIONEXCEPTION_H
