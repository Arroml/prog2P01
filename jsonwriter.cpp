#include "jsonwriter.h"
#include "xmlloader.h"

JsonWriter::JsonWriter() {}

bool JsonWriter::write(std::string filename)
{
    std::cout << filename << std::endl;
    Node::FileType fileType = Node::FileType::JSON;

    XMLLoader *XMLloader = new XMLLoader;

    XMLloader->load("../../XML_test_files/" + filename, 1);

    std::cout << "Start writing ..." << std::endl;

    int stelle = filename.find('.');

    std::string fileStart = filename.substr(0, stelle);
    std::cout << fileStart << std::endl;
    std::filesystem::create_directory("../../output");
    if (fileStart.empty()) {
        std::cerr << "falscher Datei Name" << std::endl;
        return false;
    }
    std::filesystem::path path = "../../output/" + fileStart + ".json";
    std::ofstream file(path);

    if (file.is_open()) {
        Node *root = XMLloader->getRoot();
        if (root == nullptr) {
            std::cout << "keine Root" << std::endl;
            return false;
        }
        root->printNodeInFile(file, 0, fileType);

        return true;
    }
    return false;
}
