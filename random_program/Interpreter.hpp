//
// Created by kyle on 19/03/19.
//

#ifndef GOOGLETEST_1_INTRO_INTERPRETER_H
#define GOOGLETEST_1_INTRO_INTERPRETER_H

#include <vector>
#include <string>
#include <exception>
#include "Stack.hpp"

class Interpreter {
    Stack<std::string> fileItems;

    inline void addNextLineToFileItems(std::ifstream &inputFile);
    void tryReadFile(const std::string &fileName);

    class noFileException;
public:
    void readFile(const std::string &fileName);
    Stack<std::string> &getFileItems();
    void printAndRemoveFileItems();
    void removeFileItems();
};

class Interpreter::noFileException: public std::exception{
    virtual const char *what() const noexcept override;
};

#endif //GOOGLETEST_1_INTRO_INTERPRETER_H
