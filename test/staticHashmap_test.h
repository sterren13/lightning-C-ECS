//
// Created by arno on 11/13/23.
//

#ifndef ECS_STATICHASHMAP_TEST_H
#define ECS_STATICHASHMAP_TEST_H
#include "gtest/gtest.h"
#include "storage/staticHashmap.h"

class StaticHashmapTest : public ::testing::Test {
protected:
    StaticHashmap_t map;
    StaticHashmap_entry_t entries[2] = {
            {123, (void*)456},
            {789, (void*)012}
    };

    void SetUp() override {
        StaticHashmap_init(entries, 2, &map);
    }

    void TearDown() override {
        StaticHashmap_free(&map);
    }
};

TEST_F(StaticHashmapTest, InitCreatesMapWithEntries) {
    EXPECT_EQ(map.size, 2);
    EXPECT_TRUE(StaticHashmap_has(&map, 123));
    EXPECT_TRUE(StaticHashmap_has(&map, 789));
}

TEST_F(StaticHashmapTest, GetReturnsCorrectValue) {
    void* value = StaticHashmap_get(&map, 123);
    EXPECT_EQ(value, (void*)456);
}

TEST_F(StaticHashmapTest, HasReturnsTrueForExistingKey) {
    int hasKey = StaticHashmap_has(&map, 123);
    EXPECT_TRUE(hasKey);
}

TEST_F(StaticHashmapTest, FreeDestroysMap) {
    StaticHashmap_free(&map);

    EXPECT_EQ(map.size, 0);
    EXPECT_EQ(map.bukkets, nullptr);
}

TEST_F(StaticHashmapTest, InitWithNullCreatesEmptyMap) {
    StaticHashmap_init(nullptr, 0, &map);

    EXPECT_EQ(map.size, 0);
    EXPECT_EQ(map.bukkets, nullptr);
}

#endif //ECS_STATICHASHMAP_TEST_H
