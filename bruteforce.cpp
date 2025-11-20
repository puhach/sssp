#include "bruteforce.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <queue>
#include <tuple>
#include <string>
#include <limits>
#include <cassert>


namespace bruteforce
{

    void dfs(const std::vector<std::vector<Edge>>& graph, int start, int end, int curDist, int& minDist,
             std::vector<int>& curPath, std::vector<int>& bestPath, std::vector<bool>& visited)
    {
        visited[start] = true;
        curPath.push_back(start);

        if (start == end)
        {
            if (curDist < minDist)
            {
                minDist = curDist;
                bestPath = curPath;
            }
        }
        else
        {
            for (const auto& edge : graph[start])
            {
                int mid = edge.to;

                if (visited[mid])
                    continue;

                dfs(graph, mid, end, curDist + edge.weight, minDist, curPath, bestPath, visited);
            }   // for edge
        }   // start == end

        visited[start] = false;
        curPath.pop_back();
    }   // dfs

    std::pair<int, std::vector<int>> findShortestPath(const std::vector<std::vector<Edge>>& graph, 
                                                      int start, 
                                                      int end)
    {
        int n = static_cast<int>(graph.size());
        assert(start >= 0 && start < n);
        assert(end >= 0 && end < n);

        std::vector<int> curPath, bestPath;
        std::vector<bool> visited(n, false);
        int minDist = infDist;

        dfs(graph, start, end, 0, minDist, curPath, bestPath, visited);

        return { minDist, bestPath };
    }   // findShortestPath


    std::pair<std::vector<int>, std::vector<std::vector<int>>> findShortestPaths(
        const std::vector<std::vector<Edge>>& graph,
        //const std::vector<int>& sources,
        int source,
        const std::vector<int>& targets)
    {
        int n = static_cast<int>(graph.size());

        std::vector<int> minDists;
        std::vector<std::vector<int>> shortestPaths;
        
        minDists.reserve(targets.size());
        shortestPaths.reserve(targets.size());
        //minDists.reserve(sources.size() * targets.size());
        //shortestPaths.reserve(sources.size() * targets.size());
        
        //for (int source : sources)
        //{
            assert(source >= 0 && source < n);

            for (int target : targets)
            {
                assert(target >= 0 && target < n);

                std::vector<int> curPath, bestPath;
                std::vector<bool> visited(n, false);
                int minDist = infDist;

                dfs(graph, source, target, 0, minDist, curPath, bestPath, visited);

                minDists.push_back(minDist);
                shortestPaths.push_back(std::move(bestPath));
            }   // for target
        //} // for source

        return std::make_pair(std::move(minDists), std::move(shortestPaths));
    }   // findShortestPaths

}   // bruteforce


