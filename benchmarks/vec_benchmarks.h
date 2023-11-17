#include <benchmark/benchmark.h>
#include "storage/vec.h"
#define IDERATE_SIZE 104856

static void BM_VecAppend(benchmark::State& state) {
    vec_t v;
    int value = 1;
    vec_init_t(&v, 1, int);
    vec_append_t(&v, &value, int);
    // start benchmark
    for (auto _ : state) {
        vec_append_t(&v, &value, int);
    }
    vec_free(&v);
}
BENCHMARK(BM_VecAppend);

static void BM_VecAppend_preallock_Range(benchmark::State& state){
    vec_t v;
    int value = 2;
    vec_init_t(&v, 10, int);
    // start benchmark
    for (auto _ : state) {
        vec_append_t(&v, &value, int);
    }
    vec_free(&v);
}
BENCHMARK(BM_VecAppend_preallock_Range);

static void BM_VecIderate(benchmark::State& state) {
    vec_t v;
    vec_init_t(&v, 1, int);
    for (int i = 0; i < IDERATE_SIZE; i++) {
        vec_append_t(&v, &i, int);
    }
    // start benchmark
    const int* end = vec_back_t(&v, int);
    for (auto _ : state) {
        for (int* ptr = vec_front_t(&v, int); ptr != end; ptr++) {
            (*ptr)++;
        }
    }
    vec_free(&v);
}
BENCHMARK(BM_VecIderate);

static void BM_IderateArray(benchmark::State& state) {
    int* array = (int*)malloc(IDERATE_SIZE * sizeof(int));
    for (int i = 0; i < IDERATE_SIZE; i++) {
        array[i] = i;
    }
    // start benchmark
    const int* end_ptr = array + IDERATE_SIZE;
    for (auto _ : state) {
        for (int *ptr = array; ptr != end_ptr; ptr++) {
            (*ptr)++;
        }
    }
    free(array);
}
BENCHMARK(BM_IderateArray);

static void BM_IderateStacArray(benchmark::State& state) {
    int array[IDERATE_SIZE];
    for (int i = 0; i < IDERATE_SIZE; i++) {
        array[i] = i;
    }
    // start benchmark
    const int* end_ptr = array + IDERATE_SIZE;
    for (auto _ : state) {
        for (int *ptr = array; ptr != end_ptr; ptr++) {
            (*ptr)++;
        }
    }
}
BENCHMARK(BM_IderateStacArray);