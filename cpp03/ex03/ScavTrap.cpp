#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

#define INIT_HP 100
#define INIT_EP 50
#define INIT_AD 20

ScavTrap::ScavTrap() {
	set_name("ScavTrapInit");
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	std::cout << COLOR_GREEN << "ScavTrap default constructor called" << COLOR_RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	std::cout << COLOR_GREEN << "ScavTrap constructor called  name:" << name << COLOR_RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)  {
	std::cout << COLOR_GREEN << "ScavTrap copy constructor called" << COLOR_RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << COLOR_RED << "ScavTrap destructor called" << COLOR_RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
	ClapTrap::operator=(obj);
	std::cout << COLOR_GREEN << "ScavTrap copy assignment constructor called" << COLOR_RESET << std::endl;
	return *this;
}

// attack A to B  -> B.takeDamage by A
void ScavTrap::attack_on(ScavTrap &targetObj) {
	if (this == &targetObj) {
		std::cout << COLOR_RED <<
				  "ScavTrap [Error] Can't attack themselves..." << COLOR_RESET << std::endl;
		return ;
	}
	if (targetObj.get_hp() == 0) {
		std::cout << COLOR_YELLOW <<
				  "ScavTrap [attack] " << targetObj.get_name() <<
				  " is already ZERO hit point" << COLOR_RESET << std::endl;
		return ;
	}

	// for subject, print message
	attack(targetObj.get_name());

	// check actionable
	if (is_actionable()) {
		// ep--
		set_ep(calc_consume_point(get_ep(), 1));
		// targetObj.hp -= ad
		targetObj.set_hp(calc_consume_point(targetObj.get_hp(), get_ad()));
	}
}

void ScavTrap::attack(const std::string &target) {
	// check hp
	if (!is_actionable()) {
		std::cout << COLOR_YELLOW <<
				  "ScavTrap [attack] " << get_name() <<
				  " can't action..." << COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_YELLOW <<
				  "ScavTrap [attack] " << get_name() <<
				  " attacks " << target << ", causing " <<
				  get_ad() << " points of damage!" << COLOR_RESET << std::endl;
	}
}

// duplicated...
unsigned int ScavTrap::calc_repair_hp(unsigned int hp, unsigned int repair) {
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


// HP == 0        : DIED
// 0 < HP <= 10   : DANGER
// 10 < HP <= 100 : GOOD
void ScavTrap::guardGate() {
	std::string status;
	if (get_hp() == 0) {
		status = COLOR_RED "DIED" COLOR_RESET;
	} else if (get_hp() <= 10) {
		status = COLOR_YELLOW "DANGER" COLOR_RESET;
	} else {
		status = COLOR_CYAN "GOOD" COLOR_RESET;
	}
	std::cout << "[" << get_name() << "'s guardGate] " << status << std::endl;
}

