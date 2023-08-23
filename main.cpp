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
	Graph a;
	std::string source = "C:\\SourceFiles\\source.dat";
	std::ofstream file(source);
	std::vector<PlotObject> items = { PlotObject(source, "GOOGL", 1, 2),
									  PlotObject(source, "MSFT", 1, 3),
									  PlotObject(source, "TSLA", 1, 4) };
	a.createLiveMultiplot(items);

	a.demo3Multiplot();
	return 0;
}

