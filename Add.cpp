#include <iostream>

using namespace std;

int main() {
	cout <<(long long) 0x8000000000000000<< endl;
	cout <<(long long) 0xD000000000000000<< endl;
	cout <<std::hex<< (0x8000000000000000 + 0x5000000000000000)<<endl;
	return 0;
}