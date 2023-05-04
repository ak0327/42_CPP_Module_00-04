#include "Point.hpp"

Point::Point() : x_(Fixed(0)), y_(Fixed(0)) {}

Point::Point(const Fixed x, const Fixed y) : x_(x), y_(y) {}

Point::Point(const Point &point) : x_(point.x_), y_(point.y_) {}

Point &Point::operator=(Point const &point) {
	if (this != &point) {
		const_cast<Fixed &>(x_) = point.get_x();
		const_cast<Fixed &>(y_) = point.get_y();
	}
	return *this;
}

Point::~Point() {}

Fixed Point::get_x() const {
	return x_;
}

Fixed Point::get_y() const {
	return y_;
}
