#include <gtest/gtest.h>

#include "vec.h"

/*
* test vec_init
* ec_size
* vec_capacity
* vec_resize_t
* vec_append_t
* vec_remove_t
* vec_clear
* vec_get_t
* vec_set_t
* vec_front_t
* vec_back_t
* vec_remove_back_t
*/

class VectorTest : public ::testing::Test {
protected:
    vec_t v;

    void SetUp() override {
        vec_init_t(&v, 10, int);
    }

    void TearDown() override {
        vec_free(&v);
    }
};

TEST_F(VectorTest, InitTest) {
    EXPECT_EQ(v.size, 0) << "Size is not 0 after initialization";
    EXPECT_EQ(v.capacity, 10) << "Capacity is not 10 after initialization";
    #ifdef SIZE_CHECK
    EXPECT_EQ(v.elemSize, sizeof(int)) << "Element size is not sizeof(int) after initialization";
    #endif
    EXPECT_NE(v.data, nullptr) << "Data is null after initialization";
}

TEST_F(VectorTest, SizeCapacityTest) {
    EXPECT_EQ(vec_size(&v), 0);
    EXPECT_EQ(vec_capacity(&v), 10);
}

TEST_F(VectorTest, ResizeTest) {
    vec_resize_t(&v, 20, int);
    EXPECT_EQ(v.capacity, 20) << "Capacity is not 20 after resize";
}

TEST_F(VectorTest, AppendTest) {
    int value = 5;
    vec_append_t(&v, &value, int);
    EXPECT_EQ(v.size, 1) << "Size is not 1 after append";
    EXPECT_EQ(*vec_get_t(&v, 0, int), value) << "Value is not 5 after append";
}

TEST_F(VectorTest, AppendResizeTest) {
    for (int i = 0; i < 20; i++) {
        vec_append_t(&v, &i, int);
    }
    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(*vec_get_t(&v, i, int), i) << "Value is not " << i << " after append";
    }
    EXPECT_EQ(v.size, 20) << "Size is not 20 after append";
    EXPECT_GT(v.capacity, 19) << "Capacity is not 20 after append";
}

TEST_F(VectorTest, RemoveTest) {
    int value = 5;
    vec_append_t(&v, &value, int);
    value++;
    vec_append_t(&v, &value, int);
    value++;
    vec_append_t(&v, &value, int);
    EXPECT_EQ(vec_remove_t(&v, 0, int), 1) << "Remove failed";
    EXPECT_EQ(v.size, 2) << "Size is not 0 after remove";
    EXPECT_EQ(*vec_get_t(&v, 0, int), value) << "Get last value failed";
    vec_append_t(&v, &value, int);
    EXPECT_EQ(vec_remove_t(&v, 10, int), 0) << "Remove out of bound";
}

TEST_F(VectorTest, ClearTest) {
    int value = 5;
    vec_append_t(&v, &value, int);
    vec_clear(&v);
    EXPECT_EQ(v.size, 0) << "Size is not 0 after clear";
}

TEST_F(VectorTest, GetTest) {
    int value = 5;
    vec_append_t(&v, &value, int);
    EXPECT_EQ(*vec_get_t(&v, 0, int), value) << "Retrieved value is not correct";
}

TEST_F(VectorTest, SetTest) {
    int value = 5;
    vec_append_t(&v, &value, int);
    int newValue = 10;
    vec_set_t(&v, 0, &newValue, int);
    EXPECT_EQ(*vec_get_t(&v, 0, int), newValue) << "Set value is not correct";
}

TEST_F(VectorTest, FrontBackTest) {
    int value1 = 5;
    int value2 = 10;
    vec_append_t(&v, &value1, int);
    vec_append_t(&v, &value2, int);
    EXPECT_EQ(*vec_front_t(&v, int), value1);
    EXPECT_EQ(*vec_back_t(&v, int), value2);
}

TEST_F(VectorTest, RemoveBackTest) {
    int value1 = 5;
    int value2 = 10;
    vec_append_t(&v, &value1, int);
    vec_append_t(&v, &value2, int);
    int* removedValue = vec_remove_back_t(&v, int);
    EXPECT_EQ(*removedValue, value2);
    EXPECT_EQ(v.size, 1);
}

TEST_F(VectorTest, RemoveBackLimitTest){
    for (int i = 0; i < 10; i++) {
        vec_append_t(&v, &i, int);
    }
    for (int i = 0; i < 11; i++){
        int* removedValue = vec_remove_back_t(&v, int);
        if (i < 10) {
            EXPECT_EQ(*removedValue, 9 - i);
            EXPECT_EQ(v.size, 9 - i);
        } else {
            EXPECT_EQ(removedValue, nullptr);
            EXPECT_EQ(v.size, 0);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}