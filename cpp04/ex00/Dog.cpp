#include "Dog.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Dog::Dog() {
	setType("Dog");
	std::cout << COLOR_BLUE << "Dog: constructor" << COLOR_RESET << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
	std::cout << COLOR_BLUE << "Dog: copy constructor" << COLOR_RESET << std::endl;
}

Dog::~Dog() {
	std::cout << COLOR_BLUE << "Dog: destructor" << COLOR_RESET << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	Animal::operator=(rhs);
	std::cout << COLOR_GREEN << "Dog: copy assignment operator" << COLOR_RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << COLOR_BLUE << "[Dog] ٩(∪*´•ω•) Bow wow" << COLOR_RESET << std::endl;
}
