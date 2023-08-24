// Copyright 2023 Thomas O'Connor

#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <string>

#include <chrono>
#include <thread>

#include "GraphAPI.hpp"

int main()
{
	Graph DisplayGraph;
	std::string source = SOURCE_DATA_PATH;
	std::ofstream file(source);
	file << "1 1\n2 4\n3 9\n4 16\n5 25\n6 36\n";

	DisplayGraph.createPlot(PlotObject(source));
	return 0;
}

