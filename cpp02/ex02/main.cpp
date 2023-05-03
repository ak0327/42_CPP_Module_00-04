#include <iostream>
#include "Fixed.hpp"

using namespace std;

int main() {
	cout.precision(10);
	{
		cout << "\nFixed a:" << endl;
		Fixed a;

		cout << "\nFixed b(Fixed(5.05f) * Fixed(2)):" << endl;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		cout << "\na:" << endl;
		cout << a << endl;
		cout << "\n++a:" << endl;
		cout << ++a << endl;
		cout << "\na:" << endl;
		cout << a << endl;
		cout << "\na++:" << endl;
		cout << a++ << endl;
		cout << "\na:" << endl;
		cout << a << endl;
		cout << endl;
		cout << "\nb:" << endl;
		cout << b << endl;
		cout << endl;
		cout << "\nmax(a, b):" << endl;
		cout << Fixed::max(a, b) << endl;
		cout << endl;
	}

//	system("leaks a.out");
	return 0;
}