#include "Dog.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Dog::Dog() {
	cout << COLOR_BLUE << "Dog: constructor called" << COLOR_RESET << endl;
	setType("Dog");
	// construction, Dog and Cat will create their Brain using new Brain();
	brain_ = new Brain();
}

Dog::Dog(const Dog &dog) {
	cout << COLOR_BLUE << "Dog: copy constructor called" << COLOR_RESET << endl;
	*this = dog;
}

Dog::~Dog() {
	cout << COLOR_BLUE << "Dog: destructor called" << COLOR_RESET << endl;
	// destruction, Dog and Cat will delete their Brain.
	delete brain_;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this != &dog) {
		setType(dog.getType());
	}
	return *this;
}

void Dog::makeSound() const {
	cout << COLOR_BLUE << "[Dog] ٩(∪*´•ω•) Bow wow" << COLOR_RESET << endl;
}