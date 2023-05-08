#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <limits>

int main() {
	{
		ScavTrap scavTrap = ScavTrap("Dog"); scavTrap.printStatus();

		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(150); scavTrap.printStatus();
		scavTrap.guardGate();

		// can't action
		scavTrap.beRepaired(100); scavTrap.printStatus();
		scavTrap.takeDamage(100); scavTrap.printStatus();
		std::cout << std::endl;
	}
	{
		ScavTrap scavTrap = ScavTrap("Lion"); scavTrap.printStatus();

		for (int i=0; i<50; i++) {
			scavTrap.beRepaired(5); scavTrap.printStatus();
		}
		scavTrap.guardGate();
		scavTrap.takeDamage(340); scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.takeDamage(10); scavTrap.printStatus();
		scavTrap.guardGate();
		scavTrap.beRepaired(100); scavTrap.printStatus();
		scavTrap.takeDamage(100); scavTrap.printStatus();
		std::cout << std::endl;
	}
	{
		ScavTrap foo = ScavTrap("Foo");
		ScavTrap bar = ScavTrap("Bar");
		foo.printStatus();
		bar.printStatus();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		bar.attack_on(foo);
		foo.printStatus();
		bar.printStatus();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		bar.attack_on(foo);
		std::cout << std::endl;
	}
	{
		ScavTrap foo = ScavTrap("Foo");
		ScavTrap bar = ScavTrap("Bar");
		foo.printStatus();
		foo.guardGate();
		bar.beRepaired(5);
		bar.printStatus();
		bar.guardGate();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		foo.attack_on(bar);
		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		bar.attack_on(foo);
		std::cout << std::endl;
	}
//	system("leaks a.out");
	return 0;
}