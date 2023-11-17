cmake_minimum_required(VERSION 3.10)
project(ECS)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 23)

# Voeg -O3 toe aan CXX_FLAGS (voor C++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -funroll-loops -flto")

# Voeg -O3 toe aan C_FLAGS (voor C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native -funroll-loops -flto")

# Add an option to enable testing
option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLE "Build example" ON)
option(BUILD_BENCHMARKS "Build benchmarks" ON)

# Find Google Test if testing is enabled
if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    include_directories()
endif()

if (BUILD_BENCHMARKS)
    find_package(benchmark REQUIRED)
endif()


# Add your source files here
set(SOURCE_FILES_HASH
        src/Hash/hashFunctions.c
        src/Hash/xxhash.c
        src/Hash/City.c
)
set(SOURCE_FILES_STORAGE
        src/storage/vec.c
        src/storage/staticHashmap.c
        src/storage/linkedList.c
)
set(SOURCE_FILES_ECS
        src/ECS/register.c
        src/ECS/table.c
    )

# Create the static library
add_library(ECS STATIC ${SOURCE_FILES} ${SOURCE_FILES_STORAGE} ${SOURCE_FILES_HASH} ${SOURCE_FILES_ECS})
target_include_directories(ECS PUBLIC include)

# Create the test executable if testing is enabled
if(BUILD_TESTS)
    set(TEST_FILES 
        test/test.cpp
    )
    add_executable(runUnitTests ${TEST_FILES})
    target_link_libraries(runUnitTests ECS ${GTEST_BOTH_LIBRARIES} pthread)
    target_include_directories(runUnitTests PRIVATE ${GTEST_INCLUDE_DIRS})
endif()

if (BUILD_EXAMPLE)
    set(SOURCE_FILES_EXAMPLES
        example/src/main.c
        )
    add_executable(example ${SOURCE_FILES_EXAMPLES})
    target_link_libraries(example ECS)
    target_include_directories(example PRIVATE example/include)
endif()

if (BUILD_BENCHMARKS)
    set(BENCHMARK_FILES
        benchmarks/benchmarks.cpp
        benchmarks/vec_benchmarks.h
        )
    add_executable(runBenchmarks ${BENCHMARK_FILES})
    target_link_libraries(runBenchmarks benchmark ECS)
endif()
