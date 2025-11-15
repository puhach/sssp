#include "dijkstra_naive.h"

#include <iostream>
#include <vector>
#include <limits>


namespace dijkstra_naive
{

    std::pair<std::vector<int>, std::vector<std::vector<int>>> findShortestPaths(
        const std::vector<std::vector<Edge>>& graph, 
        const std::vector<int>& sources,
        const std::vector<int>& targets)
    {
        //constexpr int INF = std::numeric_limits<int>::max();
        int n = static_cast<int>(graph.size());

        std::vector<int> minDists;
        std::vector<std::vector<int>> shortestPaths;

        minDists.reserve(sources.size() * targets.size());
        shortestPaths.reserve(sources.size() * targets.size());

        for (auto source : sources)
        {
            std::vector<int> dist(n, infDist);
            std::vector<bool> visited(n, false);
            std::vector<int> prev(n, -1);

            dist[source] = 0;

            for (int i = 0; i < n; ++i)
            {
                // Step 1: find the unvisited node with the smallest distance
                int u = -1;
                for (int v = 0; v < n; ++v)
                {
                    if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                        u = v;
                }

                if (u == -1 || dist[u] == infDist)
                    break; // remaining vertices are unreachable

                visited[u] = true;

                // Step 2: relax all edges from u
                for (const auto& edge : graph[u])
                {
                    int v = edge.to;
                    int newDist = dist[u] + edge.weight;
                    if (newDist < dist[v])
                    {
                        dist[v] = newDist;
                        prev[v] = u;
                    }
                }
            }   // for

            std::vector<std::vector<int>> paths(n);
            for (int i = 0; i < n; ++i)
            {
                if (dist[i] < infDist)
                {
                    //paths[i].reserve(n);

                    for (int cur = i; cur != -1; cur = prev[cur])
                    {
                        paths[i].push_back(cur);
                    }

                    std::reverse(paths[i].begin(), paths[i].end());
                }   // dist[i] < infDist
            }   // for i

            std::copy(dist.cbegin(), dist.cend(), std::back_inserter(minDists));
            std::move(paths.begin(), paths.end(), std::back_inserter(shortestPaths));
        } // for source

        //std::cout << "Shortest distances from node " << start << ":\n";
        //for (int i = 0; i < n; ++i)
        //    std::cout << "  to " << i << " = " << dist[i] << "\n";

        //return std::make_pair(std::move(dist), std::move(paths));
        return std::make_pair(std::move(minDists), std::move(shortestPaths));
    }   // findShortestPaths

}   // dijkstra_naive



