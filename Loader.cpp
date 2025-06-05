//
// Created by Alexander Roman on 5/6/25.
//

#include "Loader.h"

Loader::Loader()
    : root(nullptr)
{}

void Loader::load(std::string name, int flag) {}

Loader::~Loader() {}

Node *Loader::getRoot()
{
    return this->root;
}
