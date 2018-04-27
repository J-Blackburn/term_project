//includes + other preliminaries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
//include custom classes
#include "Gate.h"
#include "Wire.h"
#include "Event.h" 

using namespace std;

//functions
void wireInitialization(string ln, vector<Wire*> *wires) {
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
	wires->push_back(&myWire);
}

void gateInitialization(string ln, vector<Wire*> *wires) {
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
	bool in1Found = false;
	for(int i = 0; i < wires->size(); i++) {
		if((wire->at(i))->getNumber == in1) {
			Wire *ptr1 = wires->at(i);
			in1Found = true;
			break;
		}
	}
	bool in2Found = false;
	for(int i = 0; i < wires->size(); i++) {
		if((wire->at(i))->getNumber == in2) {
			Wire *ptr2 = wires->at(i);
			in2Found = true;
			break;
		}
	}
	bool outFound = false;
	for(int i = 0; i < wires->size(); i++) {
		if((wire->at(i))->getNumber == out) {
			Wire *ptr3 = wires->at(i);
			outFound = true;
			break;
		}
	}
	if(!in1Found) {
		Wire in1Wire("arbitrary_name", in1, 'X');
		Wire *ptr1 = &in1Wire;
	}
	if(!in2Found) {
		Wire in2Wire("arbitrary_name", in2, 'X');
		Wire *ptr2 = &in2Wire;
	}
	if(!outFound) {
		Wire outWire("arbitrary_name", out, 'X');
		Wire *ptr3 = &outWire;
	}
	//create gate
	gate myGate(gateType, ptr1, ptr2, ptr3, gateDelay)
}

bool parseCircuitFile(string fileName, vector<Wire*> *wires) {
	fileName += ".txt";
	ifstream myfile (fileName);
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			if(line.substr(0,line.find(" ")) == "CIRCUIT") {}
			else if(line.substr(0,line.find(" ")) == "INPUT" || line.substr(0,line.find(" ")) == "OUTPUT")
				wireInitialization(line, wires);
			else
				gateInitialization(line, wires);
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


//main loop
int main(int argc, char **argv) {
	//create a vector of wire pointers to keep track of wires
	priority_queue<Event> eventQueue;
	vector<*Wire> wires;
	string fileName = argv[1];
	//parse the circuit description file
	if(!parseCircuitFile(fileName, &wires)) {
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
	//printWireHistories
	return 0;
}



