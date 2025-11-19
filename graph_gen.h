#ifndef GRAPH_GEN_H
#define GRAPH_GEN_H

#include "edge.h"

#include <vector>
//#include <>

std::vector<std::vector<Edge>> generateGraph(int n, bool directed, double edgeProbability, 
                                             int minDistance, int maxDistance);

#endif	// GRAPH_GEN_H