//
// Created by kyle on 19/03/19.
//

#ifndef GOOGLETEST_1_INTRO_STACK_H
#define GOOGLETEST_1_INTRO_STACK_H

#include <vector>

template <typename T>
class Stack {
std::vector<T> items;

public:
    void push(T item);
    void push();
    T pop();
    T &back();
    size_t size();
};


#include "Stack.tpp"

#endif //GOOGLETEST_1_INTRO_STACK_H
