#include <iostream>
#include "FragTrap.hpp"

int main() {
	{
		FragTrap fragTrap = FragTrap("Alpha"); fragTrap.printStatus();

		fragTrap.highFiveGuys();
		fragTrap.takeDamage(50);	fragTrap.printStatus();
		fragTrap.beRepaired(5); fragTrap.printStatus();
		fragTrap.takeDamage(50);	fragTrap.printStatus();
		fragTrap.takeDamage(150); fragTrap.printStatus();
		fragTrap.beRepaired(100); fragTrap.printStatus();
		fragTrap.takeDamage(100); fragTrap.printStatus();
		fragTrap.highFiveGuys();
		std::cout << std::endl;
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
		std::cout << std::endl;
	}
	{
		FragTrap foo = FragTrap("Foo");
		FragTrap bar = FragTrap("Bar");
		foo.printStatus();
		foo.highFiveGuys();
		bar.beRepaired(5);
		bar.printStatus();
		bar.highFiveGuys();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		foo.highFiveGuys();
		bar.printStatus();
		bar.highFiveGuys();

		foo.attack_on(bar);
		foo.printStatus();
		foo.highFiveGuys();
		bar.printStatus();
		bar.highFiveGuys();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		foo.highFiveGuys();
		bar.printStatus();
		bar.highFiveGuys();

		bar.attack_on(foo);
		std::cout << std::endl;
	}
//	system("leaks a.out");
	return 0;
}