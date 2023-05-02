#include "Weapon.hpp"

Weapon::~Weapon() {}

// A getType() member function that returns a const reference to type.
const string &Weapon::getType() {
	return (type_);
}

// A setType() member function
// that sets type using the new one passed as parameter.
void Weapon::setType(string newType) {
	cout << "change [" << getType() << "] -> [" << newType << "]" << endl;
	type_ = newType;
}

