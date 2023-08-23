// Copyright 2023 Thomas O'Connor
#ifndef SMALL_CLASSES
#define SMALL_CLASSES

#include <string>
#include <exception>

using std::string;

class TickObject {
public:
	// Constructors
	inline TickObject(double P) :
		_label(""), _position(P), _majMinor(0) {}
	inline TickObject(double P, bool M) :
		_label(""), _position(P), _majMinor(M) {}
	inline TickObject(string L, double P, bool M) :
		_label(L), _position(P), _majMinor(M) {}

	// tick name optional
	string _label;
	// position on axis
	double _position = 0;
	// 0 major tick, 1 minor tick
	bool _majMinor = 0;
};

class PlotObject {
public:
	// Constructors
	inline PlotObject(string path) :
		_filePath(path), _lineTitle(path) {}
	inline PlotObject(string path, string title) :
		_filePath(path), _lineTitle(title) {}
	inline PlotObject(string path, int xAxis, int yAxis) :
		_filePath(path), _lineTitle(path), _x(xAxis), _y(yAxis) {}
	inline PlotObject(string path, string title, int xAxis, int yAxis) :
		_filePath(path), _lineTitle(title), _x(xAxis), _y(yAxis) {}
	inline PlotObject(string path, string title, int xAxis, int yAxis, double rr) :
		_filePath(path), _lineTitle(title), _x(xAxis), _y(yAxis), _refreshRate(rr) {}

	PlotObject& setRefreshRate(double rr) {
		if (rr <= 0.) throw "invalid_refresh_rate";
		_refreshRate = rr;
		return *this;
	}

	// source name
	string _filePath, _lineTitle;
	// xAxis & yAxis columns
	int _x = 1, _y = 2;
	double _refreshRate = 0.2;
};

#endif
