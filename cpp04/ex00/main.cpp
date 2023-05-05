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
	}

//	system("leaks a.out");
	return 0;
}
