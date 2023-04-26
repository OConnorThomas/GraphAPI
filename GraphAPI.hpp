// Copyright 2023 Thomas O'Connor
#ifndef GRAPH_API
#define GRAPH_API

#include "gnuplot-iostream.h"
#include "SmallClasses.hpp"

#define GNUPLOT_FILE_PATH "\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\""

using std::string;
using std::vector;

class Graph {
 public:
	 // Default Constructor
	 inline Graph() : _gp(GNUPLOT_FILE_PATH) {}

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
	 Graph& replot();

	 Graph& createLivePlot(std::string source);
	 Graph& createLiveMultiplot(vector<std::string> sources);

	 // demo functions for reference
	 void demo1RandomTwoLineChart();
	 void demo2Multiplot();

 private:
	 Gnuplot _gp;
};

#endif
