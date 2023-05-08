#include <iostream>
#include <iomanip>

#include "Fixed.hpp"


int main() {
	std::cout.precision(10);
	std::cout.setf(std::ios::left);
	int w;
	{
		Fixed a;
		Fixed const b(10);
		// 42.42 * (1<<8) = 10859.52 -> 10859
		// toFloat = 10859 / (1<<8) = 42.41796875
		Fixed const c(42.42f);
		Fixed const d(b);
		// 1234.4321 * (1<<8) = 316014.6176 -> 316014
		// toFloat = 316014 / (1<<8) = 1234.4296875
		a = Fixed(1234.4321f);

		std::cout << "Fixed a = Fixed(1234.4321f) = " << a << std::endl;
		std::cout << "Fixed const b(10)           = " << b << std::endl;

		std::cout << "Fixed const c(42.42f)       = " << c << std::endl;
		std::cout << "Fixed const d(b)            = " << d << std::endl;

		std::cout << std::endl;

		w = 10;
		std::cout << std::setw(w) <<  "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << std::setw(w) << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << std::setw(w) << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << std::setw(w) << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << std::endl;

		std::cout << std::setw(w) << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << "d is " << d.toFloat() << " as float" << std::endl;
		std::cout << std::endl;
	}
	{
		Fixed a;
		Fixed const b(-10);
		Fixed const c(-42.42f);
		Fixed const d(b);
		a = Fixed(-1234.4321f);

		std::cout << "Fixed a = Fixed(-1234.4321f) = " << a << std::endl;
		std::cout << "Fixed const b(-10)           = " << b << std::endl;

		std::cout << "Fixed const c(-42.42f)       = " << c << std::endl;
		std::cout << "Fixed const d(b)             = " << d << std::endl;

		std::cout << std::endl;

		w = 10;
		std::cout << std::setw(w) << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << std::setw(w) << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << std::setw(w) << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << std::setw(w) << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << std::endl;

		std::cout << std::setw(w) << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << "d is " << d.toFloat() << " as float" << std::endl;
		std::cout << std::setw(w) << std::endl;
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
		Fixed const b7(-1234.56789f);
		std::cout << std::endl;

		w = 20;
		std::cout << std::setw(w) << "a1(0)" << " = " << a1 << std::endl;
		std::cout << std::setw(w) << "a2(100)" << " = " << a2 << std::endl;
		std::cout << std::setw(w) << "a3(100.000f)" << " = " << a3 << std::endl;
		std::cout << std::setw(w) << "a4(1234.56789f)" << " = " << a4 << std::endl;
		std::cout << std::setw(w) << "a5(INT_MAX/256)" << " = " << a5 << std::endl;
		std::cout << std::setw(w) << "a6(INT_MAX)    " << " = " << a6 << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(w) << "b1(-1)" << " = " << b1 << std::endl;
		std::cout << std::setw(w) << "b2(-1.001f)" << " = " << b2 << std::endl;
		std::cout << std::setw(w) << "b3(-100)" << " = " << b3 << std::endl;
		std::cout << std::setw(w) << "b4(-100.00f)" << " = " << b4 << std::endl;
		std::cout << std::setw(w) << "b5(INT_MIN/256)" << " = " << b5 << std::endl;
		std::cout << std::setw(w) << "b6(INT_MIN)" << " = " << b6 << std::endl;
		std::cout << std::setw(w) << "b7(-1234.56789f)" << " = " << b7 << std::endl;
		std::cout << std::endl;
	}
	{
		Fixed a;
		a.setRawBits(INT_MAX);
		std::cout << a << std::endl;
		std::cout << std::endl;
	}
	w = 20;
	std::cout << std::setw(w) << "INT_MAX/256" << " = " << INT_MAX/256 << std::endl;
	std::cout << std::setw(w) << "INT_MIN/256" << " = " << INT_MIN/256 << std::endl;
	std::cout << std::setw(w) << "roundf(123.12f)" << " = " << roundf(123.12f) << std::endl;
	std::cout << std::setw(w) << "roundf(123.67f)" << " = " << roundf(123.67f) << std::endl;
	std::cout << std::setw(w) << "roundf(-123.12f)" << " = " << roundf(-123.12f) << std::endl;
	std::cout << std::setw(w) << "roundf(-123.67f)" << " = " << roundf(-123.67f) << std::endl;
	std::cout << std::endl;

//	system("leaks a.out");
	return 0;
}