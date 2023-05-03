#include <iostream>
#include "Fixed.hpp"
using namespace std;

int main() {
	cout.precision(10);
	try {
		{
			cout << "######## test in subject ########" << endl;
			cout << "\nFixed a:" << endl;
			Fixed a;

			cout << "Fixed b(Fixed(5.05f) * Fixed(2)):" << endl;
			Fixed const b(Fixed(5.05f) * Fixed(2));
			cout << endl;
			cout << " a   = " << a << endl;
			cout << " ++a = " << ++a << endl;
			cout << " a   = " << a << endl;
			cout << " a++ = " << a++ << endl;
			cout << " a   = " << a << endl;
			cout << " b   = " << b << endl;
			cout << endl;
			cout << " max(a,b) = " << Fixed::max(a, b) << endl;
			cout << endl;
		}
		{
			cout << "######## check ########" << endl;
			// 1/256 = 0.00390625
			// 0.00390625 * 26 = 0.101562
			//            * 25 = 0.0976562
			cout << " 0.1        = " << Fixed(0.1f) << endl;
			cout << " INT_MAX    = " << Fixed(INT_MAX) << endl;
			cout << " INT_MAX>>8 = " << Fixed(INT_MAX>>8) << endl; // max
			cout << endl;
		}
		{
			cout << "######## arithmetic operators [+] ########" << endl;
			cout << " 2 + 1      = " << Fixed(2) + Fixed(1) << endl;
			cout << " 0 + 1      = " << Fixed(0) + Fixed(1) << endl;
			cout << " -1.0 + 1   = " << Fixed(-1.0f) + Fixed(1) << endl;
			cout << " -1.0 + 1.0 = " << Fixed(-1.0f) + Fixed(1.0f) << endl;
			cout << " INT_MAX/512 + INT_MAX/512 = " << Fixed(INT_MAX/512) + Fixed(INT_MAX/512) << endl; // max
			cout << endl;
		}
		{
			cout << "######## arithmetic operators [-] ########" << endl;
			cout << " 2 - 1     = " << Fixed(2) - Fixed(1) << endl;
			cout << " 0 - 1     = " << Fixed(0) - Fixed(1) << endl;
			cout << " -1.0 - 1  = " << Fixed(-1.0f) - Fixed(1) << endl;
			cout << " INT_MAX/512 - INT_MAX/512 = " << Fixed(INT_MAX/512) - Fixed(INT_MAX/512) << endl; // max
			cout << endl;
		}
		{
			cout << "######## arithmetic operators [*] ########" << endl;
			cout << " 2 * 1       = " << Fixed(2) * Fixed(1) << endl;
			cout << " 2 * 2       = " << Fixed(2) * Fixed(2) << endl;
			cout << " 2 * -5      = " << Fixed(2) * Fixed(-5) << endl;
			cout << " 2.0 * -5    = " << Fixed(2.0f) * Fixed(-5) << endl;
			cout << " 100 * 0.1   = " << Fixed(100) * Fixed(0.1f) << endl;
			cout << " 0.1 * 0.1   = " << Fixed(0.1f) * Fixed(0.1f) << endl;
			cout << " 0.1 * -0.1  = " << Fixed(0.1f) * Fixed(-0.1f) << endl;
			cout << " 0.1 * 0.01  = " << Fixed(0.1f) * Fixed(0.01f) << endl;
			cout << " 100 * 0     = " << Fixed(100) * Fixed(0) << endl;
			cout << " 100.0 * 0.0 = " << Fixed(100.0f) * Fixed(0.0f) << endl;
			cout << " INT_MAX/512 * 2 = " << Fixed(INT_MAX/512) * Fixed(2) << endl; // max
			cout << endl;
		}
		{
			cout << "######## arithmetic operators [/] ########" << endl;
			cout << " 4 / 2       = " << Fixed(4) / Fixed(2) << endl;
			cout << " 5 / 2       = " << Fixed(5) / Fixed(2) << endl;
			cout << " 10 / 5      = " << Fixed(10) / Fixed(5) << endl;
			cout << " 1 / 3       = " << Fixed(1) / Fixed(3) << endl;
			cout << " 100 / 100   = " << Fixed(100) / Fixed(100) << endl;
			cout << " INT_MAX / INT_MAX = " << Fixed(INT_MAX) / Fixed(INT_MAX) << endl;
			cout << endl;
		}
		{
			cout << "######## comparison operators ########" << endl;
			cout << " 1 == 1 : " << (Fixed(1) == Fixed(1)) << endl;
			cout << " 1 != 1 : " << (Fixed(1) != Fixed(1)) << endl;
			cout << " 1 > 1  : " << (Fixed(1) > Fixed(1)) << endl;
			cout << " 1 < 1  : " << (Fixed(1) < Fixed(1)) << endl;
			cout << " 1 >= 1 : " << (Fixed(1) >= Fixed(1)) << endl;
			cout << " 1 <= 1 : " << (Fixed(1) <= Fixed(1)) << endl;
			cout << endl;
			cout << " 1.0 == 1.0 : " << (Fixed(1.0f) == Fixed(1.0f)) << endl;
			cout << " 1.0 != 1.0 : " << (Fixed(1.0f) != Fixed(1.0f)) << endl;
			cout << " 1.0 > 1.0  : " << (Fixed(1.0f) > Fixed(1.0f)) << endl;
			cout << " 1.0 < 1.0  : " << (Fixed(1.0f) < Fixed(1.0f)) << endl;
			cout << " 1.0 >= 1.0 : " << (Fixed(1.0f) >= Fixed(1.0f)) << endl;
			cout << " 1.0 <= 1.0 : " << (Fixed(1.0f) <= Fixed(1.0f)) << endl;
			cout << endl;
			cout << " 1 == 1.0 : " << (Fixed(1) == Fixed(1.0f)) << endl;
			cout << " 1 != 1.0 : " << (Fixed(1) != Fixed(1.0f)) << endl;
			cout << " 1 > 1.0  : " << (Fixed(1) > Fixed(1.0f)) << endl;
			cout << " 1 < 1.0  : " << (Fixed(1) < Fixed(1.0f)) << endl;
			cout << " 1 >= 1.0 : " << (Fixed(1) >= Fixed(1.0f)) << endl;
			cout << " 1 <= 1.0 : " << (Fixed(1) <= Fixed(1.0f)) << endl;
			cout << endl;

			cout << "(cf)" << endl;
			cout << " 1 == 1     :" << (1 == 1) << endl;
			cout << " 1.0 == 1.0 :" << (1.0 == 1.0) << endl;
			cout << " 1 == 1.0   :" << (1 == 1.0) << endl;
			cout << endl;
		}
		{
			cout << "######## exception ########" << endl;
			cout << " inf  : " << INFINITY << endl;
			cout << " -inf : " << -INFINITY << endl;
			cout << " nan  : " << NAN << endl;

//			cout << " 1 / 0 = " << Fixed(1) / Fixed(0) << endl;
//			cout << " Fixed(\"inf\") = " << Fixed(INFINITY) << endl;
//			cout << " Fixed(\"-inf\") = " << Fixed(-INFINITY) << endl;
//			cout << " Fixed(\"nan\") = " << Fixed(NAN) << endl;
			cout << endl;
		}
	}
	catch (exception &e){
		cerr << e.what() << endl;
	}
//	system("leaks a.out");
	return 0;
}