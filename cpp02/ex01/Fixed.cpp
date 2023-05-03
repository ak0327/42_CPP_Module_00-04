#include "Fixed.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

// default constructor, initializes the fixed-point number value to 0
Fixed::Fixed() {
	cout << COLOR_GREEN << "Default constructor called, set:[" << fixedPointNumber_ << "]" << COLOR_RESET << endl;
	fixedPointNumber_ = 0;
}

// destructor
Fixed::~Fixed() {
	cout << COLOR_RED << "Destructor called" << COLOR_RESET << endl;
}

// copy constructor
Fixed::Fixed(const Fixed &obj) {
	cout << COLOR_MAGENTA << "Copy constructor called" << COLOR_RESET << endl;
	setRawBits(obj.getRawBits());
}

// obj assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj) {
	cout << COLOR_CYAN << "Copy assignment operator called" << COLOR_RESET << endl;
	if (this != &obj) {
		setRawBits(obj.getRawBits());
	}
	return *this;
}

// returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
	cout << COLOR_YELLOW << "getRawBits member function called, get:[" << fixedPointNumber_ << "]" << COLOR_RESET << endl;
	return (fixedPointNumber_);
}

// sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
	cout << COLOR_BLUE << "setRawBits member function called, set:[" << raw << "]" << COLOR_RESET << endl;
	fixedPointNumber_ = raw;
}

/* ex01 Additional func */
// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const int intNum) {
	cout << COLOR_GREEN << "Int constructor called" << COLOR_RESET << endl;
	fixedPointNumber_ = intNum * (1 << fractionalBits_);
}

/* ex01 Additional func */
// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const float floatNum) {
	cout << COLOR_YELLOW << "Float constructor called" << COLOR_RESET << endl;
	fixedPointNumber_ = static_cast<int>(floatNum * (1 << fractionalBits_));
}

/* ex01 Additional func */
// converts the fixed-point value to a floating-point value.
float Fixed::toFloat() const {
	return (static_cast<float>(fixedPointNumber_) / (1 << fractionalBits_));
}

/* ex01 Additional func */
// converts the fixed-point value to an integer value.
int Fixed::toInt() const {
	return (fixedPointNumber_ / (1 << fractionalBits_));
}

/* ex01 Additional func */
// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
ostream &operator<<(ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}