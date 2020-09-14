#include <iostream>
#define N 10000000

using namespace std;


class Byte {
public:
	int dig[8];

	Byte(int num) {
		for (int i = 0; i < 8; i++)
			dig[i] = 0;
		int n = 7;
		if (num < 0)
			dig[0] = -1;
		else {
			while (num > 0) {
				dig[n] = num % 10;
				num /= 10;
				n--;
			}
		}
	}

	Byte operator *(const Byte& b) const{ //logical
		Byte byte(0);
		for (int i = 0; i < 8; i++) {
			byte.dig[i] = b.dig[i] * dig[i];
		}
		return byte;
	}

	/*Byte operator +(const Byte& b) const { //logical
		Byte byte(0);
		for (int i = 0; i < 8; i++) {
			if (b.dig[i] == 0 && dig[i]==0)
				byte.dig[i] = 0;
			else
				byte.dig[i] = 1;
		}
		return byte;
	}*/

	Byte operator +(const Byte& b) const {
		Byte byte(0);
		int sum = 0, inMem=0;

		for (int i = 7; i >=0; i--) {
			if (b.dig[i] + dig[i] + inMem == 3) {
				inMem = 1;
				byte[i] = 1;
			}
			else if (b.dig[i] + dig[i] + inMem == 2) {
				inMem = 1;
				byte[i] = 0;
			}
			else if (b.dig[i] + dig[i] + inMem == 1) {
				inMem = 0;
				byte[i] = 1;
			}
			else {
				inMem = 0;
				byte[i] = 0;
			}

			if (i == 0 && inMem == 1) {
				cout << "out of memory"<<endl;
				return -1;
			}	
		}
		return byte;
	}

	Byte operator -(const Byte& b) const {
		Byte byte(0);
		int sum = 0, inMem = 0;

		for (int i = 7; i >= 0; i--) {
			if (dig[i] > b.dig[i]){
				if (!inMem) {
					inMem = 0;
					byte[i] = 1;
				}
				else {
					inMem = 0;
					byte[i] = 0;
				}
			}
			else if (dig[i] < b.dig[i])
			{
				if (!inMem) 
					byte[i] = 1;
				else 
					byte[i] = 0;
				inMem = 1;
			}
			else if (dig[i] == b.dig[i] == 0) {
				if (!inMem) {
					inMem = 0;
					byte[i] = 0;
				}
				else {
					inMem = 1;
					byte[i] = 1;
				}
			}
			else{
				if (!inMem) {
					inMem = 0;
					byte[i] = 0;
				}
				else {
					inMem = 1;
					byte[i] = 1;
				}
			}

			if (i == 0 && inMem == 1) {
				cout << "out of memory" << endl;
				return -1;
			}
		}
		return byte;
	}

	int& operator [](const int index) {
		return dig[index];
	}

	friend ostream& operator <<(ostream& out, const Byte& b) {
		if (b.dig[0] >= 0) {
			out << "0b";
			for (int i = 0; i < 8; i++)
				out << b.dig[i];
			return out;
		}
	}
};

int main() {
	Byte b(11101), a(1010);
	cout <<"b = " <<b<<endl<<"a = "<<a<<endl;
	cout << "a*b = "<<a*b<<endl<<"a+b = "<<a+b<<endl;
	cout <<"a[7] = "<<a[7]<<endl;
	a[7] = 0;
	cout <<"a[7] = 0 => "<< a<<endl;
	

	Byte c(11111111);
	cout << b-a;
	



}