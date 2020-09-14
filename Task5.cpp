#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int freq[26], n;
	int count = 0;
	for (int i = 0; i < 26; i++)
		freq[i] = 0;
	ifstream in("lorem.txt");
	while (!in.eof()) {
		char c;
		in >> c;
		if (int(c) < 97)
			c = char(int(c) + 32);
		if (c >= 'a' || c <= 'z') {
			n = int(c) - 97;
			freq[n]++;
			count++;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << char(i + 97) << "=";
		if (freq[i] == 0)
			cout << 0 << endl;
		else
			cout << double(double(freq[i])/count) << endl;
	}

	return 0;
}