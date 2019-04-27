//
// Created by kyle on 22/03/19.
//

#ifndef GOOGLETEST_1_INTRO_TYPEDTEST_HPP
#define GOOGLETEST_1_INTRO_TYPEDTEST_HPP

#include <gtest/gtest.h>
#include <vector>
#include "Stack.hpp"

namespace StackTests{
    //Fixture////
    //It may be also be useful for testing for each inherited classes
    using numerical = testing::Types<int, float>; //This is necessary, as macro will pass commas as extra macro args
    TYPED_TEST_SUITE(StackTest, numerical);



    template <typename T>
    class StackTest: public testing::Test {
    protected:
        Stack<T> stack;
    public:
        static std::vector<T> items; //Manipulated outside definition

        StackTest(){
            for(T &item: items){
                stack.push(item);
            }
        };
        virtual ~StackTest() = default;
    };

    template <>
    std::vector<int> StackTest<int>::items{12,31,23,1,23,1};
    template <>
    std::vector<float> StackTest<float>::items{12.213f,31.1f,23.1f,1.2f,23.4f,1.0f};


}





#endif //GOOGLETEST_1_INTRO_TYPEDTEST_HPP
