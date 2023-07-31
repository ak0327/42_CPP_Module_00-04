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

FragTrap::FragTrap() : ClapTrap() {
	set_name("FragTrap");
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	std::cout << COLOR_GREEN << "FragTrap default constructor called" << COLOR_RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	std::cout << COLOR_GREEN << "FragTrap constructor called  name:" << name << COLOR_RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
	std::cout << COLOR_GREEN << "FragTrap copy constructor called" << COLOR_RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << COLOR_RED << "FragTrap destructor called" << COLOR_RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
	ClapTrap::operator=(obj);
	std::cout << COLOR_GREEN << "FragTrap copy assignment operator called" << COLOR_RESET << std::endl;
	return *this;
}

// duplicated...
unsigned int FragTrap::calc_repair_hp(unsigned int hp, unsigned int repair) {
	unsigned int	repair_value;

	if (hp >= INIT_HP)
		repair_value = 0;
	else if (UINT_MAX - hp >= repair) {
		repair_value = std::min(repair, INIT_HP - hp);
	} else {
		repair_value = UINT_MAX - hp;
	}
	return hp + repair_value;
}

void FragTrap::highFiveGuys() {
	if (is_actionable()) {
		std::cout << COLOR_GREEN << "[" << get_name() << "] (*´ω`)人(´ω`*)" << COLOR_RESET << std::endl;
	} else if (get_hp() == 0) {
		std::cout << COLOR_RED << "[" << get_name() << "] _(´ཀ`」 ∠)_" << COLOR_RESET << std::endl;
	}
	else {
		std::cout << COLOR_BLUE << "[" << get_name() << "] ｡ﾟ･（>Д<）･ﾟ｡" << COLOR_RESET << std::endl;
	}
}
