//
// Created by kyle on 22/03/19.
//

#include "TypedTest.hpp"

namespace StackTests{

    TYPED_TEST(StackTest, numerical){
        EXPECT_LT(0, this->stack.size());

        //TypeParam is a special alias for the type of the template
        TypeParam back = this->stack.back();
        EXPECT_LT(0, back);
    }
}
