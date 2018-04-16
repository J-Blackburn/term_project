#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool readEventFile(string eventFile) {
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

int main (){
	//Setup: Get file name and initialize event and priority-queue.
	//TODO: Event and priority-queue stuff.

	string fileName;
	cout << "Enter the name of the file. (no _v or .txt)" << endl << "->";
	cin >> fileName;

	//Step 1: Get info. from circuit description file.

	//TODO: Write stuff to do this.

	//Step 2: Get info. from vector file.

	bool goodRead;
	goodRead = readEventFile(fileName);
	if (!goodRead) {
		cout << "Error: The vector file could not be read or doesn't exist." << endl;
			return 1;
	}

	return 0;
}
