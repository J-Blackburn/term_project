#include "gate.h"

using namespace std;

gate::gate(string tp, string nm, wire *in1, wire *in2, wire *out, int dl) {
	type = tp;
	name = nm;
	input1 = in1;
	input2 = in2;
	output = out;
	delay = dl;
}

void compute() {
	if(type == "AND") {
		*output = (*input1 && *input2);
	}
	else if(type == "OR") {
		*output = (*input1 || *input2);
	}
	else if(type == "XOR") {
		*output = (*input1 != *input2);
	}
	else if(type == "NAND") {
		*output = (!*input1 && !*input2);
	}
	else if(type == "NOR") {
		*output = !(*input1 || *input2);
	}
	else if(type == "XNOR") {
		*output = !(*input1 != *input2);
	}
	else if(type == "NOT") {
		*output = !(*input1);
	}
	else {
		cout << "missing/invalid gate type" << endl;
	}
	/*switch (gateCase) {
		case 1: //and gate
		*output = (*input1 && *input2);
		break;
		case 2: //or gate
		*output = (*input1 || *input2);
		break;
		case 3: //xor gate
		*output = (*input1 != *input2);
		break;
		case 4: //nand gate
		*output = (!*input1 && !*input2);
		break;
		case 5: //nor gate
		*output = !(*input1 || *input2);
		break;
		case 6: //xnor gate
		*output = !(*input1 != *input2);
		break;
		default:
		cout << "Ya done goofed son!" << endl;
		break;
	}*/
	//figure output from inputs and gate type
}
