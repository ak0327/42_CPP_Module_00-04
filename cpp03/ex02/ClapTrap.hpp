#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const string &name);
	ClapTrap(const string &name, unsigned int hp, unsigned int ep, unsigned int ad);
	ClapTrap(const ClapTrap &clapTrap);
	virtual ~ClapTrap();

	ClapTrap &operator=(const ClapTrap &clapTrap);

	// functions on subject
	virtual void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// getter, setter
	void set_name(const string &name);
	void set_hp(unsigned int update);
	void set_ep(unsigned int update);
	void set_ad(unsigned int update);

	string &get_name();
	unsigned int get_hp();
	unsigned int get_ep();
	unsigned int get_ad();

	// helper
	void printStatus();
	bool is_action_available();
	unsigned int calc_consume_point(unsigned int val, unsigned int minus);

protected:
	string name_;
	unsigned int hit_point_;
	unsigned int energy_point_;
	unsigned int attack_damage_;

};