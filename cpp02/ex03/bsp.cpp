#include "Point.hpp"
#include "Fixed.hpp"

typedef Point Vec;

static Point sub(Point const a, Point const b) {
	return Point(a.get_x() - b.get_x(), a.get_y() - b.get_y());
}

static Fixed cross(Point const a, Point const b) {
	return Fixed(a.get_x() * b.get_y() - a.get_y() * b.get_x());
}

// a, b, c: The vertices of our beloved triangle
// point: The point to check
// Returns: True if the point is inside the triangle
//          False otherwise.
//          if the point is a vertex or on edge, it will return False

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Vec AB = sub(b, a);
	Vec BC = sub(c, b);
	Vec CA = sub(a, c);
	Vec AP = sub(point, a);
	Vec BP = sub(point, b);
	Vec CP = sub(point, c);

	Fixed ABxAP = cross(AB, AP);
	Fixed BCxBP = cross(BC, BP);
	Fixed CAxCP = cross(CA, CP);

//	cout << "ABxAP=" << ABxAP << endl;
//	cout << "BCxBP=" << BCxBP << endl;
//	cout << "CAxCP=" << CAxCP << endl;
	Fixed zero = Fixed(0);
	return ((ABxAP > zero && BCxBP > zero && CAxCP > zero)
	|| (ABxAP < zero && BCxBP < zero && CAxCP < zero));
}
