#pragma once

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

using namespace std;

class ScavTrap : public ClapTrap {
public:
	//constructors, destructor and attack() will print different messages.
	ScavTrap();
	ScavTrap(const string &name);
	~ScavTrap();
	void attack(const string &target);

	void attack_on(ScavTrap &targetObj);


	void guardGate();
};