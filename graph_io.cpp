#include "graph_io.h"

#include <fstream>
#include <sstream>
#include <exception>
#include <cassert>


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
        if (comma != ',')
            throw std::runtime_error("Bad file format");
    }

    return dists;
}   // loadOutput
