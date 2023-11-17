#include "storage/staticHashmap.h"
#include <stdio.h>
#include <assert.h>

#define EXPAND_FACTOR 2

uint64_t get_index(StaticHashmap_t* map, uint64_t key) {
    return key % (map->capacity);
}

int find_in_bukket(vec_t* bukket, uint64_t key) {
    if (vec_size(bukket) == 0)
        return -1;
    for (int i = 0; i < vec_size(bukket); i++)
        if (key == vec_get_t(bukket, i, StaticHashmap_entry_t)->key)
            return i;
    return -1; // key not fond
}

int StaticHashmap_has(StaticHashmap_t* map, uint64_t key) {
    uint64_t index = get_index(map, key);
    if (find_in_bukket(&map->bukkets[index], key) != -1)
        return 1; // key fond
    return 0; // key not fond in hash map
}

void StaticHashmap_init(StaticHashmap_entry_t* entries, uint32_t size, StaticHashmap_t* map) {
    if (size == 0 || entries == nullptr) {
        map->capacity = 0;
        map->size = 0;
        map->bukkets = nullptr;
        return;
    }
    map->capacity = (uint32_t)(size * EXPAND_FACTOR);
    map->size = size;
    map->bukkets = malloc(sizeof(vec_t) * map->capacity);
    // init all bukkets
    for (vec_t* ptr = map->bukkets; ptr < (map->bukkets + map->capacity); ptr++)
        vec_init_t(ptr, 2, StaticHashmap_entry_t);
    // insert all entries
    StaticHashmap_entry_t* ptr_input;
    for (ptr_input = entries; ptr_input < (entries + size); ptr_input++) {
        uint64_t index = get_index(map, ptr_input->key);
        vec_t* bukket = &(map->bukkets[index]);
        StaticHashmap_entry_t entry = {ptr_input->key, ptr_input->value};
        int bukket_index = find_in_bukket(bukket, ptr_input->key);
        assert(bukket_index == -1); // map already has this key
        vec_append_t(bukket, &entry, StaticHashmap_entry_t);
    }
}

void* StaticHashmap_get(StaticHashmap_t* map, uint64_t key) {
    uint64_t index = get_index(map, key);
    vec_t* bukket = &map->bukkets[index];
    int bukket_index = find_in_bukket(bukket, key);
    if (bukket_index == -1)
        return nullptr;
    return vec_get_t(bukket, bukket_index, StaticHashmap_entry_t)->value;
}

void StaticHashmap_free(StaticHashmap_t* map) {
    for (vec_t * ptr = map->bukkets; ptr < (map->bukkets + map->capacity); ptr++) {
        vec_front(ptr);
    }
    free(map->bukkets);
    map->bukkets = nullptr;
    map->capacity = 0;
    map->size = 0;
}