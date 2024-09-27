#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int Caculate(string& Expression) {
	stack<int> MyStack;
	int i = 0;
	int num_1, num_2;
	string temp = "";
	for (; Expression[i] != '\0'; i++) {
		switch (Expression[i]) {
		case '+':
			num_2 = MyStack.top();
			MyStack.pop();
			num_1 = MyStack.top();
			MyStack.pop();
			MyStack.push(num_1 + num_2);
			break;
		case '-':
			if (Expression[i + 1] != '\0' && Expression[i + 1] != ',') {
				temp += '-';
				break;
			}
			num_2 = MyStack.top();
			MyStack.pop();
			num_1 = MyStack.top();
			MyStack.pop();
			MyStack.push(num_1 - num_2);
			break;
		case '*':
			num_2 = MyStack.top();
			MyStack.pop();
			num_1 = MyStack.top();
			MyStack.pop();
			MyStack.push(num_1 * num_2);
			break;
		case '/':
			num_2 = MyStack.top();
			MyStack.pop();
			num_1 = MyStack.top();
			MyStack.pop();
			MyStack.push(num_1 / num_2);
			break;
		case ',':
			if (temp != "") {
				int val = (int)stoi(temp);
				temp = "";
				MyStack.push(val);
			}
			break;
		default:
			temp += Expression[i];
		}
	}
	return MyStack.top();
}

int main() {
	ifstream ifs("in.txt");
	string Expression = "";
	ifs >> Expression;
	cout << Caculate(Expression);
	ifs.close();
	return 0;
}