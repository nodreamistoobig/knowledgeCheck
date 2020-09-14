#include <iostream>

using namespace std;

int main() {
	double numArray[10];

	for (int i = 0; i < 10; i++) {
		int n = rand();
		n %= 200;
		n -= 100;
		double d = rand();
		d /= 100000;
		double randomNum = double(n + d);
		cout << randomNum << endl;
		numArray[i] = randomNum;
	}

	cout << endl;

	for (int j = 0; j < 10; j++) {
		double r;
		for (int i = 0; i < 9; i++) {
			if (numArray[i] - int(numArray[i]) > numArray[i + 1] - int(numArray[i + 1])) {
				r = numArray[i];
				numArray[i] = numArray[i + 1];
				numArray[i + 1] = r;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		cout << numArray[i]<<endl;

}