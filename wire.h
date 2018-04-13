#ifndef WIRE
#define WIRE

#pragma once

class gate;

#include <iostream>
#include <string>
using namespace std;

class wire {
	public:
	wire(string nm, int num, char st = 'X');
	void setState(char st);
	private:
	string name;
	int number;
	char state; //0,1,X
	vector <gate*>;
}