#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	{
		std::cout << "-------------------- test 1 : Animal constructor --------------------" << std::endl;

		std::cout << "test1 = Animal()" << std::endl;
		Animal test1 = Animal();
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test2 = Animal(test1)" << std::endl;
		Animal test2 = Animal(test1);
		std::cout << "test1.setType('test1')" << std::endl;
		test1.setType("test1");
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test3 = test1" << std::endl;
		Animal test3 = test1;
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << " test3: type=" << test3.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test2.setType('test2')" << std::endl;
		std::cout << "test3.setType('test3')" << std::endl;
		test2.setType("test2");
		test3.setType("test3");
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << " test3: type=" << test3.getType() << std::endl;

		std::cout << std::endl;
		std::cout << "make sound" << std::endl;
		test1.makeSound();
		test2.makeSound();
		test3.makeSound();

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 2 : Dog constructor --------------------" << std::endl;

		std::cout << "test1 = Animal()" << std::endl;
		Dog test1 = Dog();
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test2 = Dog(test1)" << std::endl;
		Dog test2 = Dog(test1);
		std::cout << "test1.setType('test1')" << std::endl;
		test1.setType("test1");
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test3 = test1" << std::endl;
		Dog test3 = test1;
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << " test3: type=" << test3.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test2.setType('test2')" << std::endl;
		std::cout << "test3.setType('test3')" << std::endl;
		test2.setType("test2");
		test3.setType("test3");
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << " test3: type=" << test3.getType() << std::endl;

		std::cout << std::endl;
		std::cout << "make sound" << std::endl;
		test1.makeSound();
		test2.makeSound();
		test3.makeSound();

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 3 : Cat constructor --------------------" << std::endl;

		std::cout << "test1 = Animal()" << std::endl;
		Cat test1 = Cat();
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test2 = Cat(test1)" << std::endl;
		Cat test2 = Cat(test1);
		std::cout << "test1.setType('test1')" << std::endl;
		test1.setType("test1");
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test3 = test1" << std::endl;
		Cat test3 = test1;
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << " test3: type=" << test3.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "test2.setType('test2')" << std::endl;
		std::cout << "test3.setType('test3')" << std::endl;
		test2.setType("test2");
		test3.setType("test3");
		std::cout << " test1: type=" << test1.getType() << std::endl;
		std::cout << " test2: type=" << test2.getType() << std::endl;
		std::cout << " test3: type=" << test3.getType() << std::endl;

		std::cout << std::endl;
		std::cout << "make sound" << std::endl;
		test1.makeSound();
		test2.makeSound();
		test3.makeSound();

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 4 : subject --------------------" << std::endl;

		std::cout << "Animal *meta = Animal(): " << std::endl;
		const Animal *meta = new Animal();
		std::cout << std::endl;

		std::cout << "Animal *j = Dog()" << std::endl;
		const Animal *j = new Dog();
		std::cout << std::endl;

		std::cout << "Animal *i = Cat()" << std::endl;
		const Animal *i = new Cat();
		std::cout << std::endl;

		std::cout << "meta->getType :" << meta->getType() << std::endl;
		std::cout << "j->getType    :" << j->getType() << std::endl;
		std::cout << "i->getType    :" << i->getType() << std::endl;

		std::cout << std::endl;

		std::cout << "meta->makeSound()" << std::endl;
		meta->makeSound();

		std::cout << "j->makeSound()" << std::endl;
		j->makeSound();		// dog sound

		std::cout << "i->makeSound()" << std::endl;
		i->makeSound();		// cat sound

		std::cout << std::endl;
		delete meta;
		delete j;
		delete i;

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- wrong cat --------------------" << std::endl;

		std::cout << "WrongAnimal *wrong_animal_cat = new WrongCat()" << std::endl;
		const WrongAnimal *wrong_animal_cat = new WrongCat();
		std::cout << std::endl;

		std::cout << "WrongAnimal wrong_animal_cat->makeSound() : same as WrongAnimal" << std::endl;
		wrong_animal_cat->makeSound();
		std::cout << std::endl;


		std::cout << "WrongCat *cat = new WrongCat()" << std::endl;
		const WrongCat *wrong_cat = new WrongCat();
		std::cout << std::endl;

		std::cout << "WrongCat wrong_cat->makeSound() : same as WrongCat" << std::endl;
		wrong_cat->makeSound();
		std::cout << std::endl;

		delete wrong_animal_cat;
		delete wrong_cat;

		std::cout << "\n" << std::endl;

	}
	{
		std::cout << "-------------------- collect cat --------------------" << std::endl;

		std::cout << "Animal *animal_cat = new Cat()" << std::endl;
		const Animal *animal_cat = new Cat();
		std::cout << std::endl;

		std::cout << "Animal animal_cat->makeSound() : same as Cat" << std::endl;
		animal_cat->makeSound();
		std::cout << std::endl;


		std::cout << "WrongCat *cat = new Cat()" << std::endl;
		const Cat *cat = new Cat();
		std::cout << std::endl;

		std::cout << "Cat cat->makeSound() : same as Cat" << std::endl;
		cat->makeSound();
		std::cout << std::endl;

		delete animal_cat;
		delete cat;

		std::cout << "\n" << std::endl;

	}
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
