#include <stdio.h>
#include "vec.h"
#include <time.h>
#include <stdio.h>
#define IDERATE_SIZE 104856

int main(int argc, char **argv) {
    struct timespec start, end;
    long double elapsed = 0;

    vec_t v;
    vec_init_t(&v, 1, int);
    for (int i = 0; i < IDERATE_SIZE; i++) {
        vec_append_t(&v, &i, int);
    }
    // test vec_get_t
    for (int i = 0; i < vec_size(&v); i++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        (*vec_get_t(&v, i, int))++;
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
    }
    elapsed = elapsed/IDERATE_SIZE;
    printf("vec_get_t time: %.9Lf ns\n", elapsed);

    // test ptr
    elapsed = 0;
    int* end_ptr = vec_back_t(&v, int);
    for (int* ptr = vec_front_t(&v, int); ptr != end_ptr; ptr++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        (*ptr)++;
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
    }
    elapsed = elapsed/IDERATE_SIZE;
    printf("ptr time: %.9Lf ns\n", elapsed);
    return 0;
}