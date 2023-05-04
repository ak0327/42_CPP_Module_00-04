#pragma once
#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap {
public:
	DiamondTrap();
	DiamondTrap(const string &name);


	void whoAmI();

private:
	// DiamondTrap class will have a name private attribute
	// same variable’s name than the one in the ClapTrap base class.
	string name_;

};