#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void postorder(int* preorder, int* inorder, int lenght) {
	int len = lenght;
	if (len == 0)
		return;
	if (len == 1) {
		cout << preorder[0] << " ";
		return;
	}
	int pos = -1;
	for (int i = 0; i < len; i++) {
		if (preorder[0] == inorder[i]) {
			pos = i;
			break;
		}
	}
	int* pretemp = new int[pos];
	int* intemp = new int[pos];
	for (int m = 1; m <= pos; m++)
		pretemp[m - 1] = preorder[m];
	for (int n = 0; n <= pos - 1; n++)
		intemp[n] = inorder[n];
	postorder(pretemp, intemp, pos);
	delete[] pretemp;
	delete[] intemp;
	int* pretemp1 = new int[len - pos - 1];
	int* intemp1 = new int[len - pos - 1];
	for (int m = 1; m <= (len - pos - 1); m++)
		pretemp1[m - 1] = preorder[m + pos];
	for (int m = 1; m <= (len - pos - 1); m++)
		intemp1[m - 1] = inorder[m + pos];
	postorder(pretemp1, intemp1, len - pos - 1);
	delete[] pretemp1;
	delete[] intemp1;
	cout << preorder[0] << " ";
	return;
}

int main() {
	ifstream ifs("in.txt");
	int num = 0;
	ifs >> num;
	int* preorder = new int[num];
	int* inorder = new int[num];
	for (int i = 0; i < num; i++)
		ifs >> preorder[i];
	for (int j = 0; j < num; j++)
		ifs >> inorder[j];
	ifs.close();
	postorder(preorder, inorder, num);
	return 0;
}
