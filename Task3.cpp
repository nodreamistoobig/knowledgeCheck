#include <iostream>
#include <fstream>

using namespace std;

int main() {
	const int N = 100;
	string maxStr;
	int lenStr=0;

	ifstream in("words.txt");
	while (!in.eof()) {
		string str;
		in >> str;
		if (str.length() > lenStr) {
			lenStr = str.length();
			maxStr = str;
		}
	}

	cout << maxStr;
}