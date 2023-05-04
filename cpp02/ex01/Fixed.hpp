#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Fixed {
public:
	// default constructor, initializes the fixed-point number value to 0
	Fixed();
	// destructor
	~Fixed();
	// copy constructor
	Fixed(Fixed const &obj);


	/* ex01 Additional func */
	// A constructor that takes a constant integer as a parameter.
	Fixed(const int intNum);

	/* ex01 Additional func */
	// constructor that takes a constant floating-point number as a parameter.
	Fixed(const float floatNum);

	// copy assignment operator overload
	Fixed &operator=(Fixed const &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	/* ex01 Additional func */
	// converts the fixed-point value to a floating-point value.
	float	toFloat(void) const;

	/* ex01 Additional func */
	// converts the fixed-point value to an integer value.
	int 	toInt(void) const;

private:
	int fixedPointNumber_;
	static const int fractionalBits_ = 8;

};

/* ex01 Additional func */
// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
ostream &operator<<(ostream &out, const Fixed &obj);