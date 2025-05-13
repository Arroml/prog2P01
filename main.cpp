#include <filesystem>
#include <iostream>
#include <string.h>
#include "xmlloader.h"
#include "InvalidOperationException.h"


int main() {
    int eingabe;
    std::string filename;
    std::string files;


    do {
        std::cout<<"1       show all Files\n"
                << "2       show specific File\n"
            << "3       show one File\n"
                << "0      Programm beenden\n";
        std::cin >> eingabe;
        switch (eingabe) {
            case 1: {
                XMLLoader loader;
                for (const auto &entry: std::filesystem::directory_iterator("../../XML_test_files/")) {
                    if (entry.path().extension() == ".xml") {
                        std::cout << entry.path().string() << std::endl << std::endl;
                        try {
                            loader.load(entry.path().string());
                            std::cout << std::endl << std::endl;
                        } catch (std::runtime_error er) {
                            std::cerr << er.what();
                        }
                    }
                }
                break;
            }

            case 2: {
                XMLLoader loader;

                std::cout << "Filename (without datatype): ";
                std::cin >> filename;
                try {
                    loader.load("../XML_test_files/" + filename + ".xml");
                } catch (std::runtime_error er) {
                    std::cerr << er.what();
                } catch (InvalidOperationException e) {
                    std::cerr << e.what();
                }
                break;
            }

            case 3:{
                XMLLoader loader;
                std::string filename = "valid1";
                try {
                    loader.load("../../XML_test_files/" + filename + ".xml");
                } catch (std::runtime_error er) {
                    std::cerr << er.what();
                } catch (InvalidOperationException e) {
                    std::cerr << e.what();
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
