#include "Fixed.hpp"

// default constructor, initializes the fixed-point number value to 0
Fixed::Fixed() : fixedPointNumber_(0) {}

// destructor
Fixed::~Fixed() {}

// copy constructor
Fixed::Fixed(Fixed const &obj) {
	*this = obj;
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
	setRawBits(intNum << fractionalBits_);
}

// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const float floatNum) {
	if (isnan(floatNum)) {
		throw std::invalid_argument("invalid argument : 'nan'");
	}
	else if (isinf(floatNum)) {
		throw std::invalid_argument("invalid argument : 'inf'");
	}
	setRawBits(static_cast<int>(roundf((floatNum * (1 << fractionalBits_)))));
}




// obj assignment operator overload
Fixed &Fixed::operator=(Fixed const &obj) {
	if (this != &obj) {
		setRawBits(obj.getRawBits());
	}
	return *this;
}

/* ex02 Additional func */
// comparison operators
bool Fixed::operator>(Fixed const &obj) {
	return getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(Fixed const &obj) {
	return getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(Fixed const &obj) {
	return !(*this < obj);
}

bool Fixed::operator<=(Fixed const &obj) {
	return !(*this > obj);
}

bool Fixed::operator==(Fixed const &obj) {
	return getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(Fixed const &obj) {
	return !(*this == obj);
}


/* ex02 Additional func */
// arithmetic operators
Fixed Fixed::operator+(Fixed const &obj) {
	setRawBits(getRawBits() + obj.getRawBits());
	return *this;
}

Fixed Fixed::operator-(Fixed const &obj) {
	setRawBits(getRawBits() - obj.getRawBits());
	return *this;
}

Fixed Fixed::operator*(Fixed const &obj) {
	long tmp = static_cast<long>(getRawBits()) * static_cast<long>(obj.getRawBits());
	tmp /= (1 << fractionalBits_);
	setRawBits(static_cast<int>(tmp));
	return *this;
}

Fixed Fixed::operator/(Fixed const &obj) {
	if (obj.getRawBits() == 0) {
		throw std::runtime_error("Division by zero");
	}
	long tmp = static_cast<long>(getRawBits()) << fractionalBits_;
	tmp /= static_cast<long>(obj.getRawBits());
	setRawBits(static_cast<int>(tmp));
	return *this;
}

/* ex02 Additional func */
// pre-increment, pre-decrement operators
Fixed &Fixed::operator++() {
	setRawBits(getRawBits() + 1);
	return *this;
}


Fixed &Fixed::operator--() {
	setRawBits(getRawBits() - 1);
	return *this;
}

// post-increment, post-decrement operators
Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	setRawBits(getRawBits() + 1);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	setRawBits(getRawBits() - 1);
	return tmp;
}

/* ex02 Additional func */
// public overloaded member functions
// A static member function min, returns a reference to the smallest one.
// 1) takes as parameters two references on fixed-point numbers
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() <= b.getRawBits()) ? a : b;
}

// 2) takes as parameters two references to constant fixed-point numbers
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() <= b.getRawBits()) ? a : b;
}


// A static member function max, returns a reference to the greatest one.
// 1) takes as parameters two references on fixed-point numbers
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() >= b.getRawBits()) ? a : b;
}

// 2) takes as parameters two references to constant fixed-point numbers
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() >= b.getRawBits()) ? a : b;
}


// converts the fixed-point value to a floating-point value.
float Fixed::toFloat() const {
	return static_cast<float>(fixedPointNumber_) / (1 << fractionalBits_);
}

// converts the fixed-point value to an integer value.
int Fixed::toInt() const {
	return roundf(static_cast<float>(fixedPointNumber_) / (1 << fractionalBits_));
}

// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}
