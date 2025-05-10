#ifndef XMLLOADER_H
#define XMLLOADER_H
#include <iostream>
#include <fstream>

#include "Loader.h"

class XMLLoader: public Loader
{
    enum TagType {NONE, START_TAG, END_TAG, SELF_CLOSING, KOMENTAR};
public:
    XMLLoader();
    void load(std::string file) override;
    void tagName(std::string line, TagType & type);
};

#endif // XMLLOADER_H
