#include "Node.h"
#include <fstream>

Node::Node(std::string name) : tagName(name) {}

Node::~Node() {
    deleteCildren();
}

void Node::addChild(Node* child) {
    children.push_back(child);
}

Node* Node::removeChild() {
    Node* child = children.back();
    children.pop_back();
    return child;
}

void Node::printNode(std::ofstream& os, int level, FileType File) {
    if (tagName.back() == '/'){
        tagName.pop_back();
    }
    if (tagName.back() == ' '){
        tagName.pop_back();
    }
    for (int i = 0; i < level; i++) {
        std::cout << "  ";
    }
    std::cout << tagName << std::endl;

    for (Node* child : children) {
        child->printNode(os, level+1, File);
    }
   /* for(int i = 0; i<level; i++){
        std::cout<<"  ";
    }
    std::cout << "</" << tagName << ">" << std::endl; */

}

void Node::printNodeInFile(std::ofstream& of, int level, FileType file){
    if (tagName.empty()) {
        return;
    }
    if (tagName.back() == '/'){
        tagName.pop_back();
    }
    if (tagName.back() == ' '){
        tagName.pop_back();
    }

    switch (file) {
    case JSON: {

        for (int i = 0; i < level; i++) {
            of << "  ";
        }

        // name-Block
        of << "{\n";

        for (int i = 0; i < level + 1; i++) {
            of << "  ";
        }
        of << "\"name\": \"" << tagName << "\"";

        // children-Block
        if (children.empty()) {
            of << "\n";
            for (int i = 0; i < level; i++) {
                of << "  ";
            }
            of << "}";
        } else {
            of << ",\n";
            for (int i = 0; i < level + 1; i++) {
                of << "  ";
            }
            of << "\"children\": [\n";

            for (int i = 0; i < children.size(); i++) {
                children[i]->printNodeInFile(of, level + 1, file);
                if (i < children.size() - 1) {
                    of << ",\n";
                } else {
                    of << "\n";
                }
            }

            for (int i = 0; i < level + 1; i++) {
                of << "  ";
            }
            of << "]\n";

            for (int i = 0; i < level; i++) {
                of << "  ";
            }
            of << "}";
        }
    }        break;
    case NONE:{
        std::cout << "keine Datei" << std::endl;
        break;
    }

    default:
        break;
    }

}


void Node::deleteCildren(){
    for (Node* child : children){
        delete child;
    }
}

void Node::setAttribute(const std::string &name, const std::string &value){
    this -> Attribute[name] = value;

}

void Node::removeAttribute(const std::string &name){
    this ->Attribute.erase(name);
}

bool Node::hasAttribute(const std::string &name){
    if (this->Attribute.find(name) == this->Attribute.end()){
        return false;
    }
    return true;
}

std::string Node::getAttribute(const std::string &name){
    return Attribute.at(name);
}


int Node::getChildLen()
{
    return children.size();
}
