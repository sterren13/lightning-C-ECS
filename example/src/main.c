#include <stdio.h>
#include "vec.h"
#include <time.h>
#define IDERATE_SIZE 104856

typedef unsigned long StaticMapKey_t;
typedef struct {
    StaticMapKey_t key;
} StaticMapEntry;

// Hashfunctie (djb2)
unsigned long hashFunction(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main(int argc, char **argv) {
    unsigned long intId = hashFunction("int");
    unsigned long floatId = hashFunction("float");
    unsigned long charId = hashFunction("char");
    unsigned long doubleId = hashFunction("double");

    printf("Unique ID for int: %lu\n", intId);
    printf("Unique ID for float: %lu\n", floatId);
    printf("Unique ID for char: %lu\n", charId);
    printf("Unique ID for double: %lu\n", doubleId);
    return 0;
}