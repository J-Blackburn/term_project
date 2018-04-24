#ifndef WIRE
#define WIRE
#endif
#pragma once

class Gate;

#include<vector>
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
	private:
	string name;
	int number;
	char state; //0,1,X
	vector <Gate*> gts;
};
