//
// Created by kyle on 19/03/19.
//

#include "Interpreter.hpp"
#include <iostream>
#include <fstream>

void Interpreter::readFile(const std::string &fileName) {
    try{
        tryReadFile(fileName);
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}

void Interpreter::tryReadFile(const std::string &fileName) {
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open())
        throw noFileException();
    while(inputFile.good())
        addNextLineToFileItems(inputFile);
}

const char *Interpreter::noFileException::what() const noexcept {
    return "\nCOULD NOT READ FILE\n";
}

inline void Interpreter::addNextLineToFileItems(std::ifstream &inputFile) {
    fileItems.push();
    std::getline(inputFile, fileItems.back());
}

Stack<std::string> &Interpreter::getFileItems() {
    return fileItems;
}

void Interpreter::printAndRemoveFileItems() {
    for(size_t i = fileItems.size(); i > 0; --i)
        std::cout << "Item " << i << ": " << fileItems.pop() << std::endl;
}

void Interpreter::removeFileItems() {
    for(size_t i = fileItems.size(); i > 0; --i)
        fileItems.pop();
}