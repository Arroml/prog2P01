#ifndef WRITER_H
#define WRITER_H
#include <iostream>
#include <fstream>
#include "Loader.h"

class Writer
{
public:
    Writer();
    virtual bool write(std::string file)=0;
};

#endif // WRITER_H
