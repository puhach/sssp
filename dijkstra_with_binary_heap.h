#ifndef DIJKSTRA_WITH_BINARY_HEAP_H
#define DIJKSTRA_WITH_BINARY_HEAP_H

#include "edge.h"

#include <tuple>
#include <vector>

namespace dijkstra_with_binary_heap
{
    std::pair<std::vector<int>, std::vector<std::vector<int>>> findShortestPaths(
        const std::vector<std::vector<Edge>>& graph,
        //const std::vector<int>& sources, 
        int source,
        const std::vector<int>& targets);

}   // dijkstra_with_binary_heap

#endif // DIJKSTRA_WITH_BINARY_HEAP_H