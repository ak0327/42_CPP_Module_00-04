#include "Fixed.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

//const int Fixed::fractionalBits_ = 8;

// default constructor, initializes the fixed-point number value to 0
Fixed::Fixed() : fixedPointNumber_(0) {}

// destructor
Fixed::~Fixed() {}

// copy constructor
Fixed::Fixed(Fixed const &obj) {
//	*this = obj; // self-assignmentはNG
//	this->setRawBits(obj.getRawBits());
	this->fixedPointNumber_ = obj.fixedPointNumber_;
}


// obj assignment operator overload
Fixed &Fixed::operator=(Fixed const &obj) {
	if (this != &obj) {
//		*this = obj;
		this->fixedPointNumber_ = obj.fixedPointNumber_;
//		this->setRawBits(obj.fixedPointNumber_);
	}
	return *this;
}

/* ex02 Additional func */
// comparison operators
bool Fixed::operator>(Fixed const &obj) {
	return this->fixedPointNumber_ > obj.fixedPointNumber_;
}

bool Fixed::operator<(Fixed const &obj) {
	return this->fixedPointNumber_ < obj.fixedPointNumber_;
}

bool Fixed::operator>=(Fixed const &obj) {
	return !(*this < obj);
}

bool Fixed::operator<=(Fixed const &obj) {
	return !(*this > obj);
}

bool Fixed::operator==(Fixed const &obj) {
	return this->fixedPointNumber_ == obj.fixedPointNumber_;
}

bool Fixed::operator!=(Fixed const &obj) {
	return !(*this == obj);
}


/* ex02 Additional func */
// arithmetic operators
Fixed Fixed::operator+(Fixed const &obj) {
	fixedPointNumber_ += obj.fixedPointNumber_;
	return *this;
}

Fixed Fixed::operator-(Fixed const &obj) {
	fixedPointNumber_ -= obj.fixedPointNumber_;
	return *this;
}

Fixed Fixed::operator*(Fixed const &obj) {
	fixedPointNumber_ =
			static_cast<int>((
					static_cast<long long>(fixedPointNumber_) * obj.fixedPointNumber_)
					>> fractionalBits_);
	return *this;
}

Fixed Fixed::operator/(Fixed const &obj) {
	if (obj.fixedPointNumber_ == 0) {
		throw runtime_error("Division by zero");
	}
	long long div = static_cast<long long>(fixedPointNumber_) << fractionalBits_;
	fixedPointNumber_ = static_cast<int>(div / obj.fixedPointNumber_);
	return *this;
}

/* ex02 Additional func */
// pre-increment, pre-decrement operators
Fixed &Fixed::operator++() {
	fixedPointNumber_++;
	return *this;
}


Fixed &Fixed::operator--() {
	fixedPointNumber_--;
	return *this;
}

// post-increment, post-decrement operators
Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	fixedPointNumber_++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	fixedPointNumber_--;
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
	fixedPointNumber_ = intNum << fractionalBits_;
}

// It converts it to the corresponding fixed-point value
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const float floatNum) {
	if (isnan(floatNum)) {
		throw invalid_argument("invalid argument : 'nan'");
	}
	else if (isinf(floatNum)) {
		throw invalid_argument("invalid argument : 'inf'");
	}
	fixedPointNumber_ = static_cast<int>(roundf((floatNum * (1 << fractionalBits_))));
}

// converts the fixed-point value to a floating-point value.
float Fixed::toFloat() const {
	return (static_cast<float>(fixedPointNumber_) / (1 << fractionalBits_));
}

// converts the fixed-point value to an integer value.
int Fixed::toInt() const {
	return (fixedPointNumber_ >> fractionalBits_);
}

// inserts a floating-point representation of the fixed-point number
// into the output stream object passed as parameter.
ostream &operator<<(ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return out;
}