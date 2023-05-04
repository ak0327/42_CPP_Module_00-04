#pragma once

#include <string>
#include <iostream>

using namespace std;

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const string &name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &clapTrap);

	// functions on subject
	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// getter, setter
	string &get_name();
	void set_hp(unsigned int update);
	void set_ep(unsigned int update);
	unsigned int get_hp();
	unsigned int get_ep();
	unsigned int get_ap();

	// helper
	void printStatus();
	bool is_action_available();
	unsigned int calc_consume_point(unsigned int val, unsigned int minus);

private:
	string name_;
	unsigned int hit_point_;
	unsigned int energy_point_;
	unsigned int attack_point_;

};