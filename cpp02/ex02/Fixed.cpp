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
	fixedPointNumber_ = 0;
}

// destructor
Fixed::~Fixed() {
}

// copy constructor
Fixed::Fixed(const Fixed &obj) {
	setRawBits(obj.getRawBits());
}


// obj assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj) {
	if (this != &obj) {
		setRawBits(obj.getRawBits());
	}
	return *this;
}

/* ex02 Additional func */
// comparison operators
bool Fixed::operator>(const Fixed &obj) {
	return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) {
	return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) {
	return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) {
	return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) {
	return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) {
	return this->getRawBits() != obj.getRawBits();
}


/* ex02 Additional func */
// arithmetic operators
Fixed Fixed::operator+(const Fixed &obj) {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) {
	return Fixed(this->toFloat() / obj.toFloat());
}

/* ex02 Additional func */
// pre-increment, pre-decrement operators
Fixed Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

// post-increment, post-decrement operators
Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

/* ex02 Additional func */
// public overloaded member functions
// A static member function min, returns a reference to the smallest one.
// 1) takes as parameters two references on fixed-point numbers
Fixed Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

// 2) takes as parameters two references to constant fixed-point numbers
Fixed Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}


// A static member function max, returns a reference to the greatest one.
// 1) takes as parameters two references on fixed-point numbers
Fixed Fixed::max(Fixed &a, Fixed &b) {
	return !min(a, b);
}

// 2) takes as parameters two references to constant fixed-point numbers
Fixed Fixed::max(const Fixed &a, const Fixed &b) {
	return !min(a, b);
}



// returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
	return (fixedPointNumber_);
}

// sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
	fixedPointNumber_ = raw;
}

// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const int intNum) {
	fixedPointNumber_ = intNum * (1 << fractionalBits_);
}

// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const float floatNum) {
	fixedPointNumber_ = static_cast<int>(floatNum * (1 << fractionalBits_));
}

// converts the fixed-point value to a floating-point value.
float Fixed::toFloat() const {
	return (static_cast<float>(fixedPointNumber_) / (1 << fractionalBits_));
}

// converts the fixed-point value to an integer value.
int Fixed::toInt() const {
	return (fixedPointNumber_ / (1 << fractionalBits_));
}

// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
ostream &operator<<(ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}