#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {
	std::cout << "HumanB() " << name << "(B) has no weapon..." << std::endl;
}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (!weapon_) {
		std::cout << COLOR_RED << name_ << " can't attack" << COLOR_RESET << std::endl;
	}
	else {
		std::cout << COLOR_GREEN << name_ << " attacks with their " << weapon_->getType() << COLOR_RESET << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
	std::cout << name_ << " equipped " << weapon_->getType() << std::endl;
}

void HumanB::getType() {
	std::cout << "HumanB getType:" << weapon_->getType() << std::endl;
}
