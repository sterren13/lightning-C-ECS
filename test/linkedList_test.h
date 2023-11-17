//
// Created by arno on 17/11/23.
//

#ifndef ECS_LINKEDLIST_TEST_H
#define ECS_LINKEDLIST_TEST_H

#include "gtest/gtest.h"
#include "storage/linkedList.h"

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList_t list;

    void SetUp() override {
        linkedList_init(&list);
    }

    void TearDown() override {
        linkedList_free(&list);
    }
};

TEST_F(LinkedListTest, InitCreatesEmptyList) {
    EXPECT_EQ(linkedList_size(&list), 0);
}

TEST_F(LinkedListTest, PushIncreasesSize) {
    int data = 5;
    linkedList_push(&list, &data);
    EXPECT_EQ(linkedList_size(&list), 1);
}

TEST_F(LinkedListTest, InsertIncreasesSizeAndPreservesOrder) {
    int data1 = 5, data2 = 10;
    linkedList_push(&list, &data1);
    linkedList_insert(&list, &data2, 0);
    EXPECT_EQ(linkedList_size(&list), 2);
    EXPECT_EQ(*(int*)linkedList_get(&list, 0), data2);
    EXPECT_EQ(*(int*)linkedList_get(&list, 1), data1);
}

TEST_F(LinkedListTest, RemoveDecreasesSizeAndPreservesOrder) {
    int data1 = 5, data2 = 10;
    linkedList_push(&list, &data1);
    linkedList_push(&list, &data2);
    linkedList_remove(&list, 0);
    EXPECT_EQ(linkedList_size(&list), 1);
    EXPECT_EQ(*(int*)linkedList_get(&list, 0), data2);
}

TEST_F(LinkedListTest, GetReturnsCorrectData) {
    int data = 5;
    linkedList_push(&list, &data);
    EXPECT_EQ(*(int*)linkedList_get(&list, 0), data);
}

TEST_F(LinkedListTest, FrontReturnsFirstNode) {
    int data1 = 5, data2 = 10;
    linkedList_push(&list, &data1);
    linkedList_push(&list, &data2);
    EXPECT_EQ(*(int*)linkedList_front(&list)->data, data1);
}

TEST_F(LinkedListTest, NextReturnsNextNode) {
    int data1 = 5, data2 = 10;
    linkedList_push(&list, &data1);
    linkedList_push(&list, &data2);
    Node_t* firstNode = linkedList_front(&list);
    EXPECT_EQ(*(int*)linkedList_next(firstNode)->data, data2);
}

TEST_F(LinkedListTest, ClearEmptiesList) {
    int data = 5;
    linkedList_push(&list, &data);
    linkedList_clear(&list);
    EXPECT_EQ(linkedList_size(&list), 0);
}

#endif //ECS_LINKEDLIST_TEST_H
