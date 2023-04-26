// Copyright 2023 Thomas O'Connor

#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <string>

#include <chrono>
#include <thread>

#include "GraphAPI.hpp"

using std::fstream;

int main()
{
	std::string source = "source.dat";
	Graph A;
	A.set_title("Test").set_grid(1).set_numMinorTicks(1).set_Label('x', "base").set_Label('y', "exponent").createLivePlot(source);

	return 0;
}

