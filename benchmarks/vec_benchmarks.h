#include <benchmark/benchmark.h>
#include <chrono>
#include "vec.h"
#define IDERATE_SIZE 104856

static void BM_VecAppend(benchmark::State& state) {
    vec_t v;
    int value = 1;
    vec_init_t(&v, 1, int);
    // start benchmark
    for (auto _ : state) {
        vec_append_t(&v, &value, int);
    }
    vec_free(&v);
}
BENCHMARK(BM_VecAppend);

/*static void BM_Vec_vec_get_t(benchmark::State& state) {
vec_t v;
    int value = 1;
    vec_init_t(&v, 1, int);
    vec_append_t(&v, &value, int);
    // start benchmark
    for (auto _ : state) {
        (*vec_get_t(&v, 0, int))++;
    }
    vec_free(&v);
}
BENCHMARK(BM_Vec_vec_get_t);

static void BM_Vec_ptrGet(benchmark::State& state) {
vec_t v;
    int value = 1;
    vec_init_t(&v, 1, int);
    vec_append_t(&v, &value, int);
    int* ptr = vec_front_t(&v, int);
    // start benchmark
    for (auto _ : state) {
        (*ptr)++;
    }
    vec_free(&v);
}
BENCHMARK(BM_Vec_ptrGet);*/

static void BM_VecIderate_vec_get_t(benchmark::State& state) {
    vec_t v;
    vec_init_t(&v, 1, int);
    for (int i = 0; i < IDERATE_SIZE; i++) {
        vec_append_t(&v, &i, int);
    }
    // start benchmark
    for (auto _ : state) {
        for (int i = 0; i < vec_size(&v); i++) {
            (*vec_get_t(&v, i, int))++;
        }
    }
    vec_free(&v);
}
BENCHMARK(BM_VecIderate_vec_get_t);

static void BM_VecIderate_ptr(benchmark::State& state) {
    vec_t v;
    vec_init_t(&v, 1, int);
    for (int i = 0; i < IDERATE_SIZE; i++) {
        vec_append_t(&v, &i, int);
    }
    int* ptr = vec_front_t(&v, int);
    int* end = vec_back_t(&v, int);
    // start benchmark
    for (auto _ : state) {
        for (; ptr != end; ptr++) {
            (*ptr)++;
        }
    }
    vec_free(&v);
}
BENCHMARK(BM_VecIderate_ptr);