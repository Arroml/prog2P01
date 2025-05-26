#ifndef XMLWRITER_H
#define XMLWRITER_H

#include "writer.h"

class XMLWriter : public Writer
{
public:
    XMLWriter();
    bool write(std::string file)override;
};

#endif // XMLWRITER_H
