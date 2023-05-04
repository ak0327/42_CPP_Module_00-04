#include <iostream>
#include "FragTrap.hpp"

using namespace std;

int main() {
	{
		FragTrap fragTrap = FragTrap("Alpha"); fragTrap.printStatus();

		fragTrap.attack("Beta"); fragTrap.printStatus();
		fragTrap.highFiveGuys();
		fragTrap.takeDamage(50);	fragTrap.printStatus();
		fragTrap.beRepaired(5); fragTrap.printStatus();
		fragTrap.takeDamage(50);	fragTrap.printStatus();
		fragTrap.takeDamage(150); fragTrap.printStatus();
		fragTrap.beRepaired(100); fragTrap.printStatus();
		fragTrap.attack("Omega");	fragTrap.printStatus();
		fragTrap.takeDamage(100); fragTrap.printStatus();
		fragTrap.highFiveGuys();
		cout << endl;
	}
	{
		FragTrap fragTrap = FragTrap("Beta"); fragTrap.printStatus();

		fragTrap.highFiveGuys();
		for (int i=0; i<99; i++) {
			fragTrap.beRepaired(10);
		}
		fragTrap.printStatus();
		fragTrap.highFiveGuys();
		fragTrap.beRepaired(5); fragTrap.printStatus();
		fragTrap.highFiveGuys();
		cout << endl;
	}
//	system("leaks a.out");
	return 0;
}