#include <iostream>
#include <fstream>

using namespace std;

int num = 0;

int* board;

void NQueen(int n, int N) {
	if (n == N) {
		num++;
		return;
	}
	if (n < 0 || n > N)
		return;
	for (int i = 0; i < N; i++) {
		bool Tag = true;
		for (int m = 0; m < n; m++) {
			if (board[m] == i || i - board[m] == n - m || i - board[m] == m - n) {
				Tag = false;
				break;
			}
		}
		if (Tag) {
			board[n] = i;
			NQueen(n + 1, N);
		}
	}
	return;
}

int main() {
	int N = 0;
	ifstream ifs("in.txt");
	ifs >> N;
	ifs.close();
	board = new int[N];
	NQueen(0, N);
	cout << num;
	delete[] board;
	return 0;
}