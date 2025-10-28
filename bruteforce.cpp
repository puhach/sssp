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

//using namespace std;

constexpr int infDist = 1000000;

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

    std::pair<int, std::vector<int>> findShortestPath(const std::vector<std::vector<Edge>>& graph, int start, int end)
    {
        int n = static_cast<int>(graph.size());
        assert(start >= 0 && start < n);
        assert(end >= 0 && end < n);

        //if (start == end)
        //    return {  };

        //std::queue<int> frontier;
        //std::vector<int> prev(n, -1);
        std::vector<int> curPath, bestPath;
        std::vector<bool> visited(n, false);
        int minDist = infDist;
        //int minDist = std::numeric_limits<int>::max();

        dfs(graph, start, end, 0, minDist, curPath, bestPath, visited);

        return { minDist, bestPath };
    }   // findPath

}   // bruteforce

std::vector<std::vector<Edge>> loadInput(const std::string& fileName, bool directed)
{

    std::ifstream in{ fileName };
    if (!in)
        throw std::runtime_error("Failed to open " + fileName);
    //in.exceptions(std::ifstream::failbit);

    constexpr int maxNumVertices = 200;

    std::vector<std::vector<Edge>> graph(maxNumVertices);

    int numVertices = 0;

    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss{ line };

        int v;
        ss >> v;

        numVertices = std::max(numVertices, v);

        --v;    // we need zero-based indices

        std::string token;
        while (ss >> token)
        {
            auto commaPos = token.find(',');
            assert(commaPos != std::string::npos);

            auto u = std::stoi(token.substr(0, commaPos)) - 1;
            auto weight = std::stoi(token.substr(commaPos + 1));

            graph[v].push_back(Edge{ u, weight });

            if (!directed)
                graph[u].push_back(Edge{ v, weight });
        }

    }   // !eof

    graph.resize(numVertices);

    return graph;
}   // loadInput

std::vector<int> loadOutput(const std::string& fileName)
{
    std::ifstream f{ fileName, std::ios::in };
    //f.exceptions(std::ofstream::failbit);
    if (!f)
        throw std::runtime_error("Failed to open " + fileName);

    std::vector<int> dists;
    dists.reserve(10);

    int dist;
    while (f >> dist)
    {
        dists.push_back(dist);

        char comma;
        f >> comma;
    }

    return dists;
}   // loadOutput

int main()
{
    int source = 1;
    std::vector<int> targets{ 7, 37, 59, 82, 99, 115, 133, 165, 188, 197 };

    std::string inputFiles[] =
    {
        "input_random_1_4.txt"
    };

    std::string outputFiles[] =
    {
        "output_random_1_4.txt"
    };


    std::cout << "Brute-force search" << std::endl;

    int numTestsBruteforce = 1;

    for (int test = 0; test < numTestsBruteforce; ++test)
    {
        std::cout << "test #" << test << std::endl;

        auto graph = loadInput("tests/" + inputFiles[test], false);

        auto minDistsGT = loadOutput("tests/" + outputFiles[test]);

        assert(minDistsGT.size() == targets.size());

        for (int i = 0; i < targets.size(); ++i)
        {
            int target = targets[i];
            int minDistGT = minDistsGT[i];

            int minDist;
            std::tie(minDist, std::ignore) = bruteforce::findShortestPath(graph, source - 1, target - 1);

            std::cout << "target " << target << ": ";

            if (minDist == minDistGT)
                std::cout << "passed";
            else
                std::cout << "failed";

            std::cout << std::endl;
        }   // for target
    }   // for test

    //std::cout << cost << std::endl;
}
