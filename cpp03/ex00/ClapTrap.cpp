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
	printStatus();
}

ClapTrap::ClapTrap(const string &name) : name_(name), hit_point_(10), energy_point_(10), attack_point_(0) {
	cout << COLOR_GREEN << "constructor called  name:" << name << COLOR_RESET << endl;
	printStatus();
}

ClapTrap::~ClapTrap() {}

string &ClapTrap::get_name() { return (name_);}
unsigned int ClapTrap::get_hp() { return (hit_point_);}
unsigned int ClapTrap::get_ep() { return (energy_point_);}
unsigned int ClapTrap::get_ap() { return (attack_point_);}

void ClapTrap::printStatus() {
	cout << "[" << get_name() << "'s status]"
	cout << "  HP : " << get_hp() << endl;
	cout << "  EP : " << get_ep() << endl;
	cout << "  AP : " << get_ap() << endl;
}