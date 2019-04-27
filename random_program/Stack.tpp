//
// Created by kyle on 19/03/19.
//

#include "Stack.hpp"

template<typename T>
void Stack<T>::push(T item) {
    items.push_back(item);
}

template<typename T>
void Stack<T>::push() {
    items.emplace_back();
}

template<typename T>
T Stack<T>::pop() {
    T backItem = back();
    items.pop_back();
    return backItem;
}

template<typename T>
T &Stack<T>::back() {
    return items.back();
}

template<typename T>
size_t Stack<T>::size() {
    return items.size();
}


