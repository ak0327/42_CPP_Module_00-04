#include <iostream>
#include "Point.hpp"

using namespace std;

static void test(Point a, Point b, Point c, Point point) {
	bool ans = bsp(a, b, c, point);
	if (ans)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main() {
	try {
		// inside
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(1, 1));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0.1, 0.1));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(4, 4));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(4, 4));
		test(Point(0, 0), Point(-5, -10), Point(5, -10), Point(0, -5));
		test(Point(0, 0), Point(-5, -10), Point(5, -10), Point(0, -0.1));

		cout << endl;

		// outside
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(-1, -1));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(10, 10));

		// on vertex
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 0));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 10));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 10.0));

		// on edge
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 5));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 4.5));
		test(Point(0, 0), Point(-5, -10), Point(5, -10), Point(0, -10));

		// not rectangle
		test(Point(0, 0), Point(0, 0), Point(10, 10), Point(1, 5));
		test(Point(0, 0), Point(0, 0), Point(10, 10), Point(0.1, 0.1));
		test(Point(0, 0), Point(0, 5), Point(0, 10), Point(0, 0.1));

	}
	catch (exception &e){
		cerr << e.what() << endl;
	}
//	system("leaks a.out");
	return 0;
}