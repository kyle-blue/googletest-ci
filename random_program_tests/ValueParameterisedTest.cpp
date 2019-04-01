//
// Created by kyle on 23/03/19.
//

#include "ValueParameterisedTest.hpp"

TEST_P(StackPTest, push){
    ASSERT_LT(0, stack.size());

    //Wierd ass test for odds and evens
    const bool IS_ODD = (stack.back() % 2);
    EXPECT_TRUE(IS_ODD) << stack.back() << ": should be an odd number. BUT ITS NOT!";
}


