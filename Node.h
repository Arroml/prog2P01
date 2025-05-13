//
// Created by Alexander Roman on 5/8/25.
//

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

class Node {
    std::string tagName;
    std::vector<Node*> children;
    public:
    Node(std::string name);
    ~Node();
    void addChild(Node* child);
    Node* removeChild();
    void printNode(int level = 0);
    void deleteCildren();
};



#endif //NODE_H
