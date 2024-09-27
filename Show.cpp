#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs("in.txt");
	string temp = "";
	while (ifs >> temp) 
		cout << temp << endl;
	ifs.close();
	while (cin >> temp)
		cout << temp << endl;
	return 0;
}