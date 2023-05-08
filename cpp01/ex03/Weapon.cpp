#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}
Weapon::~Weapon() {}

// A getType() member function that returns a const reference to type.
const std::string &Weapon::getType() {
	return (type_);
}

// A setType() member function
// that sets type using the new one passed as parameter.
void Weapon::setType(std::string newType) {
	std::cout << "change [" << getType() << "] -> [" << newType << "]" << std::endl;
	type_ = newType;
}

