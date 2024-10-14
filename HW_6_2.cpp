#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int*> AllQueue;

int k = 0;

int* arr;

void getAllQueue(vector<int> IntQueue, int n, int num) {
	if (n<0 || n>num)
		return;
	if (n == num) {
		int* temp = new int[num];
		for (int i = 0; i < num; i++)
			temp[i] = arr[i];
		AllQueue.push_back(temp);
		return;
	}
	for (int i = IntQueue.size() - 1; i >= 0; i--) {
		if (IntQueue[i] != k) {
			arr[n] = IntQueue[i];
			int temp = IntQueue[i];
			IntQueue[i] = k;
			getAllQueue(IntQueue, n + 1, num);
			IntQueue[i] = temp;
		}
	}
	return;
}

void showAllQueue(int num) {
	for (int i = AllQueue.size() - 1; i >= 0; i--) {
		for (int m = 0; m < num; m++)
			cout << AllQueue[i][m] << " ";
		cout << endl;
		delete[] AllQueue[i];
	}
	return;
}

int main() {
	vector<int> IntQueue;
	int temp = 0;
	ifstream ifs("in.txt");
	int num = 0;
	while (ifs >> temp) {
		k += temp > 0 ? temp + 1 : -temp + 1;
		num++;
		IntQueue.push_back(temp);
	}
	arr = new int[num];
	getAllQueue(IntQueue, 0, num);
	showAllQueue(num);
	delete[] arr;
	ifs.close();
	return 0;
}