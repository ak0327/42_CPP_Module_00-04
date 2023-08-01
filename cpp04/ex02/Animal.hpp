#pragma once

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);

	virtual ~Animal();

	virtual void makeSound() const = 0;

	const std::string &getType() const;
	void setType(const std::string &type);

protected:
	std::string type_;

};
