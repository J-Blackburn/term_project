#include "Gate.h"

using namespace std;

Gate::Gate(string tp, Wire *in1, Wire *in2, Wire *out, int dl) {
	type = tp;
	input1 = in1;
	input2 = in2;
	output = out;
	delay = dl;
}

bool Gate::compute() {
	char in1, in2, out;
	in1 = (*input1).getState();
	in2 = (*input2).getState();

	if(type == "AND") {
		if(in1 == '0' || in2 == '0') {
			out = '0';
		}
		else if(in1 == 'X' || in2 == 'X') {
			out = 'X';
		}
		else {
			out = '1';
		}
	}
	else if(type == "OR") {
		if(in1 == '1' || in2 == '1') {
			out = '1';
		}
		else if(in1 == 'X' || in2 == 'X') {
			out = 'X';
		}
		else {
			out = '0';
		}
	}
	else if(type == "XOR") {
		if(in1 == 'X' || in2 == 'X') {
			out = 'X';
		}
		else if(in1 == in2) {
			out = '0';
		}
		else {
			out = '1';
		}
	}
	else if(type == "NAND") {
		if(in1 == '1' || in2 == '1') {
			out = '0';
		}
		else if(in1 == 'X' || in2 == 'X') {
			out = 'X';
		}
		else {
			out = '1';
		}
	}
	else if(type == "NOR") {
		if(in1 == '1' || in2 == '1') {
			out = '0';
		}
		else if(in1 == 'X' || in2 == 'X') {
			out = 'X';
		}
		else {
			out = '1';
		}
	}
	else if(type == "XNOR") {
		if(in1 == 'X' || in2 == 'X') {
			out = 'X';
		}
		else if(in1 == in2) {
			out = '1';
		}
		else {
			out = '0';
		}
	}
	else if(type == "NOT") {
		if(in1 == 'X') {
			out = 'X';
		}
		else if(in1 == '1') {
			out = '0';
		}
		else {
			out = '1';
		}
	}
	else {
		cout << "missing/invalid gate type" << endl;
		return 0;
	}
	output->setState(out)
	cout << out << endl;
	return 1;
}

int Gate::getDelay() {
	return delay;
}
