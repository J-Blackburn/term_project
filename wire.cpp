//josh
#include "wire.h"

using namespace std;

wire::wire(string nm, int num, char st = 'X') {
	name = nm;
	IDnumber = num;
	state = st;
}

void setState(char st) {
	state = st;
}
