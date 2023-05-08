#pragma once

#include <string>
#include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &clapTrap);

	// functions on subject
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void attack_on(ClapTrap &targetObj);

	// setter
	void set_name(const std::string &name);
	void set_hp(unsigned int update);
	void set_ep(unsigned int update);
	void set_ad(unsigned int update);

	// getter
	std::string &get_name();
	unsigned int get_hp();
	unsigned int get_ep();
	unsigned int get_ad();

	// helper
	void printStatus();
	bool is_actionable();
	unsigned int calc_consume_point(unsigned int val, unsigned int minus);
	unsigned int calc_repair_hp(unsigned int hp, unsigned int repair);

private:
	std::string name_;
	unsigned int hit_point_;
	unsigned int energy_point_;
	unsigned int attack_damage_;

};