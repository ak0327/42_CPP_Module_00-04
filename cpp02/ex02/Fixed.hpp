#pragma once
#include <iostream>
#include <cmath>

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

class Fixed {
public:
	// default constructor, initializes the fixed-point number value to 0
	Fixed();
	// destructor
	~Fixed();
	// copy constructor
	Fixed(Fixed const &obj);
	// A constructor that takes a constant integer as a parameter.
	Fixed(const int intNum);
	// constructor that takes a constant floating-point number as a parameter.
	Fixed(const float floatNum);

	// copy assignment operator overload

	Fixed &operator=(Fixed const &obj);

	/* ex02 Additional func */
	// comparison operators
	bool operator>(Fixed const &obj);
	bool operator<(Fixed const &obj);
	bool operator>=(Fixed const &obj);
	bool operator<=(Fixed const &obj);
	bool operator==(Fixed const &obj);
	bool operator!=(Fixed const &obj);

	/* ex02 Additional func */
	// arithmetic operators
	Fixed operator+(Fixed const &obj);
	Fixed operator-(Fixed const &obj);
	Fixed operator*(Fixed const &obj);
	Fixed operator/(Fixed const &obj);

	/* ex02 Additional func */
	// pre-increment, pre-decrement operators
	Fixed &operator++();
	Fixed &operator--();
	// post-increment, post-decrement operators
	Fixed operator++(int);
	Fixed operator--(int);

	/* ex02 Additional func */
	// public overloaded member functions
	// A static member function min, returns a reference to the smallest one.
	// 1) takes as parameters two references on fixed-point numbers
	static Fixed &min(Fixed &a, Fixed &b);

	// 2) takes as parameters two references to constant fixed-point numbers
	static const Fixed &min(const Fixed &a, const Fixed &b);

	// A static member function max, returns a reference to the greatest one.
	// 1) takes as parameters two references on fixed-point numbers
	static Fixed &max(Fixed &a, Fixed &b);

	// 2) takes as parameters two references to constant fixed-point numbers
	static const Fixed &max(const Fixed &a, const Fixed &b);


	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	// converts the fixed-point value to a floating-point value.
	float	toFloat(void) const;
	// converts the fixed-point value to an integer value.
	int 	toInt(void) const;

private:
	int fixedPointNumber_;
	static const int fractionalBits_ = 8;

};

// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &out, const Fixed &obj);
