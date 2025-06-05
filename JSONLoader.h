//
// Created by Alexander Roman on 5/8/25.
//

#ifndef JSONLOADER_H
#define JSONLOADER_H
#include "Loader.h"

class JSONLoader : public Loader
{
public:
    void load(std::string file, int flag) override;
};

#endif //JSONLOADER_H
