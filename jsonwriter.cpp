#include "jsonwriter.h"

JsonWriter::JsonWriter() {}

bool JsonWriter::write(std::string filename){

    JSONLoader* loader = new JSONLoader;

    std::cout<<"Start writing ..."<<std::endl;
    std::ofstream file(filename+".json");

    if (file.is_open()) {

        file << "e";
            loader->getRoot()->printNode();;



    }

        return true;
}
