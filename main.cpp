#include <filesystem>
#include <iostream>
#include "xmlloader.h"
#include "stack"


int main()
{
    std::cout <<"1       show File\n"
              <<"0      Programm beenden\n";
    int eingabe;
    do{
        std::cin>>eingabe;
        switch (eingabe) {
        case 1:
        {
            XMLLoader loader;
            try {
                loader.load("../../XML_test_files/valid1.xml");
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
