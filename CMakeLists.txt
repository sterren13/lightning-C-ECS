cmake_minimum_required(VERSION 3.10)
project(ECS)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an option to enable testing
option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" OFF)

# Find Google Test if testing is enabled
if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
endif()

# Add your source files here
set(SOURCE_FILES 
    src/vec.c
    )

# Create the static library
add_library(ECS STATIC ${SOURCE_FILES})
target_include_directories(ECS PUBLIC include)

# Create the test executable if testing is enabled
if(BUILD_TESTS)
    set(TEST_FILES 
        test/test.cpp
    )
    add_executable(runUnitTests ${TEST_FILES})
    target_link_libraries(runUnitTests ECS ${GTEST_BOTH_LIBRARIES} pthread)
endif()

#if (BUILD_EXAMPLES)
#    set(SOURCE_FILES_EXAMPLES
#        example/src/vec.c
#        )
#    add_executable(example ${SOURCE_FILES_EXAMPLES})
#    target_link_libraries(example ECS)
#endif()