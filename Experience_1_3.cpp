#include <iostream>

using namespace std;

class StudentQuene {
	int val = 0;
	bool tag = true;
public:
	int getVal() { return val; };
	bool getTag() { return tag; };
	void setVal(int v) { val = v; };
	void setTag(bool t) { tag = t; };
};

void NumberOff(StudentQuene*& MyQuene, int num) {
	int count = num;
	int i = 3;
	while (count > 2) {
		int j = -1;
		while (j < num) {
			for (int m = 0; m < i && j < num; ) {
				j++;
				if (MyQuene[j].getTag() == true)
					m++;
			}
			if (j >= num)
				break;
			MyQuene[j].setTag(false);
			count--;
		}
		if (i == 3)
			i = 2;
		else
			i = 3;
	}
}

void ShowQuene(StudentQuene* Quene, int num) {
	for (int i = 0; i < num; i++) {
		if (Quene[i].getTag())
			cout << Quene[i].getVal() << " ";
	}
}

int main() {
	int num = 0;
	cin >> num;
	StudentQuene* MyQuene = new StudentQuene[num];
	for (int i = 0; i < num; i++)
		MyQuene[i].setVal(i + 1);
	NumberOff(MyQuene, num);
	ShowQuene(MyQuene, num);
	delete[] MyQuene;
	return 0;
}