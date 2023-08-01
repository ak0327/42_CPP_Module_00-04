#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &cat);
	~Cat();

	Cat &operator=(const Cat &cat);

	void makeSound() const;

};
