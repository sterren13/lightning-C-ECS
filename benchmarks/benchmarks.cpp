#include <benchmark/benchmark.h>
#include "vec_benchmarks.h"
#include "hash_benchmarks.h"
R#include "StaticHasmap_benchmarks.h"

int main(int argc, char** argv) {
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}
