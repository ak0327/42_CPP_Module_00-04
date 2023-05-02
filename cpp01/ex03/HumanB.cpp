#include "HumanB.hpp"

HumanB::~HumanB() {}

void HumanB::attack() {
	if (!weapon_) {
		cout << COLOR_RED << name_ << " can't attack" << COLOR_RESET << endl;
	}
	else {
		cout << COLOR_GREEN << name_ << " attacks with their " << weapon_->getType() << COLOR_RESET << endl;
	}
}

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
	cout << name_ << " equipped " << weapon_->getType() << endl;
}

void HumanB::getType() {
	cout << "HumanB getType:" << weapon_->getType() << endl;
}
