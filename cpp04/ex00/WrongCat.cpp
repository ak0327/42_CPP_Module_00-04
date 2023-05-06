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
	cout << COLOR_YELLOW << "WrongCat: constructor called" << COLOR_RESET << endl;
}

WrongCat::WrongCat(const WrongCat &cat) {
	*this = cat;
	cout << COLOR_YELLOW << "WrongCat: copy constructor called" << COLOR_RESET << endl;
}

WrongCat::~WrongCat() {
	cout << COLOR_YELLOW << "WrongCat: destructor called" << COLOR_RESET << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
	if (this != &cat) {
		setType(cat.getType());
	}
	return *this;
}

void WrongCat::makeSound() const {
	cout << COLOR_YELLOW << "[WrongCat] Bow wow?" << COLOR_RESET << endl;
}