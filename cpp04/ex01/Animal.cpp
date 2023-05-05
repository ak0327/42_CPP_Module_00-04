#include "Animal.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Animal::Animal() : type_("Animal") {
	cout << COLOR_GREEN << "Animal: constructor called" << COLOR_RESET << endl;
}

Animal::Animal(const Animal &animal) {
	*this = animal;
	cout << COLOR_GREEN << "Animal: copy constructor called" << COLOR_RESET << endl;
}

Animal::~Animal() {
	cout << COLOR_GREEN << "Animal: destructor called" << COLOR_RESET << endl;
}

Animal &Animal::operator=(const Animal &animal) {
	if (this != &animal) {
		setType(animal.getType());
	}
	cout << COLOR_GREEN << "Animal: copy assignment operator called" << COLOR_RESET << endl;
	return *this;
}

// setType() const; can't change
void Animal::setType(const string &type) {
	type_ = type;
}

const string &Animal::getType() const {
	return type_;
}

// const Animal, Animal
void Animal::makeSound() const {
	cout << COLOR_GREEN << "[Animal] Yo who!! ٩(ˊᗜˋ*)و" << COLOR_RESET << endl;
}
