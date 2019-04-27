#include <iostream>

#include "Interpreter.hpp"

int main() {
    std::string fileName = "Foods.txt";
    Interpreter interpreter;

    interpreter.readFile(fileName);
    interpreter.printAndRemoveFileItems();

    return 0;
}