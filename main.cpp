#include <filesystem>
#include <iostream>
#include <string.h>
#include "xmlloader.h"
//#include "stack"


int main()
{
    int eingabe;
    std::string filename;
    do{
        std::cout <<"1       show File\n"
                  <<"0      Programm beenden\n";
        std::cin>>eingabe;
        switch (eingabe) {
        case 1:
        {
            XMLLoader loader;

            std::cout<<"Filename (without datatype): ";
            std::cin>>filename;
            try {
                loader.load("../../XML_test_files/"+filename+".xml");
            } catch (std::runtime_error er) {
                std::cerr<<er.what();
            }
            break;
        }
        case 0:
            std::cout<<"Programm wird beendet\n";
            break;
        default:
            std::cout<<"ungeültige Eingabe";
            break;
        }
    }while(eingabe);

    return 0;
}
