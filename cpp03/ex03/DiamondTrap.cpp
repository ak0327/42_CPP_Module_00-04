#include "DiamondTrap.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

#define INIT_HP 100
#define INIT_EP 100
#define INIT_AD 30

DiamondTrap::DiamondTrap() {
	set_name(ClapTrap::get_name() + "_clap_name");
	set_hp(FragTrap::get_hp());
	set_ep(ScavTrap::get_ep());
	set_ad(FragTrap::get_ad());
	cout << COLOR_GREEN << "DiamondTrap default constructor called" << COLOR_RESET << endl;
}

DiamondTrap::DiamondTrap(const std::string &name) {
	set_name(ClapTrap::get_name() + "_" + name);
	set_hp(FragTrap::get_hp());
	set_ep(ScavTrap::get_ep());
	set_ad(FragTrap::get_ad());
	cout << COLOR_GREEN << "DiamondTrap constructor called  name:" << name << COLOR_RESET << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
	if (this != &diamondTrap) {
		*this = diamondTrap;
	}
}

DiamondTrap::~DiamondTrap() {
	cout << COLOR_RED << "DiamondTrap destructor called" << COLOR_RESET << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	if (this != &diamondTrap) {
		DiamondTrap tmp = DiamondTrap(diamondTrap);
		set_name(tmp.get_name());
		set_hp(tmp.get_hp());
		set_ep(tmp.get_ep());
		set_ad(tmp.get_ad());

	}
	return *this;
}

// This member function will display both its name and its ClapTrap name.
void DiamondTrap::whoAmI() {

}