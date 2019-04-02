function(linkGTestAndGMock EXE)
    if (TARGET ${EXE})
        set(GTEST_DIR lib/gtest/)
        set(GMOCK_DIR lib/gmock/)

        #Must compile libary separately for each project. Read 'ReadMe.txt' in lib folder for details
        add_library(gtest ${GTEST_DIR}/src/gtest-all.cc)
        add_library(gmock ${GMOCK_DIR}/src/gmock-all.cc)

        target_include_directories(gtest PUBLIC include/ ${GTEST_DIR})
        target_include_directories(gmock PUBLIC include/ ${GMOCK_DIR})

        target_link_libraries(${EXE} gtest gmock)

        if (UNIX)
            target_link_libraries(${EXE} pthread) #gtest requires pthread on unix
        endif ()

    else ()
        message("No valid target executable passed to linkGTestAndMock(EXE)")
    endif()
endfunction()