#include <iostream>
#include <fstream>

using namespace std;

int** arr;

void BuildRight(int& start_i, int& start_j, int& start_n, int num) {
	if (num <= 0)
		return;
	int j = 0;
	for (j = start_j; j < start_j + num; j++) {
		arr[start_i][j] = start_n;
		start_n++;
	}
	start_j = j - 1;
	return;
}

void BuildLeft(int& start_i, int& start_j, int& start_n, int num) {
	if (num <= 0)
		return;
	int j = 0;
	for (j = start_j; j > start_j - num; j--) {
		arr[start_i][j] = start_n;
		start_n++;
	}
	start_j = j + 1;
	return;
}

void BuildDown(int& start_i, int& start_j, int& start_n, int num) {
	if (num <= 0)
		return;
	int i = 0;
	for (i = start_i; i < start_i + num; i++) {
		arr[i][start_j] = start_n;
		start_n++;
	}
	start_i = i - 1;
	return;
}

void BuildUp(int& start_i, int& start_j, int& start_n, int num) {
	if (num <= 0)
		return;
	int i = 0;
	for (i = start_i; i > start_i - num; i--) {
		arr[i][start_j] = start_n;
		start_n++;
	}
	start_i = i + 1;
	return;
}

void BuildMatrix(int& start_i, int& start_j, int& start_n, int num) {
	if (num <= 0)
		return;
	if (num == 1) {
		BuildRight(start_i, start_j, start_n, num);
		return;
	}
	BuildRight(start_i, start_j, start_n, num);
	start_i++;
	BuildDown(start_i, start_j, start_n, num - 1);
	start_j--;
	BuildLeft(start_i, start_j, start_n, num - 1);
	start_i--;
	BuildUp(start_i, start_j, start_n, num - 2);
	start_j++;
	BuildMatrix(start_i, start_j, start_n, num - 2);
	return;
}

void showMatrix(int num) {
	cout << "[" << endl;
	for (int i = 0; i < num-1; i++) {
		cout << "[";
		for (int m = 0; m < num - 1; m++)
			cout << arr[i][m] << ",";
		cout << arr[i][num - 1] << "]," << endl;
		delete[] arr[i];
	}
	cout << "[";
	for (int m = 0; m < num - 1; m++)
		cout << arr[num-1][m] << ",";
	cout << arr[num-1][num - 1] << "]" << endl;
	delete[] arr[num-1];
	cout << "]";
	delete[] arr;
}

int main() {
	int num;
	ifstream ifs("in.txt");
	ifs >> num;
	ifs.close();
	arr = new int* [num];
	for (int i = 0; i < num; i++)
		arr[i] = new int[num];
	int start_i = 0, start_j = 0, start_n = 1;
	BuildMatrix(start_i, start_j, start_n, num);
	showMatrix(num);
	return 0;
}