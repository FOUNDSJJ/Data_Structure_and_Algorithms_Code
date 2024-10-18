#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class BTNode {
public:
	int val;
	BTNode* left = NULL;
	BTNode* right = NULL;
	BTNode(int v) :val(v) {};
};

void CreateBTree(string st, BTNode*& root) {
	int i = 0, top = -1, k = -1;
	BTNode* St[2000];
	BTNode* p = NULL;
	root = NULL;
	char ch = st[i];
	string temp = "";
	while (ch <= '9' && ch >= '0') {
		temp += ch;
		i++;
		ch = st[i];
	}
	int v = stoi(temp);
	root = new BTNode(v);
	p = root;
	temp = "";
	while (ch != '\0') {
		switch (ch) {
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			while (ch <= '9' && ch >= '0') {
				temp += ch;
				i++;
				ch = st[i];
			}
			int v = stoi(temp);
			p = new BTNode(v);
			temp = "";
			switch (k) {
			case 1:
				St[top]->left = p;
				break;
			case 2:
				St[top]->right = p;
				break;
			}
			i--;
		}
		i++;
		ch = st[i];
	}
}

int BTreeHeight(BTNode* root) {
	if (root == NULL)
		return 0;
	int LeftHeight = BTreeHeight(root->left);
	int RightHeight = BTreeHeight(root->right);
	int MaxHeight = (LeftHeight > RightHeight ? LeftHeight : RightHeight);
	return MaxHeight + 1;
}

int Calculate(int m, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return m;
	if (n % 2)
		return Calculate(m, n / 2) * Calculate(m, n / 2) * m;
	else
		return Calculate(m, n / 2) * Calculate(m, n / 2);
}

bool is_CompleteBinaryTree(BTNode* root) {
	if (root == NULL)
		return true;
	int height = BTreeHeight(root);
	vector<BTNode*> BTVector;
	BTVector.push_back(root);
	int base = 0;
	for (int i = 1; i < height - 1; i++) {
		int offset = Calculate(2, i - 1);
		int m = 0;
		for (; m < offset; m++) {
			if (BTVector[base + m]->left == NULL || BTVector[base + m]->right == NULL)
				return false;
			BTVector.push_back(BTVector[base + m]->left);
			BTVector.push_back(BTVector[base + m]->right);
		}
		base += m;
	}
	return true;
}

int main() {
	ifstream ifs("in.txt");
	string str = "";
	ifs >> str;
	ifs.close();
	BTNode* root = NULL;
	CreateBTree(str, root);
	if (is_CompleteBinaryTree(root))
		cout << 1;
	else
		cout << 0;
	return 0;
}