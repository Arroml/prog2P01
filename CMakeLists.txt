cmake_minimum_required(VERSION 3.16)

project(01Praktikum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01Praktikum main.cpp
    xmlloader.h xmlloader.cpp
    stack.h stack.cpp)

include(GNUInstallDirs)
install(TARGETS 01Praktikum
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
