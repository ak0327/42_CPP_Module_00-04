#pragma once

#include "Weapon.hpp"
#include <iostream>
#include <string>

using namespace std;

// HumanA will always be armed.
class HumanA {
public:
	HumanA(string name, Weapon &weapon) : name_(name), weapon_(weapon) {
		cout << name << "(A) is armed with " << weapon.getType() << endl;
	};
	~HumanA();

	void attack();

private:
	string name_;
	Weapon &weapon_;

};