#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// construction and destruction messages must be different
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap();
	FragTrap &operator=(const FragTrap &fragTrap);

	void highFiveGuys();
};