#include <gtest/gtest.h>
#include "vec_test.h"
#include "staticHashmap_test.h"
#include "linkedList_test.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}