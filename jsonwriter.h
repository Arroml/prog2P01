#ifndef JSONWRITER_H
#define JSONWRITER_H

#include "writer.h"
#include "JSONLoader.h"

class JsonWriter : public Writer
{
public:
    JsonWriter();
    bool write(std::string file)override;
};

#endif // JSONWRITER_H
