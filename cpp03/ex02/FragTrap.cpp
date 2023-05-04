#include "FragTrap.hpp"

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

FragTrap::FragTrap() {
	set_name("FragTrap");
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	cout << COLOR_GREEN << "FragTrap default constructor called" << COLOR_RESET << endl;
}

FragTrap::FragTrap(const string &name) {
	set_name(name);
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	cout << COLOR_GREEN << "FragTrap constructor called  name:" << name << COLOR_RESET << endl;
}

FragTrap::~FragTrap() {
	cout << COLOR_RED << "FragTrap destructor called" << COLOR_RESET << endl;
}

void FragTrap::highFiveGuys() {
	if (is_actionable()) {
		cout << COLOR_GREEN << "[" << get_name() << "] (*´ω`)人(´ω`*)" << COLOR_RESET << endl;
	} else if (get_hp() == 0) {
		cout << COLOR_RED << "[" << get_name() << "] _(´ཀ`」 ∠)_" << COLOR_RESET << endl;
	}
	else {
		cout << COLOR_BLUE << "[" << get_name() << "] ｡ﾟ･（>Д<）･ﾟ｡" << COLOR_RESET << endl;
	}
}