#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "edge.h"

#include <tuple>
#include <vector>

namespace bruteforce
{
    std::pair<int, std::vector<int>> findShortestPath(
        const std::vector<std::vector<Edge>>& graph, 
        int start, 
        int end);

    std::pair<std::vector<int>, std::vector<std::vector<int>>> findShortestPaths(
        const std::vector<std::vector<Edge>>& graph,
        const std::vector<int>& sources,
        const std::vector<int>& targets);

}   // bruteforce


#endif	// BRUTEFORCE_H