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

		delete dog;
		delete cat;
		cout << endl;
	}
	{
		cout << "animal array" << endl;
		Animal *animalArray[6];

		for (int i=0; i<6; i++) {
			if (i % 2) {
				animalArray[i] = new Dog();
			} else {
				animalArray[i] = new Cat();
			}
		}
		cout << endl;

		for (int i=0; i<6; i++) {
			animalArray[i]->makeSound();
		}

		cout << endl;

		for (int i=0; i<6; i++) {
			delete animalArray[i];
		}
		cout << endl;
	}

//	system("leaks a.out");
	return 0;
}
