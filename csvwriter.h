#ifndef CSVWRITER_H
#define CSVWRITER_H

#include "writer.h"

class CSVWriter : public Writer
{
public:
    CSVWriter();
    bool write(std::string file) override;
};

#endif // CSVWRITER_H
