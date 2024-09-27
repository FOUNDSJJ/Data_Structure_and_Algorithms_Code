#include <iostream>

using namespace std;

class MyString {
public:
	char val;
	bool is_Pop;
	MyString() {
		is_Pop = false;
	}
	MyString(char v) {
		val = v;
		is_Pop = false;
	}
};

bool is_Legal(MyString*& str_push, MyString*& str_test, int num_MyString, int num_test) {
	int i = 0;
	int last_j = 0;
	for (int j = 0; j < num_MyString; j++) {
		if (str_push[j].is_Pop == false && str_push[j].val == str_test[i].val) {
			str_push[j].is_Pop = true;
			last_j = j;
		}
	}
	i++;
	while (i < num_test) {
		int j = 0;
		int num_Pop = 0;
		for (; j < num_MyString; j++) {
			if (str_push[j].is_Pop == false && str_push[j].val == str_test[i].val) {
				str_push[j].is_Pop = true;
				break;
			}
		}
		for (int m = j + 1; m < last_j; m++)
			if (str_push[m].is_Pop == true)
				num_Pop++;
		if (j - last_j < -1 - num_Pop)
			return false;
		last_j = j;
		i++;
	}
	return true;
}

int main() {
	int num_MyString = 0;
	cin >> num_MyString;
	MyString* str_push = new MyString[num_MyString];
	for (int i = 0; i < num_MyString; ) {
		char temp;
		cin >> temp;
		if (temp != ' ') {
			str_push[i].val = temp;
			i++;
		}
	}
	MyString* str_test = new MyString[num_MyString];
	int i = 0;
	char temp;
	for (; cin >> temp && i < num_MyString; ) {
		if (temp != ' ') {
			str_test[i].val = temp;
			i++;
		}
	}
	if (is_Legal(str_push, str_test, num_MyString, i))
		cout << "true";
	else
		cout << "false";
	return 0;
}