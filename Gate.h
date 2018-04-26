#ifndef GATE
#define GATE
#endif
#pragma once

class Wire;

#include "Wire.h"
#include <iostream>
#include <string>
using namespace std;

class Gate {
	public:
	Gate(string tp, Wire *in1, Wire *in2, Wire *out, int dl);
	bool compute(); //figure output from inputs and gate type
	int getDelay();
	private:
	string type;
	Wire *input1,*input2,*output;
	int delay;
};
