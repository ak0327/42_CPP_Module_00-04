#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &cat);
	~Cat();

	Cat &operator=(const Cat &cat);

	void makeSound() const;

	Brain &getBrain() const;

private:
	// Dog and Cat will have a private Brain* attribute
	Brain *brain_;

};