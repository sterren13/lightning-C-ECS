//
// Created by arno on 17/11/23.
//

#ifndef ECS_LINKEDLIST_H
#define ECS_LINKEDLIST_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>

typedef struct Node_t {
    void *data;
    struct Node_t *next;
} Node_t;

typedef struct {
    Node_t *head;
    Node_t *tail;
    size_t size;
} LinkedList_t;

void linkedList_init(LinkedList_t *list);

void linkedList_free(LinkedList_t *list);

void linkedList_push(LinkedList_t *list, void *data);

#define linkedList_push_t(list, data, type) \
    linkedList_push(list, data)

void linkedList_insert(LinkedList_t *list, void *data, size_t index);

#define linkedList_insert_t(list, data, index, type) \
    linkedList_insert(list, data, index)

void linkedList_remove(LinkedList_t *list, size_t index);

void *linkedList_get(LinkedList_t *list, size_t index);

#define linkedList_front_t(list, type) \
    ((type*)linkedList_front(list)->data)

Node_t *linkedList_front(LinkedList_t *list);

Node_t *linkedList_next(Node_t *data);

size_t linkedList_size(LinkedList_t *list);

void linkedList_clear(LinkedList_t *list);

#ifdef __cplusplus
}
#endif
#endif //ECS_LINKEDLIST_H
