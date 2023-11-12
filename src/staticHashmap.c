#include "staticHashmap.h"
#include <stdio.h>

#define EXPAND_FACTOR 4

uint64_t get_index(StaticHashmap_t* map, uint64_t key) {
    return key % (map->size);
}

StaticHashmap_t StaticHashmap_init(StaticHashmap_entry_t* entries, uint32_t size) {
    StaticHashmap_t map;
    map.size = (uint32_t)(size * EXPAND_FACTOR);
    printf("map.size: %u\n", map.size);
    map.entries = malloc(sizeof(StaticHashmap_entry_t) * size);
    // set all entries to NULL
    for (StaticHashmap_entry_t* ptr = map.entries; ptr < (map.entries + size); ptr++) {
        ptr->key = 0;
        ptr->value = NULL;
    }
    // insert all entries
    StaticHashmap_entry_t* ptr_input;
    for (ptr_input = entries; ptr_input < (entries + size); ptr_input++) {
        uint64_t index = get_index(&map, ptr_input->key);
        printf("index: %lu, key = %lu\n", index, ptr_input->key);
        if (map.entries[index].value != NULL) {
            printf("collision detected\n"); // TODO handle collision
        } else
            map.entries[index] = *ptr_input;
    }
    return map;
}

void* StaticHashmap_get(StaticHashmap_t* map, uint64_t key) {
    uint64_t index = get_index(map, key);
    return map->entries[index].value;
}

void StaticHashmap_free(StaticHashmap_t* map) {
    free(map->entries);
}