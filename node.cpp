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
