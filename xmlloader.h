#ifndef XMLLOADER_H
#define XMLLOADER_H
#include <iostream>
#include <fstream>

class XMLLoader
{
    enum TagType {NONE, START_TAG, END_TAG, SELF_CLOSING, KOMENTAR};
public:
    XMLLoader();
    void load(std::string file);
    void tagName(std::string line, TagType & type);
};

#endif // XMLLOADER_H
