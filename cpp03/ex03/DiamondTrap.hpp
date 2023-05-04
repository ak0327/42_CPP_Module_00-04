#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
public:
	DiamondTrap();
	DiamondTrap(const string &name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &diamondTrap);

	void whoAmI();

private:
	// DiamondTrap class will have a name private attribute
	// same variable’s name than the one in the ClapTrap base class.
	string name_;

};