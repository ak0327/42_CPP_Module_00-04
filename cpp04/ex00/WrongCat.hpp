#pragma once

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &wrongCat);
	~WrongCat();
	WrongCat &operator=(const WrongCat &wrongCat);

	void makeSound() const;

};
