#ifndef DIJKSTRA_NAIVE_H
#define DIJKSTRA_NAIVE_H

#include "edge.h"

#include <tuple>
#include <vector>

namespace dijkstra_naive
{
    std::pair<std::vector<int>, std::vector<std::vector<int>>> findShortestPaths(
        const std::vector<std::vector<Edge>>& graph,
        const std::vector<int>& sources, 
        const std::vector<int>& targets);

}   // dijkstra_naive

#endif // DIJKSTRA_NAIVE_H