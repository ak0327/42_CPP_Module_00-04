#include <iostream>
#include "DiamondTrap.hpp"

using namespace std;

int main() {
	{
		DiamondTrap diamond = DiamondTrap("Alpha"); diamond.printStatus();

		cout << endl;

		diamond.whoAmI();
		cout << endl;

		diamond.takeDamage(50);	diamond.printStatus();
		diamond.beRepaired(5); diamond.printStatus();
		diamond.takeDamage(50);	diamond.printStatus();
		diamond.takeDamage(150); diamond.printStatus();
		diamond.beRepaired(100); diamond.printStatus();
		diamond.takeDamage(100); diamond.printStatus();
		cout << "\n" << endl;
	}
	{
		DiamondTrap diamond = DiamondTrap("Beta"); diamond.printStatus();

		cout << endl;

		diamond.whoAmI();
		diamond.highFiveGuys();
		for (int i=0; i<99; i++) {
			diamond.beRepaired(10);
		}

		cout << endl;

		diamond.printStatus();
		diamond.beRepaired(5); diamond.printStatus();
		cout << "\n" << endl;
	}
	{
		DiamondTrap foo = DiamondTrap("Foo");
		DiamondTrap bar = DiamondTrap("Bar");
		cout << endl;

		foo.highFiveGuys();
		bar.guardGate();
		cout << endl;

		foo.whoAmI();
		bar.whoAmI();

		cout << endl;

		foo.printStatus();
		bar.beRepaired(5);
		bar.printStatus();

		cout << endl;

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		cout << endl;

		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		cout << endl;

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		cout << endl;

		bar.guardGate();
		bar.highFiveGuys();
		bar.attack_on(foo);
		cout << "\n" << endl;
	}
//	system("leaks a.out");
	return 0;
}