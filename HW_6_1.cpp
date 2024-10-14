#include <iostream>
#include <fstream>

using namespace std;

int arr[] = { 0,0,0,1 };

void CowStory(int n, int N) {
	if (n < 0 || n >= N)
		return;
	arr[3] += arr[2];
	arr[2] = arr[1];
	arr[1] = arr[0];
	arr[0] = arr[3];
	CowStory(n + 1, N);
	return;
}

int main() {
	int N;
	ifstream ifs("in.txt");
	ifs >> N;
	ifs.close();
	CowStory(1, N);
	cout << arr[0] + arr[1] + arr[2] + arr[3];
	return 0;
}