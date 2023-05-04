#include <iostream>
#include "DiamondTrap.hpp"

using namespace std;

int main() {
	{
		DiamondTrap diamond = DiamondTrap("Alpha"); diamond.printStatus();

		diamond.takeDamage(50);	diamond.printStatus();
		diamond.beRepaired(5); diamond.printStatus();
		diamond.takeDamage(50);	diamond.printStatus();
		diamond.takeDamage(150); diamond.printStatus();
		diamond.beRepaired(100); diamond.printStatus();
		diamond.takeDamage(100); diamond.printStatus();
		cout << endl;
	}
	{
		DiamondTrap diamond = DiamondTrap("Beta"); diamond.printStatus();

		diamond.highFiveGuys();
		for (int i=0; i<99; i++) {
			diamond.beRepaired(10);
		}
		diamond.printStatus();
		diamond.beRepaired(5); diamond.printStatus();
		cout << endl;
	}
	{
		DiamondTrap foo = DiamondTrap("Foo");
		DiamondTrap bar = DiamondTrap("Bar");
		foo.printStatus();
		bar.beRepaired(5);
		bar.printStatus();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		bar.attack_on(foo);
		cout << endl;
	}
//	system("leaks a.out");
	return 0;
}