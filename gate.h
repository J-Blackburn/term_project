//josh
#ifndef GATE
#define GATE

#pragma once

class wire;

#include <iostream>
#include <string>
using namespace std;

class gate {
	public:
	gate(string tp, string nm, wire *in1, wire *in2, wire *out, int dl);
	void compute(); //figure output from inputs and gate type
	private:
	string type, name;
	wire *input1,*input2,*output;
	int delay;
}
