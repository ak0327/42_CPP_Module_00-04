#pragma once

#include <iostream>
#include <string>

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &dog);
	~Dog();

	Dog &operator=(const Dog &dog);

	void makeSound() const;
};