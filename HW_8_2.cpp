#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void initialize(int*& myTree, int nodeNums) {
	for (int i = 0; i < nodeNums; i++) {
		myTree[i] = i;
	}
	return;
}

void linkTree(int*& myTree, int nodeNums, ifstream& ifs) {
	int parentNode = 0, childNode = 0;
	for (int i = 0; i < nodeNums - 1; i++) {
		ifs >> parentNode >> childNode;
		myTree[childNode - 1] = parentNode - 1;
	}
	return;
}

int getMostRelatedAncestorNode(int*& myTree, int node1, int node2) {
	vector<int> ancestorNodes1, ancestorNodes2;
	ancestorNodes1.push_back(node1);
	ancestorNodes2.push_back(node2);
	while (myTree[node1] != node1) {
		ancestorNodes1.push_back(myTree[node1]);
		node1 = myTree[node1];
	}
	while (myTree[node2] != node2) {
		ancestorNodes2.push_back(myTree[node2]);
		node2 = myTree[node2];
	}
	int result = -1;
	for (int i = 0; i < (int)ancestorNodes1.size(); i++)
		for (int m = 0; m < (int)ancestorNodes2.size(); m++)
			if (ancestorNodes1[i] == ancestorNodes2[m]) {
				result = ancestorNodes1[i];
				return result;
			}
	return result;
}

int main() {
	ifstream ifs("in.txt");
	int nodeNums = 0;
	ifs >> nodeNums;
	int* myTree = new int[nodeNums];
	initialize(myTree, nodeNums);
	linkTree(myTree, nodeNums, ifs);
	int node1 = 0, node2 = 0;
	ifs >> node1 >> node2;
	cout << getMostRelatedAncestorNode(myTree, node1 - 1, node2 - 1) + 1;
	delete[] myTree;
	ifs.close();
	return 0;
}