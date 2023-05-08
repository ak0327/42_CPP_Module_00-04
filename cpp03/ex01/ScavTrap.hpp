#pragma once

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	//constructors, destructor and attack() will print different messages.
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &scavTrap);

	void attack(const std::string &target);
	void attack_on(ScavTrap &targetObj);

	void guardGate();
};