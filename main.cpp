#include "bruteforce.h"
#include "dijkstra_naive.h"
#include "dijkstra_with_binary_heap.h"
#include "graph_io.h"

#include <algorithm>
#include <functional>
#include <vector>
#include <cassert>
#include <iostream>


bool runTests(const std::vector<std::string>& inputFiles, const std::vector<std::string>& outputFiles,
              bool directed, int source, const std::vector<int>& targets,
              std::function<std::pair<std::vector<int>, std::vector<std::vector<int>>>
                            (const std::vector<std::vector<Edge>>& graph, 
                             const std::vector<int>& sources, 
                             const std::vector<int>& targets)> findShortestPaths)
{
    assert(inputFiles.size() == outputFiles.size());

    bool allPassed = true;

    for (std::size_t test = 0; test < inputFiles.size(); ++test)
    {
        std::cout << "test #" << test + 1 << ": " << "[ " << inputFiles[test] 
            << ", " << outputFiles[test] << " ]" << std::endl;

        auto graph = loadInput("tests/" + inputFiles[test], directed);

        auto minDistsGroundTruth = loadOutput("tests/" + outputFiles[test]);

        assert(minDistsGroundTruth.size() == targets.size());

        std::vector<int> zbTargets(targets.size());
        std::transform(targets.cbegin(), targets.cend(), zbTargets.begin(),
                       [](auto target) { return target - 1; });

        auto [minDistsComputed, zbShortestPaths] = findShortestPaths(graph, { source - 1 }, zbTargets);

        for (int i = 0; i < targets.size(); ++i)
        {
            auto target = targets[i];
            auto zbTarget = zbTargets[i];
            auto minDistComputed = minDistsComputed[zbTarget];
            auto minDistGroundTruth = minDistsGroundTruth[i];

            //int minDist;
            //std::tie(minDist, std::ignore) = bruteforce::findShortestPath(graph, source - 1, target - 1);

            std::cout << "target " << target << ": ";

            if (minDistComputed == minDistGroundTruth)
                std::cout << "passed";
            else
            {
                allPassed = false;
                std::cout << "failed";
            }

            std::cout << std::endl;
        }   // for target
    }   // for test

    if (allPassed)
        std::cout << std::endl << "All tests passed." << std::endl;
    else
        std::cout << std::endl << "Some tests failed." << std::endl;

    return allPassed;
}   // runTests


int main()
{
    std::cout << "Brute-force search" << std::endl;

    runTests(
        { "bruteforce_input_1_5.txt" },
        { "bruteforce_output_1_5.txt" },
        true,   // directed
        1,
        { 1, 2, 3, 4, 5 },
        bruteforce::findShortestPaths
    );
    

    std::cout << std::endl << "Naive Dijkstra search" << std::endl;

    runTests(
        { 
            "input_random_1_4.txt",
            "input_random_2_4.txt",
            "input_random_3_4.txt",
            "input_random_4_4.txt",
            "input_random_5_8.txt",
            "input_random_6_8.txt",
            "input_random_7_8.txt",
            "input_random_8_8.txt",
            "input_random_9_16.txt",
            "input_random_10_16.txt",
            "input_random_11_16.txt",
            "input_random_12_16.txt",
            "input_random_13_32.txt",
            "input_random_14_32.txt",
            "input_random_15_32.txt",
            "input_random_16_32.txt",
            "input_random_17_64.txt",
            "input_random_18_64.txt",
            "input_random_19_64.txt",
            "input_random_20_64.txt",
            "input_random_21_128.txt",
            "input_random_22_128.txt",
            "input_random_23_128.txt",
            "input_random_24_128.txt",
            "input_random_25_256.txt",
            "input_random_26_256.txt",
            "input_random_27_256.txt",
            "input_random_28_256.txt"
        },
        { 
            "output_random_1_4.txt",
            "output_random_2_4.txt",
            "output_random_3_4.txt",
            "output_random_4_4.txt",
            "output_random_5_8.txt",
            "output_random_6_8.txt",
            "output_random_7_8.txt",
            "output_random_8_8.txt",
            "output_random_9_16.txt",
            "output_random_10_16.txt",
            "output_random_11_16.txt",
            "output_random_12_16.txt",
            "output_random_13_32.txt",
            "output_random_14_32.txt",
            "output_random_15_32.txt",
            "output_random_16_32.txt",
            "output_random_17_64.txt",
            "output_random_18_64.txt",
            "output_random_19_64.txt",
            "output_random_20_64.txt",
            "output_random_21_128.txt",
            "output_random_22_128.txt",
            "output_random_23_128.txt",
            "output_random_24_128.txt",
            "output_random_25_256.txt",
            "output_random_26_256.txt",
            "output_random_27_256.txt",
            "output_random_28_256.txt"
        },
        false,  // undirected
        1,
        { 7, 37, 59, 82, 99, 115, 133, 165, 188, 197 },
        dijkstra_naive::findShortestPaths
    );


    std::cout << std::endl << "Dijkstra search with binary heap" << std::endl;

    runTests(
        {
            "input_random_1_4.txt",
            "input_random_2_4.txt",
            "input_random_3_4.txt",
            "input_random_4_4.txt",
            "input_random_5_8.txt",
            "input_random_6_8.txt",
            "input_random_7_8.txt",
            "input_random_8_8.txt",
            "input_random_9_16.txt",
            "input_random_10_16.txt",
            "input_random_11_16.txt",
            "input_random_12_16.txt",
            "input_random_13_32.txt",
            "input_random_14_32.txt",
            "input_random_15_32.txt",
            "input_random_16_32.txt",
            "input_random_17_64.txt",
            "input_random_18_64.txt",
            "input_random_19_64.txt",
            "input_random_20_64.txt",
            "input_random_21_128.txt",
            "input_random_22_128.txt",
            "input_random_23_128.txt",
            "input_random_24_128.txt",
            "input_random_25_256.txt",
            "input_random_26_256.txt",
            "input_random_27_256.txt",
            "input_random_28_256.txt"
        },
        {
            "output_random_1_4.txt",
            "output_random_2_4.txt",
            "output_random_3_4.txt",
            "output_random_4_4.txt",
            "output_random_5_8.txt",
            "output_random_6_8.txt",
            "output_random_7_8.txt",
            "output_random_8_8.txt",
            "output_random_9_16.txt",
            "output_random_10_16.txt",
            "output_random_11_16.txt",
            "output_random_12_16.txt",
            "output_random_13_32.txt",
            "output_random_14_32.txt",
            "output_random_15_32.txt",
            "output_random_16_32.txt",
            "output_random_17_64.txt",
            "output_random_18_64.txt",
            "output_random_19_64.txt",
            "output_random_20_64.txt",
            "output_random_21_128.txt",
            "output_random_22_128.txt",
            "output_random_23_128.txt",
            "output_random_24_128.txt",
            "output_random_25_256.txt",
            "output_random_26_256.txt",
            "output_random_27_256.txt",
            "output_random_28_256.txt"
        },
        false,  // undirected
        1,
        { 7, 37, 59, 82, 99, 115, 133, 165, 188, 197 },
        dijkstra_with_binary_heap::findShortestPaths
    );

    return 0;
}
