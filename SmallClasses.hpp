// Copyright 2023 Thomas O'Connor
#ifndef SMALL_CLASSES
#define SMALL_CLASSES

#include <string>

using std::string;

class TickObject {
public:
	// Constructors
	inline TickObject(string L, double P, bool M) :
		_label(L), _position(P), _majMinor(M) {}
	inline TickObject(double P, bool M) :
		_label(""), _position(P), _majMinor(M) {}
	inline TickObject(double P) :
		_label(""), _position(P), _majMinor(0) {}

	// tick name optional
	string _label;
	// position on axis
	double _position = 0;
	// 0 major tick, 1 minor tick
	bool _majMinor = 0;
};

#endif
