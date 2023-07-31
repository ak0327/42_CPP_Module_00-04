#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clapTrap);

	// If your class has virtual methods, its destructor should be virtual.
	virtual ~ClapTrap(); // to call destructor of subclass

	ClapTrap &operator=(const ClapTrap &clapTrap);

	// functions on subject
	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// add func to attack
	void attack_on(ClapTrap &targetObj);

	// setter
	void set_name(const std::string &name);
	void set_hp(unsigned int update);
	void set_ep(unsigned int update);
	void set_ad(unsigned int update);

	// getter
	const std::string &get_name() const ;
	unsigned int get_hp() const ;
	unsigned int get_ep() const ;
	unsigned int get_ad() const ;

	// helper
	void printStatus();
	bool is_actionable();
	unsigned int calc_consume_point(unsigned int val, unsigned int minus);
	virtual unsigned int calc_repair_hp(unsigned int hp, unsigned int repair);

protected:
	std::string name_;
	unsigned int hit_point_;
	unsigned int energy_point_;
	unsigned int attack_damage_;

};
