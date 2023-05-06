#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal();
	Animal(const Animal &animal);
	virtual ~Animal();
	Animal &operator=(const Animal &animal);

	virtual void makeSound() const;

	const string &getType() const;
	void setType(const string &type);

protected:
	string type_;

};