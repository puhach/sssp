#include "dijkstra_with_binary_heap.h"

#include <iostream>
#include <vector>
#include <limits>
#include <queue>


namespace dijkstra_with_binary_heap
{

    std::pair<std::vector<int>, std::vector<std::vector<int>>> findShortestPaths(
        const std::vector<std::vector<Edge>>& graph, 
        //const std::vector<int>& sources,
        int source,
        const std::vector<int>& targets)
    {
        int n = static_cast<int>(graph.size());

        //std::vector<int> minDists;
        //std::vector<std::vector<int>> shortestPaths;

        //minDists.reserve(sources.size() * targets.size());
        //shortestPaths.reserve(sources.size() * targets.size());

        //for (auto source : sources)
        //{
            std::vector<int> dist(n, infDist);
            std::vector<int> prev(n, -1);

            dist[source] = 0;

            using DistToNode = std::pair<int, int>;
            std::priority_queue<DistToNode, std::vector<DistToNode>, std::greater<DistToNode>> pq;
            pq.push({0, source});

            while (!pq.empty())
            {
                // Extract the node with the shortest distance
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u])
                    continue;

                // Relax all edges from u
                for (const auto& edge : graph[u])
                {   
                    auto v = edge.to;
                    //auto newDist = d + edge.weight;
                    auto newDist = dist[u] + edge.weight;

                    if (newDist < dist[v])
                    {
                        dist[v] = newDist;
                        prev[v] = u;
                        pq.push({newDist, v});
                    }
                }   // for edge
            }   // while

            std::vector<std::vector<int>> paths(n);

            for (int i = 0; i < n; ++i)
            {
                if (dist[i] < infDist)
                {
                    //paths[i].reserve(n);

                    for (int cur = i; cur != -1; cur = prev[cur])
                        paths[i].push_back(cur);

                    std::reverse(paths[i].begin(), paths[i].end());
                }   // dist[i] < infDist
            }   // for i

            //std::copy(dist.cbegin(), dist.cend(), std::back_inserter(minDists));
            //std::move(paths.begin(), paths.end(), std::back_inserter(shortestPaths));
        //} // for source

        return std::make_pair(std::move(dist), std::move(paths));
        //return std::make_pair(std::move(minDists), std::move(shortestPaths));
    }   // findShortestPaths

}   // dijkstra_with_binary_heap



