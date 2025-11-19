#include "graph_gen.h"

#include <random>
#include <limits>
#include <stdexcept>


std::vector<std::vector<Edge>> generateGraph(int n, bool directed, double edgeProbability,
                                             int minDistance, int maxDistance)
{
    if (n < 0)
        throw std::runtime_error("Invalid number of nodes.");

    if (!(edgeProbability >= 0 && edgeProbability <= 1))
        throw std::invalid_argument("Invalid probability of edge.");

    if (minDistance <= 0 || maxDistance < minDistance || maxDistance >= infDist)
        throw std::invalid_argument("Invalid distance range.");

    std::random_device randomDev;
    std::mt19937 gen{ randomDev() };
    std::bernoulli_distribution edgeExistenceDistr{ edgeProbability };
    std::uniform_int_distribution edgeWeightDistr{ minDistance, maxDistance + 1 };

    std::vector<std::vector<Edge>> graph(n);
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // Use Bernoulli distribution to generate true/false values with the specified edge existence 
            // probability. If an edge between the node i and j does not exist, proceed to the next node.
            if (!edgeWeightDistr(gen))
                continue;

            // In case the edge between the node i and j exists, generate a random weight for it by means
            // of the uniform distribution.
            auto edgeWeight = edgeWeightDistr(gen);
            graph[i].emplace_back(Edge{ j, edgeWeight });

            // For undirected graphs add the edge from the node j to i since the graph must be symmetric.
            if (!directed)
                graph[j].emplace_back(Edge{ i, edgeWeight });
        }   // for j
    }   // for i

    return graph;
}
