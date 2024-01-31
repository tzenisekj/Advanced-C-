#include <iostream>

using namespace std;

// function prototype
int GCD(int a, int b); 

int main() {
	cout << "GCD of 1589 and 268777 is -> " << GCD(1589, 268777) << endl;
	cout << "\nGCD of 66 and 88 is -> " << GCD(66, 88) << endl;
	cout << "\nGCD of 94833 and 123456789 is -> " << GCD(94833, 123456789) << endl; 
	cout << "\nGCD of 76 and 108 is -> " << GCD(76, 108) << endl; 
	cout << "\nGCD of 0 and 100 is -> " << GCD(0, 100) << endl; 
	cout << "\nGCD of 100 and 0 is -> " << GCD(100, 0) << endl; 
	cout << "\nGCD of 5 and 10 is -> " << GCD(5, 10) << endl; 
	cout << "\nGCD of -150 and 74 is -> " << GCD(-150, 74) << endl; 
	cout << "\nGCD of -50 and -22 is -> " << GCD(-50, -22) << endl; 
	cout << "\nGCD of 5 and 7 is -> " << GCD(5, 7) << std::endl; 
	return EXIT_SUCCESS;
}

// recrusive fucntion to find greatest common divisor of 2 numbers
int GCD(int a, int b) {
	if (b != 0 && a != 0) {
		if (a % b == 0) {
			return b;
		}
		else {
			return GCD(b, a % b);
		}
	}
	else {
		if (a == 0)
			return a;
		else
			return b; 
	}
}