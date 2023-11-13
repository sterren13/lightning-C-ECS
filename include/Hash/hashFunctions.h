//
// Created by arno on 12/11/23.
//

#ifndef ECS_HASHFUNCTIONS_H
#define ECS_HASHFUNCTIONS_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#if defined(_MSC_VER)

#define BIG_CONSTANT(x) (x)

// Other compilers

#else	// defined(_MSC_VER)

#define BIG_CONSTANT(x) (x##LLU)

#endif // !defined(_MSC_VER)

unsigned long jenkins_one_at_a_time_hash(const char *key);

unsigned long djb2(const char *str);

unsigned long fnv1a(const char *s);

uint64_t MurmurHash64( const void * key, int len, uint64_t seed );

#ifdef __cplusplus
}
#endif
#endif //ECS_HASHFUNCTIONS_H
