//
// Created by arno on 11/13/23.
//

#ifndef ECS_STATICHASMAP_BENCHMARKS_H
#define ECS_STATICHASMAP_BENCHMARKS_H

#include "benchmark/benchmark.h"
#include "storage/staticHashmap.h"

static void BM_StaticHashmapInit(benchmark::State& state) {
    StaticHashmap_entry_t entries[] = {
            {123, (void*)456},
            {789, (void*)012},
            {345, (void*)678},
            {901, (void*)234},
            {567, (void*)890},
            {1234, (void*)567},
            {8901, (void*)2345},
            {6789, (void*)0123},
            {4567, (void*)8901},
            {2345, (void*)6789},
            {1111, (void*)2222},
            {3333, (void*)4444},
            {5555, (void*)6666},
            {7777, (void*)8888},
            {9999, (void*)1111},
            {2222, (void*)3333},
            {4444, (void*)5555},
            {6666, (void*)7777},
            {8888, (void*)9999},
            {11111, (void*)22222}
    };
    for (auto _ : state) {
        StaticHashmap_t map;
        StaticHashmap_init(entries, sizeof(entries) / sizeof(StaticHashmap_entry_t), &map);
        StaticHashmap_free(&map);
    }
}
BENCHMARK(BM_StaticHashmapInit);

static void BM_StaticHashmapGet(benchmark::State& state) {
    StaticHashmap_t map;
    StaticHashmap_entry_t entries[] = {
            {123, (void*)456},
            {789, (void*)012},
            {345, (void*)678},
            {901, (void*)234},
            {567, (void*)890},
            {1234, (void*)567},
            {8901, (void*)2345},
            {6789, (void*)0123},
            {4567, (void*)8901},
            {2345, (void*)6789},
            {1111, (void*)2222},
            {3333, (void*)4444},
            {5555, (void*)6666},
            {7777, (void*)8888},
            {9999, (void*)1111},
            {2222, (void*)3333},
            {4444, (void*)5555},
            {6666, (void*)7777},
            {8888, (void*)9999},
            {11111, (void*)22222}
    };
    StaticHashmap_init(entries, sizeof(entries) / sizeof(StaticHashmap_entry_t), &map);

    for (auto _ : state) {
        StaticHashmap_get(&map, entries[0].key);
    }

    StaticHashmap_free(&map);
}
BENCHMARK(BM_StaticHashmapGet);

#endif //ECS_STATICHASMAP_BENCHMARKS_H
