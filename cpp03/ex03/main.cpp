#include <iostream>
#include "DiamondTrap.hpp"


int main() {
	{
		DiamondTrap diamond = DiamondTrap("Alpha"); diamond.printStatus();

		std::cout << std::endl;

		diamond.whoAmI();
		std::cout << std::endl;

		diamond.takeDamage(50);	diamond.printStatus();
		diamond.beRepaired(5); diamond.printStatus();
		diamond.takeDamage(50);	diamond.printStatus();
		diamond.takeDamage(150); diamond.printStatus();
		diamond.beRepaired(100); diamond.printStatus();
		diamond.takeDamage(100); diamond.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		DiamondTrap diamond = DiamondTrap("Beta"); diamond.printStatus();

		std::cout << std::endl;

		diamond.whoAmI();
		diamond.highFiveGuys();
		for (int i=0; i<99; i++) {
			diamond.beRepaired(10);
		}

		std::cout << std::endl;

		diamond.printStatus();
		diamond.beRepaired(5); diamond.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		DiamondTrap foo = DiamondTrap("Foo");
		DiamondTrap bar = DiamondTrap("Bar");
		std::cout << std::endl;

		foo.highFiveGuys();
		bar.guardGate();
		std::cout << std::endl;

		foo.whoAmI();
		bar.whoAmI();

		std::cout << std::endl;

		foo.printStatus();
		bar.beRepaired(5);
		bar.printStatus();

		std::cout << std::endl;

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		bar.guardGate();
		bar.highFiveGuys();
		bar.attack_on(foo);
		std::cout << "\n" << std::endl;
	}
//	system("leaks a.out");
	return 0;
}