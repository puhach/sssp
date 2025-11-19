#include "graph_gen.h"
#include "bruteforce.h"
#include "dijkstra_naive.h"
#include "dijkstra_with_binary_heap.h"

#include <benchmark/benchmark.h>

#include <numeric>


static void findShortestPath(
    std::function<std::pair<std::vector<int>, std::vector<std::vector<int>>>
                (const std::vector<std::vector<Edge>>&,
                 const std::vector<int>& sources,
                 const std::vector<int>& targets)> alg,
    bool directed,
    double edgeProbability,
    benchmark::State& state)
{
    auto numNodes = static_cast<int>(state.range(0));

    auto graph = generateGraph(numNodes, directed, edgeProbability, 1, 100);

    auto sources = std::vector<int>{ 0 };

    auto targets = std::vector<int>(numNodes);
    std::iota(targets.begin(), targets.end(), 0);

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(alg(graph, sources, targets));
    }

    state.SetComplexityN(numNodes);
}

static void bruteforceSearch(benchmark::State& state)
{
    findShortestPath(bruteforce::findShortestPaths, false, 0.33, state);
}

static void naiveDijkstra(benchmark::State& state)
{
    findShortestPath(dijkstra_naive::findShortestPaths, false, 0.33, state);
}

static void dijkstraWithBinaryHeap(benchmark::State& state)
{
    findShortestPath(dijkstra_with_binary_heap::findShortestPaths, false, 0.33, state);
}

BENCHMARK(bruteforceSearch)->DenseRange(1, 12, 2)->Complexity();

BENCHMARK(naiveDijkstra)->RangeMultiplier(2)->Range(1, 256)->Complexity();

BENCHMARK(dijkstraWithBinaryHeap)->RangeMultiplier(2)->Range(1, 256)->Complexity();

BENCHMARK_MAIN();