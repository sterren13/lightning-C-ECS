//
// Created by arno on 9/11/23.
//

#ifndef ECS_STATICHASHMAP_H
#define ECS_STATICHASHMAP_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "vec.h"

typedef struct {
    uint64_t key; // key of entry
    void *value; // pointer to value
} StaticHashmap_entry_t;

typedef struct StaticHashmap_t {
    uint32_t size;
    uint32_t capacity;
    vec_t *bukkets; // vec of bukket_t
} StaticHashmap_t;

void StaticHashmap_init(StaticHashmap_entry_t *entries, uint32_t size, StaticHashmap_t *map);

void *StaticHashmap_get(StaticHashmap_t *map, uint64_t key);

void StaticHashmap_free(StaticHashmap_t *map);

int StaticHashmap_has(StaticHashmap_t *map, uint64_t key);
#ifdef __cplusplus
}
#endif
#endif //ECS_STATICHASHMAP_H
