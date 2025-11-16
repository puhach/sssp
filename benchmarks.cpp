#include <benchmark/benchmark.h>

static void BM_PathFinding(benchmark::State& state) {
    for (auto _ : state) {
        // call your pathfinding function here
    }
}
BENCHMARK(BM_PathFinding);

BENCHMARK_MAIN();