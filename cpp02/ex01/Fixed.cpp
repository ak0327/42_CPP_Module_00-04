#include "Fixed.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

// default constructor, initializes the fixed-point number value to 0
Fixed::Fixed() : fixedPointNumber_(0) {}

// destructor
Fixed::~Fixed() {}

// copy constructor
Fixed::Fixed(Fixed const &obj) {
//	*this = obj; // self-assignmentはNG
//	this->setRawBits(obj.getRawBits());
	this->fixedPointNumber_ = obj.getRawBits();
}


// obj assignment operator overload
Fixed &Fixed::operator=(Fixed const &obj) {
	if (this != &obj) {
//		*this = obj;
		this->fixedPointNumber_ = obj.getRawBits();
//		this->setRawBits(obj.getRawBits());
	}
	return *this;
}

// returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
	return (fixedPointNumber_);
}

// sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
	fixedPointNumber_ = raw;
}

/* ex01 Additional func */
// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const int intNum) {
	fixedPointNumber_ = intNum << fractionalBits_;
}

/* ex01 Additional func */
// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const float floatNum) {
	fixedPointNumber_ = (int)(floatNum * (1 << fractionalBits_));
}

/* ex01 Additional func */
// converts the fixed-point value to a floating-point value.
float Fixed::toFloat() const {
	return ((float)(fixedPointNumber_) / (1 << fractionalBits_));
}

/* ex01 Additional func */
// converts the fixed-point value to an integer value.
int Fixed::toInt() const {
	return (fixedPointNumber_ >> fractionalBits_);
}

/* ex01 Additional func */
// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}