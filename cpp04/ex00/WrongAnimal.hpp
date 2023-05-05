#pragma once

#include <iostream>
#include <string>

using namespace std;

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &animal);

	// virtual
	void makeSound() const;

	const string &getType() const;
	void setType(const string &type);

protected:
	string type_;

};