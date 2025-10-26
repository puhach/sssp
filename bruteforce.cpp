#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cassert>

//using namespace std;

struct Edge
{
    int to;
    int weight;
};

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

                //visited[mid] = true;
                dfs(graph, mid, end, curDist + edge.weight, minDist, curPath, bestPath, visited);
                //visited[mid] = false;

                //if (subpathCost >= 0 && (minCost < 0 || curCost < minCost))
                //{
                //    prev[mid] = start;
                //    minCost = subpathCost + edge.weight;
                //}   // better path found
            }   // for edge
        }   // start == end

        visited[start] = false;
        curPath.pop_back();
    }   // dfs

    int findShortestPath(const std::vector<std::vector<Edge>>& graph, int start, int end)
    {
        int n = static_cast<int>(graph.size());
        assert(start >= 0 && start < n);
        assert(end >= 0 && end < n);

        if (start == end)
            return 0;

        //std::queue<int> frontier;
        //std::vector<int> prev(n, -1);
        std::vector<int> curPath, bestPath;
        std::vector<bool> visited(n, false);
        int minDist = std::numeric_limits<int>::max();

        dfs(graph, start, end, 0, minDist, curPath, bestPath, visited);

        return minDist;
    }   // findPath

}   // bruteforce

int main()
{
    int n = 5;
    std::vector<std::vector<Edge>> graph(n);

    graph[0].push_back({ 1, 2 });
    graph[0].push_back({ 2, 5 });
    graph[1].push_back({ 3, 1 });
    graph[2].push_back({ 4, 3 });
    graph[3].push_back({ 4, 2 });

    auto cost = bruteforce::findShortestPath(graph, 0, 4);

    std::cout << cost << std::endl;
}
