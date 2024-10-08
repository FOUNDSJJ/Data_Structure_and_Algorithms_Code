#include <iostream>
#include <fstream>

using namespace std;

string IntToString(int num) {
	string temp = "";
	string result = "";
	while (num % 10 > 0) {
		temp += (char)(num % 10 + 48);
		num = num / 10;
	}
	int i = (int)temp.length() - 1;
	while (i > -1) {
		result += temp[i];
		result += ' ';
		i--;
	}
	return result;
}

string CompressString() {
	ifstream ifs("in.txt");
	char temp = ' ';
	char LastChar = ' ';
	int num = 0;
	string result = "";
	while (ifs >> temp) {
		if (temp != ' ') {
			if (temp == LastChar) {
				num++;
			}
			else {
				if (LastChar == ' ') {
					LastChar = temp;
					num++;
				}
				else {
					result += LastChar;
					result += ' ';
					if (num > 1) {
						result += IntToString(num);
					}
					LastChar = temp;
					num = 1;
				}
			}
		}
	}
	result += LastChar;
	result += ' ';
	if (num > 1)
		result += IntToString(num);
	return result;
}

int main() {
	cout << CompressString();
	return 0;
}