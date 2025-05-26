//
// Created by Alexander Roman on 5/8/25.
//

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <map>

class Node {
    std::string tagName;
    std::vector<Node*> children;
    std::map<std::string,std::string> Attribute;
    enum FileType {NONE, CSV, JSON, XML};

    public:
    Node(std::string name);
    ~Node();
    void addChild(Node* child);
    Node* removeChild();
    void printNode(std::ofstream &os,int level = 0, FileType = NONE);
    void deleteCildren();

    void setAttribute(const std::string &name, const std::string &value);
    void removeAttribute(const std::string &name);
    bool hasAttribute(const std::string &name);
    std::string getAttribute(const std::string &name);
    void printAttributes(std::ostream& out, int level = 0);
};



#endif //NODE_H
