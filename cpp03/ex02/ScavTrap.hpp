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
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &scavTrap);

	void attack(const string &target);
	void attack_on(ScavTrap &targetObj);

	void guardGate();
};