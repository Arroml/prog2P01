//
// Created by Alexander Roman on 5/6/25.
//

#ifndef CSVLOADER_H
#define CSVLOADER_H
#include "Loader.h"

class CSVLoader : public Loader
{
public:
    CSVLoader();
    void load(std::string file, int flag) override;
};

#endif //CSVLOADER_H
