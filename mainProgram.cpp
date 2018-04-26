//includes + other preliminaries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//include custom classes
#include "Gate.h"
#include "Wire.h"
#include "Event.h" // I'm guessing this is the name for the event class

using namespace std;

//functions
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
	//create wire
	Wire myWire(wireName, wireNumber, 'X');
	wires.push_back(&myWire);
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
	//generate wire pointers
	
	//create gate
	//gate myGate(gateType, /*name, wire* in1, wire* in2, wire* out,*/gateDelay)
}

bool parseCircuitFile(string fileName) {
	fileName += ".txt";
	ifstream myfile (fileName);
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			if(line.substr(0,line.find(" ")) == "CIRCUIT") {}
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

bool parseInitialConditionsFile(string eventFile) {
	ifstream myFile;
	myFile.open(eventFile + "_v.txt");
	if (myFile.is_open()) {
		string dummy;
		myFile >> dummy >> dummy; //Move past vector header.
		int counter = 0; //Counter used in place of forever while loop.
		while (counter < 1000) {
			string wireName;
			int time;
			bool newValue;
			myFile >> dummy >> wireName >> time >> newValue;
			
			//TODO: Insert this data into the event and priority-queue.
			if (myFile.eof()) { //If end of file reached.
				myFile.close();
				return true; //Read successful.
			}
			counter++;
		}
	}
	myFile.close();
	return false; //Read failed.
}
/*
circuit parsing:
  *importFileCircuitDefinition
  *wireInitialization
  *gateInitialization
initial conditions parsing
  *readEventFile
*printHistory
*/

//main loop
int main(int argc, char **argv) {
	//create a vector of wire pointers to keep track of wires
	vector<*Wire> wires;
	string fileName = argv[1];
	//parse the circuit description file
	if(!parseCircuitFile(fileName)) {
		cout << "Error: The circuit description file could not be read or doesn't exist." << endl;
		return 1;
	}
	//parse the initial conditions file
	if (!parseInitialConditionsFile(fileName)) {
		cout << "Error: The initial conditions file could not be read or doesn't exist." << endl;
		return 1;
	}
	
	//run events to simulate circuit
	
	//print history/results
	
	return 0;
}



