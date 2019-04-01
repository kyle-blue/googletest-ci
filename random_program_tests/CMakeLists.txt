include(LinkLibs.cmake)

cmake_minimum_required(VERSION 3.00)
project(random_program_tests)

set(CMAKE_CXX_STANDARD 17)
set(EXE random_program_tests)

add_executable(${EXE} main.cpp TypedTest.cpp VecFixture.cpp ValueParameterisedTest.cpp Mocking.cpp)

get_filename_component(PARENT_DIR "${CMAKE_CURRENT_LIST_DIR}" DIRECTORY) #Get directory 1 above current (like doing 'cd ..')
set(MAIN_INCLUDE_DIRECTORY ${PARENT_DIR}/random_program/)
target_include_directories(${EXE} PRIVATE "${MAIN_INCLUDE_DIRECTORY}")

linkGTestAndGMock(${EXE})