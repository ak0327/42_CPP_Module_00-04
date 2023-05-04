#include "Fixed.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"


// default constructor, initializes the fixed-point number value to 0
Fixed::Fixed() : fixedPointNumber_(0) {
	cout << COLOR_GREEN << "Default constructor called, set:[" << fixedPointNumber_ << "]" << COLOR_RESET << endl;
}

// destructor
Fixed::~Fixed() {
	cout << COLOR_RED << "Destructor called" << COLOR_RESET << endl;
}

// copy constructor
Fixed::Fixed(Fixed const &obj) {
	cout << COLOR_MAGENTA << "Copy constructor called" << COLOR_RESET << endl;
	this->fixedPointNumber_ = obj.getRawBits();
}

// obj assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj) {
	cout << COLOR_CYAN << "Copy assignment operator called" << COLOR_RESET << endl;
	if (this != &obj) {
		this->fixedPointNumber_ = obj.getRawBits();
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