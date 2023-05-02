#include "HumanA.hpp"

HumanA::~HumanA() {}

void HumanA::attack() {
	cout << COLOR_BLUE << name_ << " attacks with their " << weapon_.getType() << COLOR_RESET << endl;
}