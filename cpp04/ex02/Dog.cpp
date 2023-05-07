#include "Dog.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Dog::Dog() : Animal(), brain_(new Brain()) {
	std::cout << COLOR_BLUE << "Dog: constructor called" << COLOR_RESET << std::endl;
	setType("Dog");
	// construction, Dog and Cat will create their Brain using new Brain();
}

Dog::Dog(const Dog &dog) : Animal(), brain_(NULL)  {
	std::cout << COLOR_BLUE << "Dog: copy constructor called" << COLOR_RESET << std::endl;
	*this = dog;
}

Dog::~Dog() {
	std::cout << COLOR_BLUE << "Dog: destructor called" << COLOR_RESET << std::endl;
	// destruction, Dog and Cat will delete their Brain.
	delete brain_;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this != &dog) {
		Brain *tmp = brain_;
		brain_ = new Brain(*dog.brain_);
		delete tmp;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << COLOR_BLUE << "[Dog] ٩(∪*´•ω•) Bow wow" << COLOR_RESET << std::endl;
}

Brain &Dog::getBrain() const {
	return *brain_;
}