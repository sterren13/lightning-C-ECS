//
// Created by arno on 17/11/23.
//
#include "storage/linkedList.h"

void linkedList_init(LinkedList_t* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void linkedList_free(LinkedList_t* list) {
    if (list->head == NULL)
        return;
    for (Node_t* node = linkedList_front(list); node != NULL;) {
        Node_t* next = node->next;
        free(node);
        node = next;
    }
}

void linkedList_push(LinkedList_t* list, void* data) {
    Node_t* node = (Node_t*)malloc(sizeof(Node_t));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void linkedList_insert(LinkedList_t* list, void* data, size_t index) {
    Node_t* node = (Node_t*)malloc(sizeof(Node_t));
    node->data = data;
    if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        Node_t* prev = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }
    list->size++;
}

void linkedList_remove(LinkedList_t* list, size_t index) {
    if (index == 0) {
        Node_t* node = list->head;
        list->head = node->next;
        free(node);
    } else {
        Node_t* prev = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        Node_t* node = prev->next;
        prev->next = node->next;
        free(node);
    }
    list->size--;
}

void* linkedList_get(LinkedList_t* list, size_t index) {
    Node_t* node = list->head;
    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

Node_t* linkedList_front(LinkedList_t* list) {
    return list->head;
}

Node_t* linkedList_next(Node_t* data) {
    return data->next;
}

size_t linkedList_size(LinkedList_t* list) {
    return list->size;
}

void linkedList_clear(LinkedList_t* list) {
    linkedList_free(list);
    linkedList_init(list);
}