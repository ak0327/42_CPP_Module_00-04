#include "ScavTrap.hpp"

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
	set_name("ScavTrap");
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	cout << COLOR_GREEN << "ScavTrap default constructor called" << COLOR_RESET << endl;
}

ScavTrap::ScavTrap(const string &name) {
	set_name(name);
	set_hp(INIT_HP);
	set_ep(INIT_EP);
	set_ad(INIT_AD);
	cout << COLOR_GREEN << "ScavTrap constructor called  name:" << name << COLOR_RESET << endl;
}

ScavTrap::~ScavTrap() {
	cout << COLOR_RED << "ScavTrap destructor called" << COLOR_RESET << endl;
}

void ScavTrap::attack(const string &target) {
	// check hp
	if (!is_action_available()) {
		cout << COLOR_YELLOW << "ScavTrap [attack] " << get_name() << " can't action..." << COLOR_RESET << endl;
		return ;
	}
	// ep--
	set_ep(calc_consume_point(get_ep(), 1));

	// target hp-=ap :: next ex?
	cout << COLOR_YELLOW << "ScavTrap [attack] " << get_name() << " attacks " << target << ", causing " << get_ad() << " points of damage!" << COLOR_RESET << endl;
}

// HP == 0        : DIED
// 0 < HP <= 10   : DANGER
// 10 < HP <= 100 : GOOD
void ScavTrap::guardGate() {
	string status;
	if (get_hp() == 0) {
		status = COLOR_RED "DIED" COLOR_RESET;
	} else if (get_hp() <= 10) {
		status = COLOR_YELLOW "DANGER" COLOR_RESET;
	} else {
		status = COLOR_CYAN "GOOD" COLOR_RESET;
	}
	cout << "Scav Trap [guardGate] " << status << endl;
}
