#pragma once

#include <string>
#include <iostream>

using namespace std;

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const string &name);
	~ClapTrap();

	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);

	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void printStatus();
	string &get_name();
	unsigned int get_hp();
	unsigned int get_ep();
	unsigned int get_ap();

private:
	string name_;
	unsigned int hit_point_;
	unsigned int energy_point_;
	unsigned int attack_point_;

};