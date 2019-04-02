Its recommended to compile the googltest (and googlemock)
library with each project by including the source files:

This is because every user needs to compile the tests they created
using the same compiler flags used to compile the installed 
gtest/gmock libraries; otherwise he may run into undefined behaviors
(i.e. the tests can behave strangely and may even crash for no
obvious reasons).

like:

add_library(gtest ${GTEST_DIR}/gtest-all.cc)
add_library(gtest ${GMOCK_DIR}/gtest-all.cc)

target_include_directories(gtest /usr/local/lib/include/ ${GTEST_DIR})
target_include_directories(gtest /usr/local/lib/include/ ${GMOCK_DIR})

