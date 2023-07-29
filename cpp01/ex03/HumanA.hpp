#pragma once

#include "Weapon.hpp"
#include <iostream>
#include <string>

// HumanA will always be armed.
class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack();

private:
	std::string name_;
	Weapon &weapon_;

};
