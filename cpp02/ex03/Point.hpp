#pragma once

#include "Fixed.hpp"

class Point {
public:
	// default constructor that initializes x and y to 0.
	Point();

	// constructor that takes as parameters two constant floating-point numbers.
	// initializes x and y with those parameters.
	Point(Fixed const x, Fixed const y);

	// destructor
	~Point();

	// copy constructor
	Point(const Point &point);

	// copy assignment operator overload.
	Point &operator=(Point const &point);

	Fixed get_x() const;

	Fixed get_y() const;

private:
	Fixed const x_;
	Fixed const y_;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);
