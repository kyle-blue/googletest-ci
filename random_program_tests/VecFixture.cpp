//
// Created by kyle on 22/03/19.
//

#include "VecFixture.hpp"


TEST_F(VecFixture, push_back){
    size_t vecSizeBefore = vec.size();
    vec.push_back(1);

    EXPECT_EQ(1, vec.back()) << "SHOULD BE EQUAL (test reversed for experimental purposes";
    EXPECT_GT(vec.size(), vecSizeBefore) << "SHOULD BE MORE THAN (test reversed for experimental purposes";
}