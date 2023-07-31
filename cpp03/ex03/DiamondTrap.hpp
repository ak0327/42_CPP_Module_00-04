#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &diamondTrap);
	unsigned int calc_repair_hp(unsigned int hp, unsigned int repair);

	void whoAmI() const ;

private:
	// DiamondTrap class will have a name private attribute
	// same variable’s name than the one in the ClapTrap base class.
	std::string name_;

};
