#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Case {
public:
	string str1 = "";
	string str2 = "";
};

int Caculate(stack<string>& Stack) {
	stack<string> MyStack;
	stack<int> num;
	while (!Stack.empty()) {
		MyStack.push(Stack.top());
		Stack.pop();
	}
	while (!MyStack.empty()) {
		string temp = MyStack.top();
		MyStack.pop();
		if (temp == "+") {
			int num2 = num.top();
			num.pop();
			int num1 = num.top();
			num.pop();
			num.push(num1 + num2);
		}
		else {
			if (temp == "-") {
				int num2 = num.top();
				num.pop();
				int num1 = num.top();
				num.pop();
				num.push(num1 - num2);
			}
			else {
				if (temp == "*") {
					int num2 = num.top();
					num.pop();
					int num1 = num.top();
					num.pop();
					num.push(num1 * num2);
				}
				else {
					if (temp == "/") {
						int num2 = num.top();
						num.pop();
						int num1 = num.top();
						num.pop();
						num.push(num1 / num2);
					}
					else {
						if (temp[0] > 64 && temp[0] < 91)
							num.push(int(temp[0]));
						else
							num.push(stoi(temp));
					}
				}
			}
		}
	}
	return num.top();
}

int getResult(string str) {
	stack<string> NumStack;
	stack<string> OpStack;
	string temp = "";
	for (int i = 0; i < (int)str.length(); i++) {
		switch (str[i]) {
		case ' ': {
			cout << " ";
			break;
		}
		case '+': {
			while (!OpStack.empty() && OpStack.top() != "(") {
				string temp = OpStack.top();
				NumStack.push(temp);
				OpStack.pop();
			}
			string s = "+";
			OpStack.push(s);
			break;
		}
		case '-': {
			while (!OpStack.empty() && OpStack.top() != "(") {
				string temp = OpStack.top();
				NumStack.push(temp);
				OpStack.pop();
			}
			string s = "-";
			OpStack.push(s);
			break;
		}
		case '*': {
			while (!OpStack.empty() && OpStack.top() != "(" && (OpStack.top() == "*" || OpStack.top() == "/")) {
				string temp = OpStack.top();
				NumStack.push(temp);
				OpStack.pop();
			}
			string s = "*";
			OpStack.push(s);
			break;
		}
		case '/': {
			while (!OpStack.empty() && OpStack.top() != "(" && (OpStack.top() == "*" || OpStack.top() == "/")) {
				string temp = OpStack.top();
				NumStack.push(temp);
				OpStack.pop();
			}
			string s = "/";
			OpStack.push(s);
			break;
		}
		case '(': {
			string s = "(";
			OpStack.push(s);
			break;
		}
		case ')': {
			while (!OpStack.empty() && OpStack.top() != "(") {
				string temp = OpStack.top();
				NumStack.push(temp);
				OpStack.pop();
			}
			OpStack.pop();
			break;
		}
		default:
			if ((str[i] < 91 && str[i]>64) || (str[i] < 123 && str[i]>96)) {
				temp += (char)(str[i] - 32 * ((int)str[i] / 96));
			}
			else {
				while (i < (int)str.length() && str[i] < 58 && str[i]>47) {
					temp += str[i];
					i++;
				}
				i--;
			}
			NumStack.push(temp);
			temp = "";
		}
	}
	while (!OpStack.empty()) {
		NumStack.push(OpStack.top());
		OpStack.pop();
	}
	return Caculate(NumStack);
}

void is_Equal(Case* TestCase) {
	string str1 = TestCase->str1;
	string str2 = TestCase->str2;
	if (getResult(str1) == getResult(str2))
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}

int main() {
	int CaseNums = 0;
	cin >> CaseNums;
	Case* MyCase = new Case[CaseNums];
	for (int i = 0; i < CaseNums; i++) {
		cin >> MyCase[i].str1 >> MyCase[i].str2;
		is_Equal(&MyCase[i]);
	}
	delete[] MyCase;
	return 0;
}