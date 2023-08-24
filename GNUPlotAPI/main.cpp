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
	std::vector<PlotObject> items = { PlotObject(source, "GOOGL", 1, 2),
									  PlotObject(source, "MSFT", 1, 3),
									  PlotObject(source, "TSLA", 1, 4) };
	DisplayGraph.createLiveMultiplot(items);

	DisplayGraph.demo3Multiplot();
	return 0;
}

