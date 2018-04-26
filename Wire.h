#ifndef WIRE
#define WIRE
#endif
#pragma once

class Gate;

//#include "Gate.h"
//#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Wire {
	public:
	Wire(string nm, int num, char st = 'X');
	void setState(char st);
	char getState();
	string getName();
	int getNumber();
	string getHistory();
	void updateHistory(char newPoint);
	
	private:
	string name;
	int number;
	char state; //0,1,X
	string history = "";
//	vector <Gate*> gts;
};
