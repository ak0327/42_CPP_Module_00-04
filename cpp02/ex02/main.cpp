#include <iostream>
#include "Fixed.hpp"

int main() {
	std::cout.precision(10);
	try {
		{
			std::cout << "######## test in subject ########" << std::endl;
			std::cout << "\nFixed a:" << std::endl;
			Fixed a;

			std::cout << "Fixed b(Fixed(5.05f) * Fixed(2)):" << std::endl;
			Fixed const b(Fixed(5.05f) * Fixed(2));
			std::cout << std::endl;
			std::cout << " a   = " << a << std::endl;
			std::cout << " ++a = " << ++a << std::endl;
			std::cout << " a   = " << a << std::endl;
			std::cout << " a++ = " << a++ << std::endl;
			std::cout << " a   = " << a << std::endl;
			std::cout << " b   = " << b << std::endl;
			std::cout << std::endl;
			std::cout << " max(a,b) = " << Fixed::max(a, b) << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "######## check ########" << std::endl;
			// 1/256 = 0.00390625
			// 0.00390625 * 26 = 0.101562
			//            * 25 = 0.0976562
			std::cout << " 0.1        = " << Fixed(0.1f) << std::endl;
			std::cout << " INT_MAX    = " << Fixed(INT_MAX) << std::endl;
			std::cout << " INT_MAX>>8 = " << Fixed(INT_MAX>>8) << std::endl; // max
			std::cout << std::endl;
		}
		{
			std::cout << "######## arithmetic operators [+] ########" << std::endl;
			std::cout << " 2 + 1      = " << Fixed(2) + Fixed(1) << std::endl;
			std::cout << " 0 + 1      = " << Fixed(0) + Fixed(1) << std::endl;
			std::cout << " -1.0 + 1   = " << Fixed(-1.0f) + Fixed(1) << std::endl;
			std::cout << " -1.0 + 1.0 = " << Fixed(-1.0f) + Fixed(1.0f) << std::endl;
			std::cout << " INT_MAX/512 + INT_MAX/512 = " << Fixed(INT_MAX/512) + Fixed(INT_MAX/512) << std::endl; // max
			std::cout << std::endl;
		}
		{
			std::cout << "######## arithmetic operators [-] ########" << std::endl;
			std::cout << " 2 - 1     = " << Fixed(2) - Fixed(1) << std::endl;
			std::cout << " 0 - 1     = " << Fixed(0) - Fixed(1) << std::endl;
			std::cout << " -1.0 - 1  = " << Fixed(-1.0f) - Fixed(1) << std::endl;
			std::cout << " INT_MAX/512 - INT_MAX/512 = " << Fixed(INT_MAX/512) - Fixed(INT_MAX/512) << std::endl; // max
			std::cout << std::endl;
		}
		{
			std::cout << "######## arithmetic operators [*] ########" << std::endl;
			std::cout << " 2 * 1       = " << Fixed(2) * Fixed(1) << std::endl;
			std::cout << " 2 * 2       = " << Fixed(2) * Fixed(2) << std::endl;
			std::cout << " 2 * -5      = " << Fixed(2) * Fixed(-5) << std::endl;
			std::cout << " 2.0 * -5    = " << Fixed(2.0f) * Fixed(-5) << std::endl;
			std::cout << " 100 * 0.1   = " << Fixed(100) * Fixed(0.1f) << std::endl;
			std::cout << " 0.1 * 0.1   = " << Fixed(0.1f) * Fixed(0.1f) << std::endl;
			std::cout << " 0.1 * -0.1  = " << Fixed(0.1f) * Fixed(-0.1f) << std::endl;
			std::cout << " 0.1 * 0.01  = " << Fixed(0.1f) * Fixed(0.01f) << std::endl;
			std::cout << " 100 * 0     = " << Fixed(100) * Fixed(0) << std::endl;
			std::cout << " 100.0 * 0.0 = " << Fixed(100.0f) * Fixed(0.0f) << std::endl;
			std::cout << " INT_MAX/512 * 2 = " << Fixed(INT_MAX/512) * Fixed(2) << std::endl; // max
			std::cout << std::endl;
		}
		{
			std::cout << "######## arithmetic operators [/] ########" << std::endl;
			std::cout << " 4 / 2       = " << Fixed(4) / Fixed(2) << std::endl;
			std::cout << " 5 / 2       = " << Fixed(5) / Fixed(2) << std::endl;
			std::cout << " 10 / 5      = " << Fixed(10) / Fixed(5) << std::endl;
			std::cout << " 1 / 3       = " << Fixed(1) / Fixed(3) << std::endl;
			std::cout << " 100 / 100   = " << Fixed(100) / Fixed(100) << std::endl;
			std::cout << " INT_MAX / INT_MAX = " << Fixed(INT_MAX) / Fixed(INT_MAX) << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "######## comparison operators ########" << std::endl;
			std::cout << " 1 == 1 : " << std::boolalpha << (Fixed(1) == Fixed(1)) << std::endl;
			std::cout << " 1 != 1 : " << std::boolalpha << (Fixed(1) != Fixed(1)) << std::endl;
			std::cout << " 1 > 1  : " << std::boolalpha << (Fixed(1) > Fixed(1)) << std::endl;
			std::cout << " 1 < 1  : " << std::boolalpha << (Fixed(1) < Fixed(1)) << std::endl;
			std::cout << " 1 >= 1 : " << std::boolalpha << (Fixed(1) >= Fixed(1)) << std::endl;
			std::cout << " 1 <= 1 : " << std::boolalpha << (Fixed(1) <= Fixed(1)) << std::endl;
			std::cout << std::endl;
			std::cout << " 1.0 == 1.0 : " << std::boolalpha << (Fixed(1.0f) == Fixed(1.0f)) << std::endl;
			std::cout << " 1.0 != 1.0 : " << std::boolalpha << (Fixed(1.0f) != Fixed(1.0f)) << std::endl;
			std::cout << " 1.0 > 1.0  : " << std::boolalpha << (Fixed(1.0f) > Fixed(1.0f)) << std::endl;
			std::cout << " 1.0 < 1.0  : " << std::boolalpha << (Fixed(1.0f) < Fixed(1.0f)) << std::endl;
			std::cout << " 1.0 >= 1.0 : " << std::boolalpha << (Fixed(1.0f) >= Fixed(1.0f)) << std::endl;
			std::cout << " 1.0 <= 1.0 : " << std::boolalpha << (Fixed(1.0f) <= Fixed(1.0f)) << std::endl;
			std::cout << std::endl;
			std::cout << " 1 == 1.0 : " << std::boolalpha << (Fixed(1) == Fixed(1.0f)) << std::endl;
			std::cout << " 1 != 1.0 : " << std::boolalpha << (Fixed(1) != Fixed(1.0f)) << std::endl;
			std::cout << " 1 > 1.0  : " << std::boolalpha << (Fixed(1) > Fixed(1.0f)) << std::endl;
			std::cout << " 1 < 1.0  : " << std::boolalpha << (Fixed(1) < Fixed(1.0f)) << std::endl;
			std::cout << " 1 >= 1.0 : " << std::boolalpha << (Fixed(1) >= Fixed(1.0f)) << std::endl;
			std::cout << " 1 <= 1.0 : " << std::boolalpha << (Fixed(1) <= Fixed(1.0f)) << std::endl;
			std::cout << std::endl;

			std::cout << "(cf)" << std::endl;
			std::cout << " 1 == 1     :" << std::boolalpha << (1 == 1) << std::endl;
			std::cout << " 1.0 == 1.0 :" << std::boolalpha << (1.0 == 1.0) << std::endl;
			std::cout << " 1 == 1.0   :" << std::boolalpha << (1 == 1.0) << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "######## exception ########" << std::endl;
			std::cout << "(cf)" << std::endl;
			std::cout << " inf  : " << INFINITY << std::endl;
			std::cout << " -inf : " << -INFINITY << std::endl;
			std::cout << " nan  : " << NAN << std::endl;
			std::cout << std::endl;
		}
		{
			try {
				std::cout << " 1 / 0 = " << Fixed(1) / Fixed(0) << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		{
			try {
				std::cout << " Fixed(\"inf\")  = " << Fixed(INFINITY) << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		{
			try {
				std::cout << " Fixed(\"-inf\") = " << Fixed(-INFINITY) << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		{
			try {
				std::cout << " Fixed(\"nan\")  = " << Fixed(NAN) << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
		}

	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
//	system("leaks a.out");
	return 0;
}