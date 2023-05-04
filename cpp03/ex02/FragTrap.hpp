#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// construction and destruction messages must be different
	FragTrap();
	FragTrap(const string &name);
	~FragTrap();

	void highFiveGuys();
};