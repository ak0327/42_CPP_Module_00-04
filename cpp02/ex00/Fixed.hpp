#pragma once
#include <iostream>
#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"
using namespace std;

class Fixed {
public:
	// default constructor, initializes the fixed-point number value to 0
	Fixed();

	// destructor
	~Fixed();

	// copy constructor
	Fixed(const Fixed &copyObj);

	// copy assignment operator overload
	Fixed &operator=(const Fixed &copyObj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int fixedPointNumber_;
	static const int fractionalBits_;

};