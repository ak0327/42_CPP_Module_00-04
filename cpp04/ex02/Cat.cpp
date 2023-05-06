#include "Cat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Cat::Cat() {
	cout << COLOR_YELLOW << "Cat: constructor called" << COLOR_RESET << endl;
	setType("Cat");
	// construction, Dog and Cat will create their Brain using new Brain();
	brain_ = new Brain();
}

Cat::Cat(const Cat &cat) {
	*this = cat;
	cout << COLOR_YELLOW << "Cat: copy constructor called" << COLOR_RESET << endl;
}

Cat::~Cat() {
	cout << COLOR_YELLOW << "Cat: destructor called" << COLOR_RESET << endl;
	// destruction, Dog and Cat will delete their Brain.
	delete brain_;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this != &cat) {
		setType(cat.getType());
	}
	return *this;
}

void Cat::makeSound() const {
	cout << COLOR_YELLOW << "[Cat] ₍ᐞ•༝•ᐞ₎◞ ̑̑ meows" << COLOR_RESET << endl;
}