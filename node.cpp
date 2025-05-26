#include "Node.h"

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

void Node::printNode(int level) {
    for (int i = 0; i < level; i++) {
        std::cout << "  ";
    }
    std::cout << tagName << std::endl;

    for (Node* child : children) {
        child->printNode(level + 1);
    }
   /* for(int i = 0; i<level; i++){
        std::cout<<"  ";
    }
    std::cout << "</" << tagName << ">" << std::endl; */

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



