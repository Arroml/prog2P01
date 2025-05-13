//
// Created by Alexander Roman on 5/6/25.
//

#ifndef LOADER_H
#define LOADER_H
#include <iostream>

#include "Node.h"


class Loader {
protected:
    Node* root;
    public:
    Loader();
    virtual void load(std::string fileName) = 0;
    Node* getRoot();
    virtual ~Loader();

};

#endif //LOADER_H
