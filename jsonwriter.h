#ifndef JSONWRITER_H
#define JSONWRITER_H

#include "JSONLoader.h"
#include "writer.h"


class JsonWriter : public Writer
{
public:
    JsonWriter();
    bool write(std::string filename) override;
};

#endif // JSONWRITER_H
