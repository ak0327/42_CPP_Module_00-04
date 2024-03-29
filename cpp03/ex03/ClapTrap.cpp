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

ClapTrap::ClapTrap() : name_("ClapTrapInit"),
					   hit_point_(INIT_HP),
					   energy_point_(INIT_EP),
					   attack_damage_(INIT_AD) {
	std::cout << COLOR_GREEN << "ClapTrap default constructor called" << COLOR_RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name_(name),
											  hit_point_(INIT_HP),
											  energy_point_(INIT_EP),
											  attack_damage_(INIT_AD) {
	std::cout << COLOR_GREEN << "ClapTrap constructor called  name:" << name << COLOR_RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : name_(obj.get_name()),
										  hit_point_(obj.get_hp()),
										  energy_point_(obj.get_ep()),
										  attack_damage_(obj.get_ad()) {
	std::cout << COLOR_GREEN << "ClapTrap copy constructor called" << COLOR_RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << COLOR_RED << "ClapTrap destructor called" << COLOR_RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	if (this != &obj) {
		set_name(obj.get_name());
		set_hp(obj.get_hp());
		set_ep(obj.get_ep());
		set_ad(obj.get_ad());
	}
	std::cout << COLOR_GREEN << "ClapTrap copy assignment constructor called" << COLOR_RESET << std::endl;
	return *this;
}

// attack A to B  -> B.takeDamage by A
void ClapTrap::attack_on(ClapTrap &targetObj) {
	if (this == &targetObj) {
		std::cout << COLOR_RED <<
				  "ClapTrap [Error] Can't attack themselves..." << COLOR_RESET << std::endl;
		return ;
	}
	if (targetObj.get_hp() == 0) {
		std::cout << COLOR_YELLOW <<
				  "ClapTrap [attack] " << targetObj.get_name() <<
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

void ClapTrap::attack(const std::string &target) {
	// check hp
	if (!is_actionable()) {
		std::cout << COLOR_YELLOW <<
				  "ClapTrap [attack] " << get_name() <<
				  " can't action..." << COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_YELLOW <<
				  "ClapTrap [attack] " << get_name() <<
				  " attacks " << target << ", causing " <<
				  get_ad() << " points of damage!" << COLOR_RESET << std::endl;
	}
}

// attack A to B  -> B.takeDamage by A
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->get_hp() == 0) {
		std::cout << COLOR_MAGENTA <<
				  "ClapTrap [takeDamage] " << get_name() <<
				  " is already ZERO hit point" << COLOR_RESET << std::endl;
		return ;
	}

	set_hp(calc_consume_point(get_hp(), amount));
	std::cout << COLOR_MAGENTA <<
			  "ClapTrap [takeDamage] " << get_name() <<
			  " take damage " << amount << COLOR_RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	// validate in this func ?
	if (!is_actionable()) {
		std::cout << COLOR_BLUE <<
				  "ClapTrap [beRepaired] " << get_name() <<
				  " can't action..."  << COLOR_RESET << std::endl;
		return ;
	}
	set_hp(calc_repair_hp(get_hp(), amount));
	set_ep(calc_consume_point(get_ep(), 1));
	std::cout << COLOR_BLUE <<
			  "ClapTrap [beRepaired] " << get_name() <<
			  " be repaired " << amount << COLOR_RESET << std::endl;
}

void ClapTrap::set_name(const std::string &name) { name_ = name; }
void ClapTrap::set_hp(unsigned int update) { hit_point_ = update; }
void ClapTrap::set_ep(unsigned int update) { energy_point_ = update; }
void ClapTrap::set_ad(unsigned int update) { attack_damage_ = update; }

const std::string &ClapTrap::get_name() const { return (name_); }
unsigned int ClapTrap::get_hp() const { return (hit_point_); }
unsigned int ClapTrap::get_ep() const { return (energy_point_); }
unsigned int ClapTrap::get_ad() const { return (attack_damage_); }

unsigned int ClapTrap::calc_consume_point(unsigned int val,
										  unsigned int minus) {
	if (val >= minus) {
		return (val - minus);
	}
	return 0;
}

unsigned int ClapTrap::calc_repair_hp(unsigned int hp, unsigned int repair) {
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

void ClapTrap::printStatus() {
	std::cout << " [" << get_name() << "'s status]: HP(" <<
			  get_hp() << "), EP(" <<
			  get_ep() << "), AD(" <<
			  get_ad() << ")" << std::endl;
}

bool ClapTrap::is_actionable() {
	return (get_hp() > 0 && get_ep() > 0);
}
