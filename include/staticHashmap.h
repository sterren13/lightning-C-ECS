//
// Created by arno on 9/11/23.
//

#ifndef ECS_STATICHASHMAP_H
#define ECS_STATICHASHMAP_H
#include <stdint.h>
#include "vec.h"

typedef struct {
    uint64_t key;
    void* value;
} StaticHashmap_entry_t;

typedef struct {
    uint32_t size;
    StaticHashmap_entry_t* entries;
} StaticHashmap_t;

StaticHashmap_t StaticHashmap_init(StaticHashmap_entry_t* entries, uint32_t size);

void* StaticHashmap_get(StaticHashmap_t* map, uint64_t key);

void StaticHashmap_free(StaticHashmap_t* map);

#endif //ECS_STATICHASHMAP_H
