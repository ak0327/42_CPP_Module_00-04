#pragma once

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal &animal);
	virtual ~Animal();
	Animal &operator=(const Animal &animal);

	virtual void makeSound() const;

	const std::string &getType() const;
	void setType(const std::string &type);

protected:
	std::string type_;

};