#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include "edge.h"

#include <vector>
#include <string>


std::vector<std::vector<Edge>> loadInput(const std::string& fileName, bool directed);

std::vector<int> loadOutput(const std::string& fileName);

#endif	// GRAPH_IO_H