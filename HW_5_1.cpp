#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string GetLongestSubstring(string s1, string s2) {
	int i = 0, j = s2.find_first_of(s1[0], 0);
	int k = j;
	string LongestSubstring = "";
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] != s2[j]) {
			LongestSubstring = "";
			j = s2.find_first_of(s1[0], k + 1);
			k = j;
			i = 0;
		}
		else {
			LongestSubstring += s1[i];
			i++;
			j++;
		}
	}
	return LongestSubstring;
}

int main() {
	ifstream ifs("in.txt");
	string s1, s2;
	ifs >> s1 >> s2;
	ifs.close();
	string LongestSubstrin = GetLongestSubstring(s1, s2);
	cout << LongestSubstrin << " " << LongestSubstrin.length();
	return 0;
}