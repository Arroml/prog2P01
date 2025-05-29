//
// Created by Alexander Roman on 5/6/25.
//

#ifndef LOADER_H
#define LOADER_H
#include <iostream>
#include <map>
#include "Node.h"


class Loader {
protected:
    Node* root;

    public:
    Loader();
    virtual void load(std::string fileName, int flag) = 0;
    Node* getRoot();
    virtual ~Loader();
    void initRegisteredLoaders();

};

#endif //LOADER_H
