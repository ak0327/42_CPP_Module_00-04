#include "WrongAnimal.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	cout << COLOR_RED << "WrongAnimal: constructor" << COLOR_RESET << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	this->setType(obj.getType());
	cout << COLOR_RED << "WrongAnimal: copy constructor" << COLOR_RESET << endl;
}

WrongAnimal::~WrongAnimal() {
	cout << COLOR_RED << "WrongAnimal: destructor" << COLOR_RESET << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	cout << COLOR_RED << "WrongAnimal: copy assignment operator" << COLOR_RESET << endl;
	return *this;
}

// setType() const; can't change
void WrongAnimal::setType(const string &type) {
	type_ = type;
}

const string &WrongAnimal::getType() const {
	return type_;
}

// const WrongAnimal, WrongAnimal
void WrongAnimal::makeSound() const {
	cout << COLOR_RED << "[WrongAnimal] I am WRONG ANIMAL!!!" << COLOR_RESET << endl;
}
