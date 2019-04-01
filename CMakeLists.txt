cmake_minimum_required(VERSION 3.00)
project(googletest_1___intro)

set(CMAKE_CXX_STANDARD 17)

set(RANDOM_DIR "${CMAKE_CURRENT_LIST_DIR}/random_program/")
set(RANDOM_TESTS_DIR "${CMAKE_CURRENT_LIST_DIR}/random_program_tests/")
set(RANDOM_BIN_DIR "${RANDOM_DIR}/cmake-build-debug/")
set(RANDOM_TESTS_BIN_DIR "${RANDOM_TESTS_DIR}/cmake-build-debug/")

#args: src_dir, bin_dir
add_subdirectory(${RANDOM_DIR} ${RANDOM_BIN_DIR})
add_subdirectory(${RANDOM_TESTS_DIR} ${RANDOM_TESTS_BIN_DIR})