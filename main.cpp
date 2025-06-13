#include "CSVLoader.h"
#include "InvalidOperationException.h"
#include "JSONLoader.h"
#include "csvwriter.h"
#include "jsonwriter.h".h "
#include "writer.h"
#include "xmlloader.h"
#include "xmlwriter.h".h "
#include <filesystem>
#include <iostream>
#include <map>
#include <string.h>

int main(int argv, char *argc[])
{
    if (argv > 3) {
        std::cout << "Bitte Dateinamen als Endung übergeben." << std::endl;
    }
    if (argv > 1 && argv < 3) {
        std::string fileName = argc[1];

        std::map<std::string, Loader *> registeredLoaders{{"csv", new CSVLoader},
                                                          {"json", new JSONLoader},
                                                          {"xml", new XMLLoader}};
        int pos = fileName.rfind('.');
        try {
            if (pos == std::string::npos) {
                throw std::runtime_error("ungültiger Datei Name");
            }
        } catch (std::runtime_error er) {
            std::cout << er.what();
        }

        std::string fileEnding = fileName.substr(pos + 1);
        Loader *loader = registeredLoaders.at(fileEnding);

        //loader->load("../../XML_test_files/"+fileName, 1);
        JsonWriter writer;
        writer.write(fileName);
    }

    int eingabe;
    std::string filename;
    std::string files;

    do {
        std::cout << "1       show all Files\n"
                  << "2       show specific File\n"
                  << "3       show one File\n"
                  << "4       Convert File\n"
                  << "0      Programm beenden\n";
        std::cin >> eingabe;
        switch (eingabe) {
        case 1: {
            std::map<std::string, Loader *> registeredLoaders{
                {"csv", new CSVLoader},
                {"json", new JSONLoader},
                {"xml", new XMLLoader},
            };
            std::vector<std::string> files{"basic.json",
                                           "broken1.xml",
                                           "broken2.xml",
                                           "broken3.xml",
                                           "broken4.xml",
                                           "broken5.xml",
                                           "broken6.xml",
                                           "broken7.xml",
                                           "broken8.xml",
                                           "broken9.xml",
                                           "valid1.xml",
                                           "valid2.xml",
                                           "valid3.xml",
                                           "stud.csv"};

            try {
                for (std::string &file : files) {
                    int pos = file.rfind('.');

                    std::string fileEnding = file.substr(pos + 1);
                    std::string baseName = file.substr(0, pos);

                    Loader *loader = registeredLoaders.at(fileEnding);

                    if (loader == nullptr) {
                        std::runtime_error er("loader Fehlgeschlagen");
                    }
                    std::cout << std::endl
                              << std::endl
                              << "eoffne neue File: " << file << std::endl;
                    loader->load("../../XML_test_files/" + file, 1);
                }
            } catch (std::runtime_error er) {
                std::cerr << er.what();
            } catch (InvalidOperationException e) {
                std::cerr << e.what();
            }
            break;
        }

        case 2: {
            XMLLoader loader;

            std::cout << "Filename (with datatype): ";
            std::cin >> filename;
            try {
                loader.load("../../XML_test_files/" + filename, 1);
            } catch (std::runtime_error er) {
                std::cerr << er.what();
            } catch (InvalidOperationException e) {
                std::cerr << e.what();
            }
            break;
        }

        case 3: {
            XMLLoader loader;
            std::string filename = "broken7";
            try {
                loader.load("../../XML_test_files/" + filename + ".xml", 1);
            } catch (std::runtime_error er) {
                std::cerr << er.what();
            } catch (InvalidOperationException e) {
                std::cerr << e.what();
            }
        } break;
        case 4: {
            std::vector<std::string> files{ "valid3.xml"}; // "valid1.xml", "valid2.xml",
            std::string filetype;

            for (auto file : files) {
                int stelle = file.find('.');
                std::string fileEnding = file.substr(stelle + 1);
                std::string fileStart = file.substr(0, stelle);
                std::cout<<"Json oder XML (all small)?"<<std::endl;
                std::cin>>filetype;
                if (filetype == "json") {
                    JsonWriter writer;
                    if(writer.write(file)){
                        std::cout<<"Writing Complete!\n";
                    }
                    else{
                        std::cout<<"ERROR in Writing\n";
                    }
                }
                if (filetype == "xml"){
                    XMLWriter writer;
                    if(writer.write(file)){
                        std::cout<<"Writing Complete!\n";
                    }
                    else{
                        std::cout<<"ERROR in Writing\n";
                    }
                }
            }
        }
        break;
        case 0:
            std::cout << "Programm wird beendet\n";
            break;
        default:
            std::cout << "ungeültige Eingabe";
            break;
        }
    } while (eingabe);

    return 0;
}
