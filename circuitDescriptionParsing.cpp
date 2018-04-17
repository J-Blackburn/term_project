#include <iostream>
#include <fstream>
#include <string>

#include "gate.h"
#include "wire.h"

using namespace std;

void wireInitialization(string ln) {
	string wireType, wireName;
	int wireNumber;
	wireType = ln.substr(0, ln.find(" "));
	ln.erase(0,ln.find(" "));
	ln.erase(0,ln.find_first_not_of(" "));
	wireName = ln.substr(0,ln.find(" "));
	ln.erase(0,ln.find(" "));
	ln.erase(0,ln.find_first_not_of(" "));
	wireNumber = stoi(ln.substr(0,ln.find(" ")));
	cout << "Type: " << wireType << " Name: " << wireName;
	cout << " Number: " << wireNumber << endl;
	//create wire
	//wire myWire(wireName, wireNumber, 'x');
}

void gateInitialization(string ln) {
	string gateType, gd;
	int gateDelay, in1, in2, out;
	gateType = ln.substr(0, ln.find(" "));
	ln.erase(0,ln.find(" "));
	ln.erase(0,ln.find_first_not_of(" "));
	gd = ln.substr(0,ln.find(" "));
	gd.erase(gd.find("ns"), gd.size());
	gateDelay = stoi(gd);
	ln.erase(0,ln.find(" "));
	ln.erase(0,ln.find_first_not_of(" "));
	in1 = stoi(ln.substr(0,ln.find(" ")));
	ln.erase(0,ln.find(" "));
	ln.erase(0,ln.find_first_not_of(" "));
	in2 = stoi(ln.substr(0,ln.find(" ")));
	ln.erase(0,ln.find(" "));
	ln.erase(0,ln.find_first_not_of(" "));
	string temp = ln.substr(0,ln.find(" "));
	if(temp == "") {
		out = in2;
		in2 = -1;
	}
	else {
		out = stoi(temp);
	}
	cout << "Type: " << gateType << " Delay: " << gateDelay;
	cout << " Input 1: " << in1 << " Input 2: " << in2 ;
	cout << " Output: " << out << endl;
	//create gate
	//gate myGate(gateType, /*name, wire* in1, wire* in2, wire* out,*/gateDelay)
}

bool importFile(char *input) {
	string line;
	ifstream myfile (input);
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			if(line.substr(0,line.find(" ")) == "CIRCUIT")
				cout << "File is correct" << endl;
			else if(line.substr(0,line.find(" ")) == "INPUT" || line.substr(0,line.find(" ")) == "OUTPUT")
				wireInitialization(line);
			else
				gateInitialization(line);
		}
    myfile.close();
	}
	else return 0;;
	return 1;
}

int main(int argc, char **argv) {
	if(importFile(argv[1]))
		cout << "SUCCESSFUL PARSING" << endl;
	else 
		cout << "FAILED PARSING" << endl;
	return 0;
}
int main(int argc, char **argv) {
	if(importFile(argv[1]))
		cout << "SUCCESSFUL PARSING" << endl;
	else 
		cout << "FAILED PARSING" << endl;
	return 0;
}
