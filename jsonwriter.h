#ifndef JSONWRITER_H
#define JSONWRITER_H

#include "JSONLoader.h"
#include "writer.h"
#include <filesystem>

class JsonWriter : public Writer
{
public:
    JsonWriter();
    bool write(std::string file) override;
};

#endif // JSONWRITER_H
