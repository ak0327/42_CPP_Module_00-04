#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

using namespace std;

int main() {
	{
		cout << "Animal *meta = Animal(): " << endl;
		const Animal *meta = new Animal();

		cout << "Animal *i = Cat() : " << endl;
		const Animal *i = new Cat();

		cout << "Animal *j = Dog() : " << endl;
		const Animal *j = new Dog();

		cout << endl;

		cout << "meta->getType :" << meta->getType() << endl;
		cout << "i->getType    :" << i->getType() << endl;
		cout << "j->getType    :" << j->getType() << endl;

		cout << endl;

		meta->makeSound();
		i->makeSound();		// cat sound
		j->makeSound();		// dog sound

		cout << endl;
		delete meta;
		delete i;
		delete j;
		cout << endl;
	}
	{
		const WrongAnimal *wrongCat = new WrongCat();
		const WrongCat *cat = new WrongCat();

		cout << endl;

		wrongCat->makeSound();
		cat->makeSound();
		cout << endl;

		delete wrongCat;
		delete cat;
		cout << endl;
	}
	{
		const Dog dog1 = Dog();
		const Dog dog2 = Dog(dog1);
		dog1.makeSound();
		dog2.makeSound();
		cout << endl;

	}
	{
		const Cat cat1 = Cat();
		Cat cat2 = cat1;
		cat1.makeSound();
		cat2.makeSound();
		cout << endl;
	}

//	system("leaks a.out");
	return 0;
}
