//#include <fstream>
#include <map>
//#include <iostream>

#include "xmlloader.h"
//#include "stack"
#include "InvalidOperationException.h"
#include "stack.h"
#include "InvalidOperationException.h"

XMLLoader::XMLLoader() {}

void XMLLoader::load(std::string file)
{

    std::map<std::string,std::string> attributes;
    Stack stack;
    TagType type;
    std::string line;
    std::string preline;
    std::ifstream ifs(file);
    if (ifs.is_open())
    {
        int zahl = 1;
        while (std::getline(ifs, line))
        {
            /*  [&] {
                for (int i = 0; i < line.size(); i++) {
                if (line[i]=='<' && line[i+1]=='?'){
                    return;
                }
            }
            }(); */
        /*    if (line[0]=='<' && line[1]=='?'){
                continue;
            }*/

            tagName(line, type);
            switch (type) {
            case END_TAG:
                if (stack.isEmpty()){
                    throw InvalidOperationException("Ein Push wurde versucht in line :" + std::to_string(zahl));
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
                        std::cout << line << std::endl;
                        return;
                    }

                }
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
                                std::cout <<zahl << "  "<< name << "  " << wert << std::endl;
                            }
                        }
                    }


                }

                preline = line;
                stack.push(line);
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
        if (!stack.isEmpty()){
            std::cout << "Falsch in line: " << zahl - 1 << std::endl;

            return;
        }
        std::cout << "Richtig\n";

        return;
    }
    throw std::runtime_error("Datei konnte nicht geöffnet werden \n");

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
