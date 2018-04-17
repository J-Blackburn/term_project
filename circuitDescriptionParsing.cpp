#include <iostream>
#include <string>
using namespace std;

int main() {
	string test = "ONE  TWO   THREE";
	string test2 = "First  Second";
	string a,b,c,d;
	a = test.substr(0, test.find(" "));
	test.erase(0,test.find(" "));
	test.erase(0,test.find_first_not_of(" "));
	b = test.substr(0,test.find(" "));
	test.erase(0,test.find(" "));
	test.erase(0,test.find_first_not_of(" "));
	c = test.substr(0,test.find(" "));
	cout << a << "." << b << "." << c << "." << endl;
	a = test2.substr(0, test2.find(" "));
	test2.erase(0,test2.find(" "));
	test2.erase(0,test2.find_first_not_of(" "));
	b = test2.substr(0,test2.find(" "));
	test2.erase(0,test2.find(" "));
	test2.erase(0,test2.find_first_not_of(" "));
	c = test2.substr(0,test2.find(" "));
	cout << a << "." << b << "." << c << "." << endl;
}
