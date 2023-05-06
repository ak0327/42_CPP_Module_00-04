#pragma once

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &dog);
	~Dog();

	Dog &operator=(const Dog &dog);

	void makeSound() const;

private:
	// Dog and Cat will have a private Brain* attribute
	Brain *brain_;

};