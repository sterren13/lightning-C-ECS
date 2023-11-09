#include <stdio.h>
#include "vec.h"
#include <time.h>
#include <stdio.h>
#define IDERATE_SIZE 104856

int main(int argc, char **argv) {
    struct timespec start, end;
    long double elapsed = 0;
    // clock_gettime(CLOCK_MONOTONIC, &start);
    // ....
    //  clock_gettime(CLOCK_MONOTONIC, &end);
    // elapsed = end.tv_nsec - start.tv_nsec;

    vec_t v;
    vec_init_t(&v, 1, int);
    for (int i = 0; i < IDERATE_SIZE; i++) {
        vec_append_t(&v, &i, int);
    }
    // start benchmark
    clock_gettime(CLOCK_MONOTONIC, &start);
    register int* endptr = vec_back_t(&v, int);
    for (register int* ptr = vec_front_t(&v, int); ptr != endptr; ptr++) {
        (*ptr)++;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_nsec - start.tv_nsec;
    vec_free(&v);
    printf("vec time:\t %.9Lf ns\n", elapsed);

    int* array = (int*)malloc(IDERATE_SIZE * sizeof(int));
    for (int i = 0; i < IDERATE_SIZE; i++) {
        array[i] = i;
    }
    // start benchmark
    clock_gettime(CLOCK_MONOTONIC, &start);
    register int* end_ptr = array + IDERATE_SIZE;
    for (register int *ptr = array; ptr != end_ptr; ptr++) {
        (*ptr)++;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_nsec - start.tv_nsec;
    free(array);
    printf("array time:\t %.9Lf ns\n", elapsed);
    return 0;
}