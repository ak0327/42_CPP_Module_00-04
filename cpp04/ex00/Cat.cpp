#include "Cat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Cat::Cat() {
	setType("Cat");
	std::cout << COLOR_YELLOW << "Cat: constructor" << COLOR_RESET << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj) {
	std::cout << COLOR_YELLOW << "Cat: copy constructor" << COLOR_RESET << std::endl;
}

Cat::~Cat() {
	std::cout << COLOR_YELLOW << "Cat: destructor" << COLOR_RESET << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	Animal::operator=(rhs);
	std::cout << COLOR_GREEN << "Cat: copy assignment operator" << COLOR_RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << COLOR_YELLOW << "[Cat] ₍ᐞ•༝•ᐞ₎◞ ̑̑ meows" << COLOR_RESET << std::endl;
}
