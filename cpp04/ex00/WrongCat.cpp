#include "WrongCat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

WrongCat::WrongCat() {
	setType("WrongCat");
	std::cout << COLOR_YELLOW << "WrongCat: constructor" << COLOR_RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) {
	this->setType(obj.getType());
	std::cout << COLOR_YELLOW << "WrongCat: copy constructor" << COLOR_RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << COLOR_YELLOW << "WrongCat: destructor" << COLOR_RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	std::cout << COLOR_GREEN << "WrongCat: copy assignment operator" << COLOR_RESET << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	cout << COLOR_YELLOW << "[WrongCat] Bow wow?" << COLOR_RESET << endl;
}
