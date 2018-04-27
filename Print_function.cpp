//inplemented via command printHistories(&wires); given a vector of wire pointers called 'wires'
void printHistories(vector<Wire*> *wires) {
	
for(int i = 0; i < wires->size(); i++) {
	cout << "Wire Number " << (wires->at(i))->getNumber() << ": ";
	cout << (wires->at(i))->getHistory() << "  ";
	string str = (wires->at(i))->getHistory();
	while(str.find('0') < 100) {
		str.replace(str.find('0'),1,"_");
	}
	while(str.find('1') < 100) {
		str.replace(str.find('1'),1,"-");
	}
	cout << str << endl;
	}
}
