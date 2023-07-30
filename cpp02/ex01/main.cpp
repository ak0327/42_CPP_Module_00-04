#include <iostream>
#include <iomanip>

#include "Fixed.hpp"

// 1234.5678 ->  12345678
//               1234
//                  .5678

int main() {
	std::cout.precision(10);
	std::cout.setf(std::ios::left);
	int width;
	{
		std::cout << "---------- subject ----------" << std::endl;

		Fixed a = Fixed(1234.4321f);
		Fixed const b(10);
		Fixed const c(42.42f);
		Fixed const d(b);

		std::cout << "Fixed a = Fixed(1234.4321f) = " << a << std::endl;
		// 1234.4321 * (1<<8) = 316014.6176 -> 316014
		// toFloat = 316014 / (1<<8) = 1234.4296875

		std::cout << "Fixed const b(10)           = " << b << std::endl;

		std::cout << "Fixed const c(42.42f)       = " << c << std::endl;
		// 42.42 * (1<<8) = 10859.52 -> 10859
		// toFloat = 10859 / (1<<8) = 42.41796875

		std::cout << "Fixed const d(b)            = " << d << std::endl;

		std::cout << std::endl;

		width = 10;
		std::cout << std::setw(width) <<  "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << std::setw(width) << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << std::setw(width) << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << std::setw(width) << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << std::endl;

		std::cout << std::setw(width) << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "d is " << d.toFloat() << " as float" << std::endl;
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "---------- test 1 ----------" << std::endl;
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

		width = 10;
		std::cout << std::setw(width) << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << std::setw(width) << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << std::setw(width) << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << std::setw(width) << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << std::endl;

		std::cout << std::setw(width) << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "d is " << d.toFloat() << " as float" << std::endl;
		std::cout << std::setw(width) << "\n" << std::endl;
	}
	{
		std::cout << "---------- test 2 ----------" << std::endl;
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

		width = 20;
		std::cout << std::setw(width) << "a1(0)" << " = " << a1 << std::endl;
		std::cout << std::setw(width) << "a2(100)" << " = " << a2 << std::endl;
		std::cout << std::setw(width) << "a3(100.000f)" << " = " << a3 << std::endl;
		std::cout << std::setw(width) << "a4(1234.56789f)" << " = " << a4 << std::endl;
		std::cout << std::setw(width) << "a5(INT_MAX/256)" << " = " << a5 << std::endl;
		std::cout << std::setw(width) << "a6(INT_MAX)    " << " = " << a6 << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width) << "b1(-1)" << " = " << b1 << std::endl;
		std::cout << std::setw(width) << "b2(-1.001f)" << " = " << b2 << std::endl;
		std::cout << std::setw(width) << "b3(-100)" << " = " << b3 << std::endl;
		std::cout << std::setw(width) << "b4(-100.00f)" << " = " << b4 << std::endl;
		std::cout << std::setw(width) << "b5(INT_MIN/256)" << " = " << b5 << std::endl;
		std::cout << std::setw(width) << "b6(INT_MIN)" << " = " << b6 << std::endl;
		std::cout << std::setw(width) << "b7(-1234.56789f)" << " = " << b7 << std::endl;
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "---------- test 3 : rounded precision ----------" << std::endl;
		width = 20;
		std::cout << std::setw(width) << "toInt(1234.4321f)" << " = " << Fixed(1234.4321f).toInt() << std::endl;
		std::cout << std::setw(width) << "roundf(1234.4321f)" << " = " << roundf(1234.4321f) << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width) << "toInt(-1234.4321f)" << " = " << Fixed(-1234.4321f).toInt() << std::endl;
		std::cout << std::setw(width) << "roundf(-1234.4321f)" << " = " << roundf(-1234.4321f) << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width) << "toInt(123.12f)" << " = " << Fixed(123.12f).toInt() << std::endl;
		std::cout << std::setw(width) << "roundf(123.12f)" << " = " << roundf(123.12f) << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width) << "toInt(123.67f)" << " = " << Fixed(123.67f).toInt() << std::endl;
		std::cout << std::setw(width) << "roundf(123.67f)" << " = " << roundf(123.67f) << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width) << "toInt(-123.12f)" << " = " << Fixed(-123.12f).toInt() << std::endl;
		std::cout << std::setw(width) << "roundf(-123.12f)" << " = " << roundf(-123.12f) << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width) << "toInt(-123.67f)" << " = " << Fixed(-123.67f).toInt() << std::endl;
		std::cout << std::setw(width) << "roundf(-123.67f)" << " = " << roundf(-123.67f) << std::endl;
		std::cout << std::endl;
	}

	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
