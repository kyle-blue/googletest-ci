//
// Created by kyle on 23/03/19.
//

#ifndef GOOGLETEST_1_INTRO_VALUEPARAMETERISEDTEST_HPP
#define GOOGLETEST_1_INTRO_VALUEPARAMETERISEDTEST_HPP

#include <gtest/gtest.h>
#include <type_traits>

#include "Stack.hpp"


                //OR; : public testing::Test, testing::WithParamInterface<int>
class StackPTest: public testing::TestWithParam<int> { //Template arg must be specified to define behaviour of parameter generators
protected:
    int num;
    Stack<int> stack;

public:
    StackPTest():  num(GetParam()) { //Get input data from param generator for this iteration
        stack.push(num);
    }
    ~StackPTest() = default;
};


//Must later instantiate value param test suites. Can be done anywhere after 'StackPTest' declaration
INSTANTIATE_TEST_SUITE_P(oddStack,
                         StackPTest,
                         testing::Range(1, 10, 2));
//INSTANTIATE_TEST_SUITE_P(evenStack,
//                         StackPTest,
//                         testing::Range(2, 10, 2));


#endif //GOOGLETEST_1_INTRO_VALUEPARAMETERISEDTEST_HPP
