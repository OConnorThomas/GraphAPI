// Copyright 2023 Thomas O'Connor
#ifndef GRAPH_API
#define GRAPH_API

#include "gnuplot-iostream.h"
#include "SmallClasses.hpp"

#define GNUPLOT_FILE_PATH "\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\""
#define SOURCE_DATA_PATH "C:\\SourceFiles\\source.dat"

using std::string;
using std::vector;

class Graph {
public:
	// Constructors
	inline Graph() : _gp(GNUPLOT_FILE_PATH) {}
	inline Graph(PlotObject data) : _gp(GNUPLOT_FILE_PATH) { createLivePlot(data); }
	inline Graph(const vector<PlotObject>& dataSet) : _gp(GNUPLOT_FILE_PATH) { createLivePlot(dataSet); }

	// Setters:
	Graph& set_Label(char axis, std::string_view label);
	Graph& set_Range(char axis, int lowBound, int upBound);

	Graph& set_TickMarks(char axis, int frequency);
	Graph& setNew_TickMark(char axis, TickObject obj);
	Graph& setAll_TickMarks(char axis, const vector<TickObject>& ticks);
	Graph& set_numMinorTicks(int num);

	Graph& set_title(std::string_view title);
	Graph& set_grid(bool b);
	Graph& set_autoscale();
	Graph& set_LargeTerminal();
	Graph& replot();
	Graph& flush();

	Graph& createPlot(const PlotObject& oneSetData);
	Graph& createPlot(const vector<PlotObject>& dataSet);
	Graph& createLivePlot(const PlotObject& oneSetData);
	Graph& createLivePlot(const vector<PlotObject>& dataSet);

	Graph& createMultiplot(const vector<PlotObject>& dataSet);
	Graph& createMultiplot(const vector<vector<PlotObject>>& dataSets);
	Graph& createLiveMultiplot(const vector<PlotObject>& dataSet);
	Graph& createLiveMultiplot(const vector<vector<PlotObject>>& dataSets);

	// demo functions for reference
	void demo1RandomTwoLineChart();
	void demo2Multiplot();
	void demo3Multiplot();

private:
	Gnuplot _gp;
};

std::pair<int, int> generateLayout(int size);

#endif
