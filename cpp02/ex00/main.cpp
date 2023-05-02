#include <iostream>
#include <string>

#include "Fixed.hpp"

using namespace std;

int main() {

	cout << "\nFixed a:" << endl;
	Fixed a;

	cout << "\nFixed b(a):" << endl;
	Fixed b(a);

	cout << "\nFixed c:" << endl;
	Fixed c;

	cout << "\nc = b:" << endl;
	c = b;


	cout << "\na.getRawBits():" << endl;
	cout << a.getRawBits() << endl;

	cout << "\nb.getRawBits():" << endl;
	cout << b.getRawBits() << endl;

	cout << "\nc.getRawBits():" << endl;
	cout << c.getRawBits() << endl;

	cout << endl;
//	system("leaks a.out");
	return 0;
}