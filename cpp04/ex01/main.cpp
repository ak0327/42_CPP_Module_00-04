#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	{
		try {
			std::cout << "======== subject ========" << std::endl;
			const Animal *dog = new Dog();
			const Animal *cat = new Cat();

			std::cout << std::endl;

			dog->makeSound();
			cat->makeSound();

			delete dog;
			delete cat;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		try {
			std::cout << "======== animal array ========" << std::endl;
			std::cout << "Animal *animalArray[2]" << std::endl;
			Animal *animalArray[2];

			for (int i=0; i<2; i++) {
				if (i % 2) {
					animalArray[i] = new Dog();
				} else {
					animalArray[i] = new Cat();
				}
			}
			std::cout << std::endl;

			std::cout << "\nmakesound" << std::endl;
			for (int i=0; i<2; i++) {
				animalArray[i]->makeSound();
			}

			std::cout << std::endl;
			std::cout << "\ndelete" << std::endl;
			for (int i=0; i<2; i++) {
				delete animalArray[i];
			}
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		try {
			std::cout << "======== copy1: Cat cat1;  Cat cat2=Cat(cat1); ========" << std::endl;
			std::cout << "\nCat cat1;" << std::endl;
			Cat cat1;
			std::cout << "\ncheck brain[0]" << std::endl;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;

			std::cout << "\nCat cat2 = Cat(cat1);" << std::endl;
			Cat cat2 = Cat(cat1);

			std::cout << "\nmakesound" << std::endl;
			cat1.makeSound();
			cat2.makeSound();
			std::cout << std::endl;

			std::cout << "\ncheck brain[0]" << std::endl;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\nchange cat2.brain[0]" << std::endl;
			cat2.getBrain().setIdeaElem(0, "As yet I have no name.");
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\nCat cat3=Cat(cat2)" << std::endl;
			Cat cat3 = Cat(cat2);
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\nchange cat3.brain[0]" << std::endl;
			cat3.getBrain().setIdeaElem(0, "bow wow ...!");
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\nCat cat1=cat3" << std::endl;
			cat1 = cat3;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		try {
			std::cout << "======== Error: index out of range ========" << std::endl;

			Dog dog = Dog();
			std::cout << "\ndog.brain[200]=" << dog.getBrain().getIdeaElem(200) << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		try {
			std::cout << "======== Error: index out of range ========" << std::endl;
			Dog dog = Dog();
			std::cout << "\ndog.brain[100]=" << dog.getBrain().getIdeaElem(100) << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		try {
			std::cout << "======== Error: index out of range ========" << std::endl;
			Cat cat = Cat();
			std::cout << "\ncat.brain[99]=hoge" << std::endl;
			cat.getBrain().setIdeaElem(99, "hoge");

			std::cout << "\ncat.brain[99]=" << cat.getBrain().getIdeaElem(99) << std::endl;

			std::cout << "\ncat.brain[100]=hoge" << std::endl;
			cat.getBrain().setIdeaElem(100, "hoge");
			std::cout << "\n" << std::endl;

		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}

	system("leaks a.out");
	return 0;
}
