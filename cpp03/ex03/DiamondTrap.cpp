#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

// more good...
#define INIT_HP 100
#define INIT_EP 50
#define INIT_AD 30

#define CLAP_SUFFIX "_clap_name"

DiamondTrap::DiamondTrap() {
	name_ = "DiamondTrap";
	ClapTrap::set_name(name_ + CLAP_SUFFIX);
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	std::cout << COLOR_GREEN << "DiamondTrap default constructor called" << COLOR_RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) {
	name_ = name;
	ClapTrap::set_name(name + CLAP_SUFFIX);
	set_name(get_name());
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	std::cout << COLOR_GREEN << "DiamondTrap constructor called  name:" << name << COLOR_RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
	name_ = obj.name_;
	ClapTrap::set_name(name_ + CLAP_SUFFIX);
	set_hp(obj.get_hp());
	set_ep(obj.get_ep());
	set_ad(obj.get_ad());
	std::cout << COLOR_GREEN << "DiamondTrap copy constructor called" << COLOR_RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << COLOR_RED << "DiamondTrap destructor called" << COLOR_RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this != &obj) {
		name_ = obj.name_;
		ClapTrap::set_name(name_ + CLAP_SUFFIX);
		set_hp(obj.get_hp());
		set_ep(obj.get_ep());
		set_ad(obj.get_ad());
	}
	std::cout << COLOR_GREEN << "DiamondTrap copy assignment operator called" << COLOR_RESET << std::endl;
	return *this;
}

// duplicated...
unsigned int DiamondTrap::calc_repair_hp(unsigned int hp, unsigned int repair) {
	unsigned int	repair_value;

	if (hp >= INIT_HP)
		repair_value = 0;
	else if (UINT_MAX - hp >= repair) {
		repair_value = std::min(repair, INIT_HP - hp);
	} else {
		repair_value = UINT_MAX - hp;
	}
	return hp + repair_value; // same as attack_damage
}

// This member function will display both its name and its ClapTrap name.
void DiamondTrap::whoAmI() const {
	std::cout << COLOR_MAGENTA <<
	"[WhoAmI] name:" << name_ <<
	", ClapTrap name:" << ClapTrap::get_name() <<
	COLOR_RESET << std::endl;
}
