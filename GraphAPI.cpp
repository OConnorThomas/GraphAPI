// Copyright 2023 Thomas O'Connor

#include "GraphAPI.hpp"

Graph& Graph::set_Label(char axis, std::string_view label) {
	_gp << "set " << axis << "label'" << label << "'\n ";
	return *this;
}

// Pass in NULL for bounds if you want to let GNUPLOT decide automatically
Graph& Graph::set_Range(char axis, int lowBound, int upBound) {
	if (lowBound == NULL) static_cast<char>(lowBound = '*');
	if (upBound == NULL) static_cast<char>(upBound = '*');
	_gp << "set " << axis << "range[" << lowBound << ":" << upBound << "]\n ";
	return *this;
}

Graph& Graph::set_TickMarks(char axis, int frequency) {
	_gp << "set " << axis << "tics " << frequency << '\n';
	return *this;
}

// String item format: { "\"Unique\" 6.66 1" } || { label, position, 0 major/1minor tic }
Graph& Graph::setNew_TickMark(char axis, TickObject obj) {
	_gp << "set " << axis << "tics add(";
	if (obj._label != "") _gp << '\"' << obj._label << "\" ";
	_gp << obj._position << ' ' << obj._majMinor << ")\n ";
	return *this;
}

// String list format: { "1,2,4,8,16,32,64, \"Max\"128" }
// Diplaces all tic marks on that axis. Use keyword "auto" to reset
Graph& Graph::setAll_TickMarks(char axis, const vector<TickObject>& ticks) {
	string list;
	for (size_t i = 0; i < ticks.size(); i++) {
		if (ticks[i]._label != "") {
			list.push_back('\"');
			list.append(ticks[i]._label);
			list.append("\" ");
		}
		list.append(std::to_string(ticks[i]._position));
		list.push_back(' ');
		list.append(std::to_string(ticks[i]._majMinor));
		if (i + 1 != ticks.size()) list.append(", ");
	}
	_gp << "set " << axis << "tics (" << list << ")\n ";
	return *this;
}

Graph& Graph::set_numMinorTicks(int num) {
	_gp << "set mxtics " << num << '\n';
	return *this;
}

Graph& Graph::set_title(std::string_view title) {
	_gp << "set title'" << title << "'\n ";
	_gp << "set terminal qt title '" << title << "'\n ";
	// _gp << "set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb\"#ffcccc\" behind\n ";
	return *this;
}

Graph& Graph::set_grid(bool b) {
	if (b)
		_gp << "set grid\n ";
	else
		_gp << "unset grid\n ";
	return *this;
}

Graph& Graph::set_autoscale() {
	_gp << "set autoscale\n ";
	return *this;
}

Graph& Graph::replot() {
	_gp << "replot\n ";
	return *this;
}

// must go at the end of your call chains
// keybind 'x' to close graph window
Graph& Graph::createLivePlot(std::string source) {
	_gp << "plot '" << source << "' using 1:2 title \"" << source << "\" with lines\n ";
	_gp << "done = 0\n ";
	_gp << "bind all 'x' 'done = 1'\n ";
	_gp << "while (!done) {\n ";
	_gp << "pause 0.2\n ";
	_gp << "replot\n ";
	_gp << "}\n ";
	return *this;
}








#include <numeric>
#include <iostream>
#include <random>

void Graph::demo1RandomTwoLineChart() {
	Gnuplot gp("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");

	std::random_device rd;
	std::mt19937 mt(rd());
	std::normal_distribution<double> nd(0., 1.);

	std::vector<double> v0, v1;
	for (int i = 0; i < 1000; i++) {
		v0.push_back(nd(mt));
		v1.push_back(nd(mt));
	}

	std::partial_sum(v0.begin(), v0.end(), v0.begin());
	std::partial_sum(v1.begin(), v1.end(), v1.begin());

	gp << "set title 'Graph of two random lines'\n ";
	gp << "plot '-' with lines title 'v0',"
		<< "'-' with lines title 'v1'\n ";
	gp.send(v0);
	gp.send(v1);

	std::cin.get();
}

void Graph::demo2Multiplot() {
	Gnuplot gp("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");

	gp << "set multiplot layout 2, 2 columnsfirst margins 0.1, 0.9, 0.1, 0.9 spacing 0.1\n ";
	gp << "set ylabel 'ylabel'\n ";
	gp << "plot sin(x)\n ";
	gp << "set xlabel 'xlabel'\n ";
	gp << "plot cos(x)\n ";
	gp << "unset ylabel\n ";
	gp << "unset xlabel\n ";
	gp << "plot sin(2 * x)\n ";
	gp << "set xlabel 'xlabel'\n ";
	gp << "plot cos(2 * x)\n ";
	gp << "unset multiplot\n ";
	gp << "while(1) {\n ";
	gp << "pause 3\n ";
	gp << "reread\n ";
	gp << "}\n ";
}
