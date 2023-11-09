//
// Created by arno on 9/11/23.
//
#include <benchmark/benchmark.h>
#include <string.h>

#define HASH_STRING "Hello, World!, Hello, World!, Hello, World!, Hello, World! dskjflhgsqkdljhg_qzeoiu bsdfulysqhfiuzepsuhzesiup fiez hfboli usghefblkuesz"

inline unsigned long jenkins_one_at_a_time_hash(const char *key) {
    unsigned long hash = 0;
    while (*key) {
        hash += *key++;
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

static void BM_jenkins_one_at_a_time_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    for (auto _ : state) {
        hashwaarde = jenkins_one_at_a_time_hash(s);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_jenkins_one_at_a_time_hash);

inline unsigned long djb2(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

static void BM_djb2_hash(benchmark::State& state) {
    const char* s = HASH_STRING;
    unsigned long hashwaarde;
    for (auto _ : state) {
        hashwaarde = djb2(s);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_djb2_hash);

inline unsigned long fnv1a(const char *s) {
    unsigned long hash = 2166136261u;
    while (*s) {
        hash ^= *s++;
        hash *= 16777619;
    }
    return hash;
}

static void BM_fnv1a_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    for (auto _ : state) {
        hashwaarde = fnv1a(s);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_fnv1a_hash);

inline uint32_t murmur3_32(const char* key, size_t len) {
    uint32_t h = 0x9747b28c; // constante seed waarde
    if (len > 3) {
        const uint32_t* key_x4 = (const uint32_t*) key;
        size_t i = len >> 2;
        do {
            uint32_t k = *key_x4++;
            k *= 0xcc9e2d51;
            k = (k << 15) | (k >> 17);
            k *= 0x1b873593;
            h ^= k;
            h = (h << 13) | (h >> 19);
            h = h*5 + 0xe6546b64;
        } while (--i);
        key = (const char*) key_x4;
    }
    if (len & 3) {
        size_t i = len & 3;
        uint32_t k = 0;
        key = &key[i - 1];
        do {
            k <<= 8;
            k |= *key--;
        } while (--i);
        k *= 0xcc9e2d51;
        k = (k << 15) | (k >> 17);
        k *= 0x1b873593;
        h ^= k;
    }
    h ^= len;
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

static void BM_murmur3_32_hash(benchmark::State& state) {
    const char *s = HASH_STRING;
    unsigned long hashwaarde;
    size_t len = strlen(s);
    for (auto _ : state) {
        hashwaarde = murmur3_32(s, len);
    }
    state.SetLabel("key: " + std::to_string(hashwaarde));
}
BENCHMARK(BM_murmur3_32_hash);