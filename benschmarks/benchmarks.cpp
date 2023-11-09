#include <benchmark/benchmark.h>
#include "vec_benschmarks.h"

int main(int argc, char** argv) {
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}
