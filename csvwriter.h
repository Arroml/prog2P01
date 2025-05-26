#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "writer.h"

class CSVWriter : public Writer
{
public:
    CSVWriter();
    void write()override;
};

#endif // CSVWRITER_H
