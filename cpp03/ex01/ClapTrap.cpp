#include "ClapTrap.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

#define INIT_HP 10
#define INIT_EP 10
#define INIT_AD 0

ClapTrap::ClapTrap() : name_("ClapTrap"), hit_point_(INIT_HP), energy_point_(INIT_EP), attack_damage_(INIT_AD) {
	cout << COLOR_GREEN << "ClapTrap default constructor called" << COLOR_RESET << endl;
}

ClapTrap::ClapTrap(const string &name) : name_(name), hit_point_(INIT_HP), energy_point_(INIT_EP), attack_damage_(INIT_AD) {
	cout << COLOR_GREEN << "ClapTrap constructor called  name:" << name << COLOR_RESET << endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	if (this != &clapTrap) {
		*this = clapTrap;
	}
}

ClapTrap::~ClapTrap() {
	cout << COLOR_RED << "ClapTrap destructor called" << COLOR_RESET << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	if (this != &clapTrap) {
		ClapTrap tmp = ClapTrap(clapTrap);
		set_name(tmp.get_name());
		set_hp(tmp.get_hp());
		set_ep(tmp.get_ep());
		set_ad(tmp.get_ad());

	}
	return *this;
}

void ClapTrap::attack_on(ClapTrap &targetObj) {
	if (this == &targetObj) {
		return ;
	}
	if (targetObj.get_hp() == 0) {
		cout << COLOR_YELLOW <<
			 "ClapTrap [attack] " << targetObj.get_name() <<
			 " is already ZERO hit point" << COLOR_RESET << endl;
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

void ClapTrap::attack(const std::string &target) {
	// check hp
	if (!is_actionable()) {
		cout << COLOR_YELLOW <<
			 "ClapTrap [attack] " << get_name() <<
			 " can't action..." << COLOR_RESET << endl;
	} else {
		cout << COLOR_YELLOW <<
			 "ClapTrap [attack] " << get_name() <<
			 " attacks " << target << ", causing " <<
			 get_ad() << " points of damage!" << COLOR_RESET << endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!is_actionable()) {
		cout << COLOR_MAGENTA <<
			 "ClapTrap [takeDamage] " << get_name() <<
			 " can't action..." << COLOR_RESET << endl;
		return ;
	}
	set_hp(calc_consume_point(get_hp(), amount));
	cout << COLOR_MAGENTA <<
		 "ClapTrap [takeDamage] " << get_name() <<
		 " take damage " << amount << COLOR_RESET << endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	// validate in this func ?
	if (!is_actionable()) {
		cout << COLOR_BLUE <<
			 "ClapTrap [beRepaired] " << get_name() <<
			 " can't action..."  << COLOR_RESET << endl;
		return ;
	}
	set_hp(calc_repair_hp(get_hp(), amount));
	set_ep(calc_consume_point(get_ep(), 1));
	cout << COLOR_BLUE <<
		 "ClapTrap [beRepaired] " << get_name() <<
		 " be repaired " << amount << COLOR_RESET << endl;
}

void ClapTrap::set_name(const string &name) { name_ = name; }
void ClapTrap::set_hp(unsigned int update) { hit_point_ = update; }
void ClapTrap::set_ep(unsigned int update) { energy_point_ = update; }
void ClapTrap::set_ad(unsigned int update) { attack_damage_ = update; }

string &ClapTrap::get_name() { return (name_); }
unsigned int ClapTrap::get_hp() { return (hit_point_); }
unsigned int ClapTrap::get_ep() { return (energy_point_); }
unsigned int ClapTrap::get_ad() { return (attack_damage_); }

unsigned int ClapTrap::calc_consume_point(unsigned int val,
										  unsigned int minus) {
	if (val >= minus) {
		return (val - minus);
	}
	return (0);
}

unsigned int ClapTrap::calc_repair_hp(unsigned int hp, unsigned int repair) {
	if (UINT_MAX - hp >= repair)
		return (hp + repair);
	return (UINT_MAX); // same as attack_damage
}

void ClapTrap::printStatus() {
	cout << " [" << get_name() << "'s status]: HP(" <<
		 get_hp() << "), EP(" <<
		 get_ep() << "), AP(" <<
		 get_ad() << ")" << endl;
}

bool ClapTrap::is_actionable() {
	return (get_hp() > 0 && get_ep() > 0);
}