//
// Created by arno on 9/11/23.
//
#include <benchmark/benchmark.h>
#include "Hash/hashFunctions.h"
#include "Hash/xxhash.h"
#include "Hash/City.h"
#include <cstring>

#define HASH_STRING "Hello, World!, Hello, World!, Hello, World!, Hello, World! dskjflhgsqkdljhg_qzeoiu bsdfulysqhfiuzepsuhzesiup fiez hfboli usghefblkuesz"

static void BM_jenkins_one_at_a_time_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    for (auto _ : state) {
        hashwaarde = jenkins_one_at_a_time_hash(s);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_jenkins_one_at_a_time_hash);

static void BM_djb2_hash(benchmark::State& state) {
    const char* s = HASH_STRING;
    unsigned long hashwaarde;
    for (auto _ : state) {
        hashwaarde = djb2(s);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_djb2_hash);

static void BM_fnv1a_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    for (auto _ : state) {
        hashwaarde = fnv1a(s);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_fnv1a_hash);

static void BM_murmur3_32_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    size_t len = strlen(s);
    for (auto _ : state) {
        hashwaarde = MurmurHash64(s, len, 0);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_murmur3_32_hash);

static void BM_xxhash_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    size_t len = strlen(s);
    for (auto _ : state) {
        hashwaarde = XXH64(s, len, 0);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_xxhash_hash);

static void BM_City_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    size_t len = strlen(s);
    for (auto _ : state) {
        hashwaarde = CityHash64(s, len);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_City_hash);