#include "ClapTrap.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"


ClapTrap::ClapTrap() : name_("null"), hit_point_(10), energy_point_(10), attack_point_(0) {
	cout << COLOR_GREEN << "default constructor called" << COLOR_RESET << endl;
}

ClapTrap::ClapTrap(const string &name) : name_(name), hit_point_(10), energy_point_(10), attack_point_(0) {
	cout << COLOR_GREEN << "constructor called  name:" << name << COLOR_RESET << endl;
}

ClapTrap::~ClapTrap() {
	cout << COLOR_RED << "destructor called" << COLOR_RESET << endl;
}

void ClapTrap::attack(const std::string &target) {
	// check hp
	if (!is_action_available()) {
		cout << COLOR_YELLOW << "ClapTrap [attack]" << get_name() << " can't action..." << COLOR_RESET << endl;
		return ;
	}
	// ep--
	set_ep(calc_consume_point(get_ep(), 1));

	// target hp-=ap :: next ex?
	cout << COLOR_YELLOW << "ClapTrap [attack]" << get_name() << " attacks " << target << ", causing " << get_ap() << " points of damage!" << COLOR_RESET << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!is_action_available()) {
		cout << COLOR_MAGENTA << "ClapTrap [takeDamage]" << get_name() << " can't action..." << COLOR_RESET << endl;
		return ;
	}
	set_hp(calc_consume_point(get_hp(), amount));
	cout << COLOR_MAGENTA << "ClapTrap [takeDamage] " << get_name() << "take damage " << amount << COLOR_RESET << endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	// validate in this func ?
	if (!is_action_available()) {
		cout << COLOR_BLUE << "ClapTrap [beRepaired] " << get_name() << " can't action..."  << COLOR_RESET << endl;
		return ;
	}
	set_hp(get_hp() + amount);
	set_ep(calc_consume_point(get_ep(), 1));
	cout << COLOR_BLUE << "ClapTrap [beRepaired] " << get_name() << "be repaired " << amount << COLOR_RESET << endl;
}


string &ClapTrap::get_name() { return (name_); }
void ClapTrap::set_hp(unsigned int update) { hit_point_ = update; }
void ClapTrap::set_ep(unsigned int update) { energy_point_ = update; }
unsigned int ClapTrap::get_hp() { return (hit_point_); }
unsigned int ClapTrap::get_ep() { return (energy_point_); }
unsigned int ClapTrap::get_ap() { return (attack_point_); }

unsigned int ClapTrap::calc_consume_point(unsigned int val,
												 unsigned int minus) {
	if (val >= minus) {
		return (val - minus);
	}
	return (0);
}

void ClapTrap::printStatus() {
	cout << " [" << get_name() << "'s status]: HP(" << get_hp() << "), EP(" << get_ep() << "), AP(" << get_ap() << ")" << endl;
}

bool ClapTrap::is_action_available() {
	return (get_hp() > 0 && get_ep() > 0);
}