#include <iostream>

using namespace std;

int main() {

	const int N = 100;
	char vowels[] = { 'e','y','u','i','o','a' };

	int v=0, c, letters =0;

	char str [N];
	cin >> str;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < sizeof(vowels); j++)
			if (vowels[j] == str[i])
				v++;
		if (str[i]>0)
			letters++;
	}

	c = letters - v;

	cout << "vowels = " << v << " consonants = " << c << endl;

	return 0;
}