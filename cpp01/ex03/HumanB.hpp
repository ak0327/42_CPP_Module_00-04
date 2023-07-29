#pragma once

#include "Weapon.hpp"
#include <iostream>
#include <string>

// HumanB may not always have a Weapon,
class HumanB {
public:
	HumanB(std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);

	void getType();

private:
	std::string name_;
	Weapon *weapon_;
};
