#include <iostream>
#include <limits.h>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		std::cout << "-------------------- subject --------------------" << std::endl;
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
	{
		std::cout << "-------------------- animal array --------------------" << std::endl;
		try {
			std::cout << "=== Animal *animalArray[4] ===" << std::endl;
			int arr_size = 4;
			Animal *animalArray[arr_size];

			for (int i=0; i<arr_size; i++) {
				if (i % 2) {
					animalArray[i] = new Dog();
				} else {
					animalArray[i] = new Cat();
				}
				std::cout << std::endl;

			}
			std::cout << std::endl;

			std::cout << "\n=== makesound ===" << std::endl;
			for (int i=0; i<arr_size; i++) {
				std::cout << "index=" << i << " : ";
				animalArray[i]->makeSound();
			}

			std::cout << std::endl;
			std::cout << "\n=== delete ===" << std::endl;
			for (int i=0; i<arr_size; i++) {
				delete animalArray[i];
				std::cout << std::endl;
			}
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- copy1: Cat cat1;  Cat cat2=Cat(cat1); --------------------" << std::endl;
		try {
			std::cout << "\n=== Cat cat1 ===" << std::endl;
			Cat cat1;
			std::cout << "\n=== check brain[0] ===" << std::endl;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;

			std::cout << "\n=== Cat cat2 = Cat(cat1) ===" << std::endl;
			Cat cat2 = Cat(cat1);

			std::cout << "\n=== make sound : cat1 ===" << std::endl;
			cat1.makeSound();
			std::cout << "\n=== make sound : cat2 ===" << std::endl;
			cat2.makeSound();
			std::cout << std::endl;

			std::cout << "\n=== check brain[0] ===" << std::endl;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\n=== change cat2.brain[0] to 'As yet I have no name.' ===" << std::endl;
			cat2.getBrain().setIdeaElem(0, "As yet I have no name.");
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\n=== Cat cat3=Cat(cat2) ===" << std::endl;
			Cat cat3 = Cat(cat2);
			std::cout << std::endl;

			std::cout << "\n=== check brain[0] ===" << std::endl;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat3.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\n=== change cat3.brain[0] to 'bow wow ...!' ===" << std::endl;
			cat3.getBrain().setIdeaElem(0, "bow wow ...!");
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat3.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

			std::cout << "\n=== Cat cat1=cat3 ===" << std::endl;
			cat1 = cat3;
			std::cout << std::endl;

			std::cout << "\n=== check brain[0] ===" << std::endl;
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat3.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;

			std::cout << std::endl;

			std::cout << "\n=== change cat3.brain[0] to 'meows' ===" << std::endl;
			cat3.getBrain().setIdeaElem(0, "meows");
			std::cout << "cat1.brain[0]=" << cat1.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat2.brain[0]=" << cat2.getBrain().getIdeaElem(0) << std::endl;
			std::cout << "cat3.brain[0]=" << cat3.getBrain().getIdeaElem(0) << std::endl;
			std::cout << std::endl;

		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- Error: index out of range; 100 --------------------" << std::endl;
		try {
			Dog dog = Dog();
			std::string elem = dog.getBrain().getIdeaElem(100);
			std::cout << "\ndog.brain[100]=" << elem << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- Error: index out of range; 200 --------------------" << std::endl;
		try {
			Dog dog = Dog();
			std::string elem = dog.getBrain().getIdeaElem(200);
			std::cout << "\ndog.brain[200]=" << elem << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- Error: index out of range; -1 --------------------" << std::endl;
		try {
			Dog dog = Dog();
			std::string elem = dog.getBrain().getIdeaElem(-1);
			std::cout << "\ndog.brain[-1]=" << elem << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- Error: index out of range; INT_MAX --------------------" << std::endl;
		try {
			Dog dog = Dog();
			std::string elem = dog.getBrain().getIdeaElem(INT_MAX);
			std::cout << "\ndog.brain[INT_MAX]=" << elem << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- Error: index out of range; SIZE_MAX --------------------" << std::endl;
		try {
			Dog dog = Dog();
			std::string elem = dog.getBrain().getIdeaElem(SIZE_MAX);
			std::cout << "\ndog.brain[SIZE_MAX]=" << elem << std::endl;
			std::cout << "\n" << std::endl;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- Error: index out of range; set(100) --------------------" << std::endl;
		try {
			Cat cat = Cat();
			std::cout << std::endl;
			std::cout << "=== set cat.brain[99]=hoge ===" << std::endl;
			cat.getBrain().setIdeaElem(99, "hoge");

			std::string elem_1 = cat.getBrain().getIdeaElem(99);
			std::cout << "cat.brain[99]=" << elem_1 << std::endl;

			std::cout << std::endl;

			std::cout << "=== set cat.brain[100]=hoge ===" << std::endl;
			cat.getBrain().setIdeaElem(100, "hoge");

			std::string elem_2 = cat.getBrain().getIdeaElem(99);
			std::cout << "cat.brain[100]=" << elem_2 << std::endl;
			std::cout << "\n" << std::endl;

		} catch (std::exception const &e) {
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
