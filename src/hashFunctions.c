#include "hashFunctions.h"

uint64_t jenkins_one_at_a_time_hash(const char *key) {
    uint64_t hash = 0;
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

uint64_t djb2(const char *str) {
    uint64_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

uint64_t fnv1a(const char *s) {
    uint64_t hash = 2166136261u;
    while (*s) {
        hash ^= *s++;
        hash *= 16777619;
    }
    return hash;
}

// https://github.com/aappleby
uint64_t MurmurHash64 ( const void * key, int len, uint64_t seed ) {
    const uint64_t m = BIG_CONSTANT(0xc6a4a7935bd1e995);
    const int r = 47;

    uint64_t h = seed ^ (len * m);

    const uint64_t * data = (const uint64_t *)key;
    const uint64_t * end = data + (len/8);

    while(data != end)
    {
        uint64_t k = *data++;

        k *= m;
        k ^= k >> r;
        k *= m;

        h ^= k;
        h *= m;
    }

    const unsigned char * data2 = (const unsigned char*)data;

    switch(len & 7)
    {
        case 7: h ^= (data2[6]) << 48;
        case 6: h ^= (data2[5]) << 40;
        case 5: h ^= (data2[4]) << 32;
        case 4: h ^= (data2[3]) << 24;
        case 3: h ^= (data2[2]) << 16;
        case 2: h ^= (data2[1]) << 8;
        case 1: h ^= (data2[0]);
            h *= m;
    };

    h ^= h >> r;
    h *= m;
    h ^= h >> r;

    return h;
}