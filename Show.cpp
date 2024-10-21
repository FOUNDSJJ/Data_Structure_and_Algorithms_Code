#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream ifs("in.txt");
	string temp = "";
	while (getline(ifs, temp, '\n'))
		cout << temp << endl;
	ifs.close();
	while (getline(cin, temp, '\n'))
		cout << temp << endl;
	return 0;
}