#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	{
		std::cout << "  ========== subject ==========" << std::endl;

		std::cout << "Animal *meta = Animal(): " << std::endl;
		const Animal *meta = new Animal();

		std::cout << "Animal *i = Cat() : " << std::endl;
		const Animal *i = new Cat();

		std::cout << "Animal *j = Dog() : " << std::endl;
		const Animal *j = new Dog();

		std::cout << std::endl;

		std::cout << "meta->getType :" << meta->getType() << std::endl;
		std::cout << "i->getType    :" << i->getType() << std::endl;
		std::cout << "j->getType    :" << j->getType() << std::endl;

		std::cout << std::endl;

		meta->makeSound();
		i->makeSound();		// cat sound
		j->makeSound();		// dog sound

		std::cout << std::endl;
		delete meta;
		delete i;
		delete j;
		std::cout << std::endl;
	}
	{
		std::cout << "\n  ========== wrong cat ==========" << std::endl;

		std::cout << "const WrongAnimal *wrongCat = new WrongCat()" << std::endl;
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << "const WrongCat *cat = new WrongCat()" << std::endl;
		const WrongCat *cat = new WrongCat();

		std::cout << std::endl;

		std::cout << "WrongAnimal wrongCat->makeSound() : same as wrongAnimal" << std::endl;
		wrongCat->makeSound();
		std::cout << "WrongCat cat->makeSound() : same as wrongCat" << std::endl;
		cat->makeSound();
		std::cout << std::endl;

		delete wrongCat;
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << "\n  ========== copy test ==========" << std::endl;

		std::cout << "dog1 = Dog()" << std::endl;
		Dog dog1 = Dog();

		std::cout << "\ndog2 = Dog(dog1)" << std::endl;
		const Dog dog2 = Dog(dog1);
		dog1.makeSound();
		dog2.makeSound();

		std::cout << "\ndog1.setType = Bird" << std::endl;
		dog1.setType("Bird");

		std::cout << "dog1 type=" << dog1.getType() << std::endl;
		std::cout << "dog2 type=" << dog2.getType() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\n  ========== copy test ==========" << std::endl;
		std::cout << "cat1 = Cat()" << std::endl;
		const Cat cat1 = Cat();

		std::cout << "\ncat2 = cat1" << std::endl;
		Cat cat2 = cat1;

		std::cout << "\nmakeSound" << std::endl;
		cat1.makeSound();
		cat2.makeSound();
		std::cout << std::endl;
	}

	system("leaks a.out");
	return 0;
}
