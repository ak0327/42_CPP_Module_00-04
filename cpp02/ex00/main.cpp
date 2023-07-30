#include <iostream>
#include "Fixed.hpp"

int main() {

	std::cout << "\nFixed a:" << std::endl;
	Fixed a;

	std::cout << "\nFixed b(a):" << std::endl;
	Fixed b(a);

	std::cout << "\nFixed c:" << std::endl;
	Fixed c;

	std::cout << "\nc = b:" << std::endl;
	c = b;


	std::cout << "\na.getRawBits():" << std::endl;
	std::cout << a.getRawBits() << std::endl;

	std::cout << "\nb.getRawBits():" << std::endl;
	std::cout << b.getRawBits() << std::endl;

	std::cout << "\nc.getRawBits():" << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl;

//	system("leaks -q a.out");
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
