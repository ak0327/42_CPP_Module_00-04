#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {
	{
		ScavTrap scavTrap = ScavTrap("Dog"); scavTrap.printStatus();

		scavTrap.attack("Cat"); scavTrap.printStatus();
		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.beRepaired(5); scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(150); scavTrap.printStatus();
		scavTrap.guardGate();

		// can't action
		scavTrap.beRepaired(100); scavTrap.printStatus();
		scavTrap.attack("Human");	scavTrap.printStatus();
		scavTrap.takeDamage(100); scavTrap.printStatus();
		cout << endl;
	}
	{
		ScavTrap scavTrap = ScavTrap("Lion"); scavTrap.printStatus();

		scavTrap.attack("Tiger"); scavTrap.printStatus();
		for (int i=0; i<50; i++) {
			scavTrap.beRepaired(5); scavTrap.printStatus();
		}
		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(150); scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.beRepaired(100); scavTrap.printStatus();
		scavTrap.attack("Human");	scavTrap.printStatus();
		scavTrap.takeDamage(100); scavTrap.printStatus();
		cout << endl;
	}
//	system("leaks a.out");
	return 0;
}