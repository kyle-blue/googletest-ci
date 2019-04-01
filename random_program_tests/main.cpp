#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>


int main(int argc, char *argv[]) {
    std::cout << "\nRUNNING ALL TESTS:\n" << std::endl;

    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

//ToDo: At some point, lookup how to search for memory leaks (possibly using gtest and google listener API)