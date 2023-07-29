#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {
	std::cout << "HumanA created: " << name << "(A) is armed with " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << COLOR_BLUE << name_ << " attacks with their " << weapon_.getType() << COLOR_RESET << std::endl;
}
