#include <iostream>
#include "Fixed.hpp"

using namespace std;

int main() {
	cout.precision(10);
	{
		cout << "\nFixed a:" << endl;
		Fixed a;

		cout << "\nFixed const b(10):" << endl;
		Fixed const b(10);

		// 42.42 * (1<<8) = 10859.52 -> 10859
		// toFloat = 10859 / (1<<8) = 42.41796875
		cout << "\nFixed const c(42.42f):" << endl;
		Fixed const c(42.42f);

		cout << "\nFixed const d(b):" << endl;
		Fixed const d(b);

		// 1234.4321 * (1<<8) = 316014.6176 -> 316014
		// toFloat = 316014 / (1<<8) = 1234.4296875
		cout << "\na = Fixed(1234.4321f):" << endl;
		a = Fixed(1234.4321f);

		cout << endl;

		cout << "a is " << a << endl;
		cout << "b is " << b << endl;

		cout << "c is " << c << endl;
		cout << "d is " << d << endl;

		cout << endl;

		cout << "a is " << a.toInt() << " as integer" << endl;
		cout << "b is " << b.toInt() << " as integer" << endl;
		cout << "c is " << c.toInt() << " as integer" << endl;
		cout << "d is " << d.toInt() << " as integer" << endl;

		cout << endl;

		cout << "a is " << a.toFloat() << " as float" << endl;
		cout << "b is " << b.toFloat() << " as float" << endl;
		cout << "c is " << c.toFloat() << " as float" << endl;
		cout << "d is " << d.toFloat() << " as float" << endl;
		cout << endl;
	}
	{
		Fixed const a1(0);
		Fixed const a2(100);
		Fixed const a3(100.000f);
		Fixed const a4(1234.56789f);
		Fixed const a5(INT_MAX/256);
		Fixed const a6(INT_MAX);
		Fixed const b1(-1);
		Fixed const b2(-1.001f);
		Fixed const b3(-100);
		Fixed const b4(-100.00f);
		Fixed const b5(INT_MIN/256);
		Fixed const b6(INT_MIN);
		cout << endl;
		cout << "a1(0)           = " << a1 << endl;
		cout << "a2(100)         = " << a2 << endl;
		cout << "a3(100.000f)    = " << a3 << endl;
		cout << "a4(1234.56789f) = " << a4 << endl;
		cout << "a5(INT_MAX/256) = " << a5 << endl;
		cout << "a6(INT_MAX)     = " << a6 << endl;
		cout << endl;
		cout << "b1(-1)          = " << b1 << endl;
		cout << "b2(-1.001f)     = " << b2 << endl;
		cout << "b3(-100)        = " << b3 << endl;
		cout << "b4(-100.00f)    = " << b4 << endl;
		cout << "b5(INT_MIN/256) = " << b5 << endl;
		cout << "b6(INT_MIN)     = " << b6 << endl;
		cout << endl;
		cout << "INT_MAX/256     = " << INT_MAX/256 << endl;
		cout << "INT_MIN/256     = " << INT_MIN/256 << endl;
		cout << endl;
	}

//	system("leaks a.out");
	return 0;
}