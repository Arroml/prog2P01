#include "Node.h"
#include <fstream>
#include <sstream>

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

    if (tagName == "?xml version=\"1.0\" encoding=\"UTF-8\"?"){
        for (auto child : children){

            child->printNodeInFile(of, level + 1, file);
        }
    }


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
        int leerzeichen= tagName.find(' ');
        if (leerzeichen != std::string::npos){
            std::string baseName = tagName.substr(0, leerzeichen);
            std::string rest = tagName.substr(leerzeichen + 1);
            tagName = baseName;
            std::stringstream ss(rest);
            std::string part;
            while (ss >> part){
                int gleich = part.find('=');
                if (gleich != std::string::npos){
                    std::string begin = part.substr(0, gleich);
                    std::string end = part.substr(gleich +1);
                    Attribute[begin] = end;
                }
            }
        }



        for (int i = 0; i < level; i++) {
            of << "  ";
        }
        of << "{\n";
        for (int i = 0; i < level + 1; i++) {
            of << "  ";
        }
        of << "\"name\": \"" << tagName << "\"";
        if (children.empty()) {
            of << "\n";
            for (int i = 0; i < level; i++) {
                of << "  ";
            }
            of << "}";
        } else {
            of << ",\n";

            if (!Attribute.empty()){

                for (auto atribute:Attribute){

                    for (int i = 0; i < level; i++) {
                        of << "  ";
                    }
                    of << "\"" << atribute.first << "\":" << " " <<atribute.second;
                    of << "\n";
                }
            }
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

    }        break;
    }
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
