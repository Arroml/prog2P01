#include "jsonwriter.h"

JsonWriter::JsonWriter() {}

bool JsonWriter::write(std::string filename){
    std::cout<<"Start writing ..."<<std::endl;

    std::ofstream file(filename+".json");

    if (file.is_open()) {

        file << "test123" << std::endl;

    }

        return true;
}
