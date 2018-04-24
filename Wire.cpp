#include "Wire.h"

using namespace std;

Wire::Wire(string nm, int num, char st) {
	name = nm;
	number = num;
	state = st;
}

void Wire::setState(char st) {
	state = st;
}

char Wire::getState() {
	return state;
}

string Wire::getName() {
	return name;
}

int Wire::getNumber() {
	return number;
}
