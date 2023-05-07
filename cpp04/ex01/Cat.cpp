#include "Cat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Cat::Cat() : Animal(), brain_(new Brain()) {
	std::cout << COLOR_YELLOW << "Cat: constructor called" << COLOR_RESET << std::endl;
	// construction, Dog and Cat will create their Brain using new Brain();
	setType("Cat");
}

Cat::Cat(const Cat &cat) : Animal(cat), brain_(NULL) {
	std::cout << COLOR_YELLOW << "Cat: copy constructor called" << COLOR_RESET << std::endl;
	*this = cat;
}

Cat::~Cat() {
	std::cout << COLOR_YELLOW << "Cat: destructor called" << COLOR_RESET << std::endl;
	// destruction, Dog and Cat will delete their Brain.
	delete brain_;
}

Cat &Cat::operator=(const Cat &cat) {
	std::cout << COLOR_YELLOW << "Cat: copy assignment constructor called" << COLOR_RESET << std::endl;
	if (this != &cat) {
		Brain *tmp = brain_;
		brain_ = new Brain(cat.getBrain());
		delete tmp;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << COLOR_YELLOW << "[Cat] ₍ᐞ•༝•ᐞ₎◞ ̑̑ meows" << COLOR_RESET << std::endl;
}


Brain &Cat::getBrain() const {
	return *brain_;
}