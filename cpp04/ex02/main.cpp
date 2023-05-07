#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	{
		try {
			std::cout << "======== test ========" << std::endl;
			Animal animal;

			animal->makeSound();

			delete animal;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}

	system("leaks a.out");
	return 0;
}
