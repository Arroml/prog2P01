#ifndef XMLWRITER_H
#define XMLWRITER_H

#include "writer.h"

class XMLWriter : public Writer
{
public:
    XMLWriter();
    void write()override;
};

#endif // XMLWRITER_H
