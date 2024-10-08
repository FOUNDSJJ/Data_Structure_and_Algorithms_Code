#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int GetNum(string MainString, string SmallString) {
	int i = 0, j = 0, num = 0;
	while (i < (int)MainString.length() && j < (int)SmallString.length()) {
		if (MainString[i] != SmallString[j]) {
			i = i - j;
			j = -1;
		}
		else
			if (j == (int)SmallString.length() - 1) {
				num++;
				j = -1;
			}
		i++;
		j++;
	}
	return num;
}

int main() {
	ifstream ifs("in.txt");
	string MainString, SmallString;
	getline(ifs, MainString, ' ');
	getline(ifs, SmallString, ' ');
	cout << GetNum(MainString, SmallString);
	return 0;
}