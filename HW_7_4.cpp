#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class BTNode {
private:
	int val = -1;
public:
	BTNode* left = NULL;
	BTNode* right = NULL;
public:
	BTNode() {};
	BTNode(int v) :val(v) {};
	int getVal() { return val; };
	BTNode* getLeft() { return left; };
	BTNode* getRight() { return right; };
	void setLeft(BTNode* l) { left = l; };
	void setRight(BTNode* r) { right = r; };
};

int getMaxValIndex(vector<int> BTVector, int start, int end) {
	if (start > end || BTVector.size() == 0)
		return -1;
	int Max = BTVector[start];
	int Index = start;
	for (int i = start + 1; i <= end; i++)
		if (BTVector[i] > Max) {
			Index = i;
			Max = BTVector[i];
		}
	return Index;
}

void CreateBTree(vector<int> BTVector, BTNode*& root, int start, int end) {
	if (start > end)
		return;
	int index = getMaxValIndex(BTVector, start, end);
	root = new BTNode(BTVector[index]);
	CreateBTree(BTVector, root->left, start, index - 1);
	CreateBTree(BTVector, root->right, index + 1, end);
	return;
}

void showBTree(BTNode* root) {
	if (root == nullptr)
		return;
	cout << root->getVal();
	if (root->left == NULL && root->right == NULL)
		return;
	cout << "(";
	showBTree(root->left);
	if (root->right != NULL) {
		cout << ",";
		showBTree(root->right);
	}
	cout << ")";
	return;
}

void DeleteBTree(BTNode* root) {
	if (root == nullptr)
		return;
	queue<BTNode*> BTQueue;
	BTQueue.push(root);
	while (!BTQueue.empty()) {
		if (BTQueue.front()->right != nullptr) {
			BTQueue.push(BTQueue.front()->right);
		}
		if (BTQueue.front()->left != nullptr) {
			BTQueue.push(BTQueue.front()->left);
		}
		delete BTQueue.front();
		BTQueue.pop();
	}
	return;
}

int main() {
	vector<int> BTVector;
	ifstream ifs("in.txt");
	int temp = 0;
	while (ifs >> temp)
		BTVector.push_back(temp);
	ifs.close();
	BTNode* root = NULL;
	CreateBTree(BTVector, root, 0, BTVector.size() - 1);
	showBTree(root);
	DeleteBTree(root);
	return 0;
}