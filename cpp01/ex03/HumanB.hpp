#pragma once

#include "Weapon.hpp"
#include <iostream>
#include <string>

using namespace std;

// HumanB may not always have a Weapon,
class HumanB {
public:
	HumanB(string name) : name_(name), weapon_(NULL) {
		cout << name << "(B) has no weapon..." << endl;
	};
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);

	void getType();

private:
	string name_;
	Weapon *weapon_;
};