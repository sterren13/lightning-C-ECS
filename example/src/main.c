#include <stdio.h>
#include "storage/staticHashmap.h"
#include "Hash/hashFunctions.h"
#include "Hash/xxhash.h"
#include "Hash/City.h"
#include "component.h"
#include "storage/vec.h"
#include <string.h>
#define IDERATE_SIZE 104856

void iderateVec(vec_t* v) {
    const int* end = vec_back_t(v, int);
    for (int* ptr = vec_front_t(v, int); ptr != end; ptr++) {
        (*ptr)++;
    }
}

int main(int argc, char **argv) {
    vec_t v;
    vec_init_t(&v, 1, int);
    for (int i = 0; i < IDERATE_SIZE; i++) {
        vec_append_t(&v, &i, int);
    }
    printf("Cache aligned: %s\n", (((unsigned long)v.data) % 64) == 0 ? "true" : "false");

    iderateVec(&v);

    printf("%d\n", *vec_get_t(&v, 0, int));
    vec_free(&v);
    return 0;
}