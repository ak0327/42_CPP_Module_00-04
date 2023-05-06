#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

using namespace std;

int main() {
	{
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		cout << endl;
		dog->makeSound();
		cat->makeSound();

		delete dog;
		delete cat;
		cout << endl;
	}
	{
		// can't create
//		const Animal animal = Animal();
		cout << endl;
	}
//	system("leaks a.out");
	return 0;
}
