#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	{
		try {
			std::cout << "======== test ========" << std::endl;
			Animal animal;

			animal.makeSound();

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- ex01 subject --------------------" << std::endl;
		try {
			std::cout << "=== Animal *dog = new Dog() ===" << std::endl;
			const Animal *dog = new Dog();
			std::cout << std::endl;
			std::cout << "=== dog->makeSound() ===" << std::endl;
			dog->makeSound();
			std::cout << std::endl;

			std::cout << "=== Animal *cat = new Cat() ===" << std::endl;
			const Animal *cat = new Cat();
			std::cout << "=== cat->makeSound() ===" << std::endl;
			std::cout << std::endl;
			cat->makeSound();
			std::cout << std::endl;

			std::cout << "=== delete dog ===" << std::endl;
			delete dog;

			std::cout << std::endl;
			std::cout << "=== delete cat ===" << std::endl;
			delete cat;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
