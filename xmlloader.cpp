#include <map>
#include "xmlloader.h"
#include "InvalidOperationException.h"
#include "stack.h"
#include "InvalidOperationException.h"
#include "Node.h"

XMLLoader::XMLLoader() {}

std::string XMLLoader::getTagName(std::string oldName){
    int i = 0;
    std::string newName;
    while(oldName[i] != '<'){
        i++;
    }
    i++;
    while(oldName[i] != '>'){
        newName+=oldName[i];
        i++;
    }
    // std::cout << newName;
    return newName;
}

void XMLLoader::load(std::string file, int flag)
{
    Node::FileType fileType = Node::FileType::XML;

    std::ofstream of;

    std::vector<Node*> nodestack;

    std::map<std::string,std::string> attributes;
    Stack stack;
    TagType type;
    std::string line;
    std::string preline;
    std::ifstream ifs(file);
    if (ifs.is_open())
    {
        int zahl = 1;
        std::cout<<"Loading XML"<<std::endl;
        while (std::getline(ifs, line))
        {

            tagName(line, type);
            switch (type) {
            case END_TAG:
                if (stack.isEmpty()){
                    std::cout << "ein Push wurde versucht" << std::endl;
                    return;
                }
                if (! stack.isEmpty()){
                    std::string comp1, comp2;
                    std::string lastPush = stack.pop();
                    int i = 0;
                    while(lastPush[i] != '<' && i <= lastPush.size()){
                        i++;
                    }
                    i++;
                    while(lastPush[i] != ' ' && lastPush[i] != '>' && i <= lastPush.size()){
                        comp1 += lastPush[i];
                        i++;
                    }

                    i = 0;
                    while (line[i] != '<' && i < lastPush.size()){
                        i++;
                    }
                    i++;
                    i++;
                    while (line[i] != ' ' && line[i] != '>' && i <= line.size()){
                        comp2 += line[i];
                        i++;
                    }


                    if (comp1 != comp2){

                        std::cout<<"Falsch in line : " << zahl-1 << std::endl;
                        std::cout << line << std::endl << std::endl;

                        //   this->root->printNode();
                        delete root;
                        return;
                    }


                }
                nodestack.pop_back();
                preline = line;
                zahl ++;
                break;

            case SELF_CLOSING:{

                for (int i = 0; i < line.size(); i++){
                    if (line[i] == '<'){
                        for (int j = i; j<line.size(); j++){
                            if (line[j] == ' ' && line[j+1] != '/'){
                                j++;
                                std::string name, wert;
                                while (line[j] != '=' && j < line.size()){
                                    name += line[j];
                                    j++;
                                }
                                j++;
                                j++;
                                while (line[j] != '"' && j < line.size()){
                                    wert += line[j];
                                    j++;
                                }
                                std::cout << zahl << "  " << name << "  " << wert << std::endl;

                            }
                        }
                    }
                }

                preline = line;

                std::string newName = this->getTagName(line);
                Node *newNode = new Node(newName);
                nodestack.back()->addChild(newNode);

                zahl ++;
                break;
            }

            case NONE:
                zahl ++;
                break;

            case START_TAG:{


                for (int i =0; i < line.size(); i++){
                    if (line [i] == '<'){
                        for (int j = i; j<line.size(); j++){

                            if (line[j] == ' '){
                                j++;
                                std::string name, wert;
                                while (line[j] != '=' && j < line.size()){
                                    name += line[j];
                                    j++;
                                }
                                j++;
                                j++;
                                while (line[j] != '"' && j < line.size()){
                                    wert += line[j];
                                    j++;
                                }
                            }
                        }
                    }


                }

                preline = line;

                stack.push(line);
                std::string newName = this->getTagName(line);
                Node *newNode = new Node(newName);
                if (nodestack.empty()){
                    root = newNode;
                }else{
                    nodestack.back()->addChild(newNode);
                }
                nodestack.push_back(newNode);
                zahl ++;
                break;
            }
            case KOMENTAR:
                zahl ++;
                break;

            default:
                std::cout << "Falsche Eingabe\n";
            }
        }

        if (!stack.isEmpty() && flag == 0){
            std::cout << "Falsch in line: " << zahl - 1 << std::endl;


            this->root->printNode(of, 0, fileType);
            delete root;
            return;

        }
        std::cout << "Richtig\n";


        if (flag == 1){

            this->root->printNode(of, 0, fileType);

        } if (flag == 2) {
            std::cout << "Richtig\n";
            std::ofstream ofs("bla.json");
            this->root->printNode(ofs);
        }


        return;
    }
    throw std::runtime_error("Datei konnte nicht geoeffnet werden \n");

}

void XMLLoader::tagName(std::string line, TagType & type){

    if (line.empty()){
        type = NONE;
        return;
    }
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '<')
        {
            if (line[i+1] == '/'){


                type = END_TAG;
                return;
            }
            if (line[i+1] == '!' && line[i+2] == '-' && line[i+3] == '-'){
                type = KOMENTAR;
                return;
            }

            while(line[i] != '>' && i <= line.size())
            {
                if (line[i] == '/' && line[i+1] == '>'){
                    type = SELF_CLOSING;
                    return;
                }

                if (line[i] == '/'){
                    type = SELF_CLOSING;

                    return;
                }

                i++;
            }
            type = START_TAG;
            return;
        }
    }
}
