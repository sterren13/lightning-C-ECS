#include <gtest/gtest.h>
#include "vec.h"

class VectorTest : public ::testing::Test {
protected:
    vec_t v;

    void SetUp() override {
        vec_init(&v, 10, sizeof(int));
    }

    void TearDown() override {
        vec_free(&v);
    }
};

TEST_F(VectorTest, InitTest) {
    EXPECT_EQ(v.size, 0);
    EXPECT_EQ(v.capacity, 10);
    EXPECT_EQ(v.elemSize, sizeof(int));
    EXPECT_NE(v.data, nullptr);
}

TEST_F(VectorTest, ResizeTest) {
    vec_resize(&v, 20, sizeof(int));
    EXPECT_EQ(v.capacity, 20);
}

TEST_F(VectorTest, AppendTest) {
    int value = 5;
    vec_append(&v, &value, sizeof(int));
    EXPECT_EQ(v.size, 1);
    EXPECT_EQ(*(int*)vec_get(&v, 0, sizeof(int)), value);
}

TEST_F(VectorTest, RemoveTest) {
    int value = 5;
    vec_append(&v, &value, sizeof(int));
    vec_remove(&v, 0, sizeof(int));
    EXPECT_EQ(v.size, 0);
}

TEST_F(VectorTest, ClearTest) {
    int value = 5;
    vec_append(&v, &value, sizeof(int));
    vec_clear(&v);
    EXPECT_EQ(v.size, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}