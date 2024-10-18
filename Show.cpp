#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs("in.txt");
	string temp = "";
	while (ifs >> temp) 
		cout << temp << endl;
	ifs.close();
	while (cin >> temp)
		cout << temp << endl;
	//float num =-0.179931640625;
	//printf("%X\n", 1000);
	//printf("%f\n", num);
	//unsigned char* p = (unsigned char*)&num;
	//for (int i = sizeof(num) - 1; i >= 0; i--) { 
	//	printf("%02X", p[i]); 
	//}
	//printf("\n\n");
	//cout << (float)(0x3FB98270);
	return 0;
}