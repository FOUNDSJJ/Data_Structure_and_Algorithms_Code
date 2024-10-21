#include <iostream>
#include <fstream>

using namespace std;

void initialize(int*& unicomRoad, int cityNums) {
	for (int i = 0; i < cityNums; i++) {
		unicomRoad[i] = i;
	}
	return;
}

int getRootPoint(int* unicomRoad, int i) {
	while (unicomRoad[i] != i) {
		i = unicomRoad[i];
	}
	return i;
}

int calculateUnconnectedRoads(int* unicomRoad, int cityNums) {
	int result = -1;
	for (int i = 0; i < cityNums; i++) {
		if (unicomRoad[i] == i)
			result++;
	}
	return result;
}

void linkUnicomRoad(int*& unicomRoad, int roadNums, ifstream& ifs) {
	int city1 = 0, city2 = 0;
	for (int i = 0; i < roadNums; i++) {
		ifs >> city1 >> city2;
		unicomRoad[getRootPoint(unicomRoad, city1 - 1)] = getRootPoint(unicomRoad, city2 - 1);
	}
	return;
}


int main() {
	ifstream ifs("in.txt");
	int cityNums = 0, roadNums = 0;
	ifs >> cityNums >> roadNums;
	int* unicomRoad = new int[cityNums];
	initialize(unicomRoad, cityNums);
	linkUnicomRoad(unicomRoad, roadNums, ifs);
	cout << calculateUnconnectedRoads(unicomRoad, cityNums);
	ifs.close();
	delete[] unicomRoad;
	return 0;
}