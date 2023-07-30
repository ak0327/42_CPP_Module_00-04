#pragma once
#include <iostream>

class Fixed {
public:
	// default constructor, initializes the fixed-point number value to 0
	Fixed();

	// destructor
	~Fixed();

	// copy constructor
	Fixed(Fixed const &obj);

	// copy assignment operator overload
	Fixed &operator=(const Fixed &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int fixedPointNumber_;
	static const int fractionalBits_ = 8;

};
