#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class BTNode {
public:
	int val;
	BTNode* left = nullptr;
	BTNode* right = nullptr;
	BTNode() {};
	BTNode(int v) :val(v) {};
	void setBTNode(int v) { val = v; };
	int getVal() { return val; };
	BTNode* getLeft() { return left; };
	BTNode* getRight() { return right; };
};

queue<BTNode*> BTQueue;

void CreateBTree(string st, BTNode*& root) {
	int i = 0, top = -1, k = -1;
	BTNode* St[2000];
	BTNode* p = nullptr;
	root = nullptr;
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

void CollectLeaves(BTNode* root, vector<int>& Leaves) {
	if (root == nullptr)
		return;
	if (root->left == nullptr && root->right == nullptr) {
		Leaves.push_back(root->getVal());
		return;
	}
	CollectLeaves(root->left, Leaves);
	CollectLeaves(root->right, Leaves);
	return;
}

void showLeaves(vector<int> Leaves, bool beginRight) {
	if (Leaves.empty())
		return;
	if (beginRight) {
		for (int i = Leaves.size() - 1; i >= 0; i--) {
			cout << Leaves[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < (int)Leaves.size(); i++) {
		cout << Leaves[i] << " ";
	}
	cout << endl;
	return;
}

void CleanQueue(queue<BTNode*> BTQueue) {
	while (!BTQueue.empty())
		BTQueue.pop();
	return;
}

void showBTree(BTNode* root) {
	if (root == nullptr)
		return;
	BTQueue.push(root);
	while (!BTQueue.empty()) {
		cout << BTQueue.front()->getVal() << " ";
		if (BTQueue.front()->right != nullptr) {
			BTQueue.push(BTQueue.front()->right);
		}
		if (BTQueue.front()->left != nullptr) {
			BTQueue.push(BTQueue.front()->left);
		}
		BTQueue.pop();
	}
	return;
}

int main() {
	ifstream ifs("in.txt");
	string str = "";
	ifs >> str;
	ifs.close();
	BTNode* root = nullptr;
	CreateBTree(str, root);
	vector<int> Leaves;
	CollectLeaves(root, Leaves);
	showLeaves(Leaves, false);
	showLeaves(Leaves, true);
	CleanQueue(BTQueue);
	showBTree(root);
	cout << endl;
	return 0;
}