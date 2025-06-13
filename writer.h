#ifndef WRITER_H
#define WRITER_H
#include "Loader.h"
#include <fstream>
#include <iostream>
#include <filesystem>

class Writer
{
public:
    Writer();
    virtual bool write(std::string file) = 0;
};

#endif // WRITER_H
