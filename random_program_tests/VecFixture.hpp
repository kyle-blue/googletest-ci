//
// Created by kyle on 22/03/19.
//

#ifndef GOOGLETEST_1_INTRO_VECFIXTURE_HPP
#define GOOGLETEST_1_INTRO_VECFIXTURE_HPP


#include <gtest/gtest.h>
#include <vector>

class VecFixture: public ::testing::Test {
protected:
    std::vector<int> vec;

    virtual void SetUp() override {
        ASSERT_NE(vec, std::vector<int>()) << "vec shouldn't be empty" << std::endl;
    }
    virtual void TearDown() override {
    }

public:
    VecFixture()
            :vec{31,2,31,2,1} {}
    virtual ~VecFixture() = default;
};






#endif //GOOGLETEST_1_INTRO_VECFIXTURE_HPP
