#include <iostream>
#include "Point.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_RESET		"\x1b[0m"

static void test(Point a, Point b, Point c, Point point) {
	bool ans = bsp(a, b, c, point);
	std::string color = ans ? COLOR_GREEN : COLOR_RED;

	std::cout << " " << color << std::boolalpha << ans << COLOR_RESET << std::endl;
}

int main() {
	try {
		// inside
		std::cout << "===== inside =====" << std::endl;
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(1, 1));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0.1f, 0.1f));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(4, 4));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(4, 4));
		test(Point(0, 0), Point(-5, -10), Point(5, -10), Point(0, -5));
		test(Point(0, 0), Point(-5, -10), Point(5, -10), Point(0, -0.1f));

		std::cout << std::endl;

		// outside
		std::cout << "===== outside =====" << std::endl;
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(-1, -1));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(10, 10));
		std::cout << std::endl;

		// on vertex
		std::cout << "===== on vertex =====" << std::endl;
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 0));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 10));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 10.0f));
		std::cout << std::endl;

		// on edge
		std::cout << "===== on edge =====" << std::endl;
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 5));
		test(Point(0, 0), Point(10, 0), Point(0, 10), Point(0, 4.5f));
		test(Point(0, 0), Point(-5, -10), Point(5, -10), Point(0, -10));
		std::cout << std::endl;

		// not rectangle
		std::cout << "===== not rectangle =====" << std::endl;
		test(Point(0, 0), Point(0, 0), Point(10, 10), Point(1, 5));
		test(Point(0, 0), Point(0, 0), Point(10, 10), Point(0.1f, 0.1f));
		test(Point(0, 0), Point(0, 5), Point(0, 10), Point(0, 0.1f));

	}
	catch (std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
//	system("leaks a.out");
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
