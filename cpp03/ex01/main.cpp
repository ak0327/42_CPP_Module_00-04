#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <limits>

int main() {
	{
		std::cout << "-------------------- test 1 : constructor --------------------" << std::endl;
		ScavTrap test1 = ScavTrap(); test1.printStatus();
		std::cout << std::endl;

		ScavTrap test2 = ScavTrap("test2"); test2.printStatus();
		std::cout << std::endl;

		ScavTrap test3 = ScavTrap(test2); test3.printStatus();
		std::cout << std::endl;

		ScavTrap test4; test4 = test1; test4.printStatus();
		std::cout << std::endl;

		test1.takeDamage(1);
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();
		std::cout << std::endl;

		test2.takeDamage(2);
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();
		std::cout << std::endl;

		test3.takeDamage(3);
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();
		std::cout << std::endl;

		test4.takeDamage(4);
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();
		std::cout << std::endl;

		std::cout << "\n" << std::endl;

	}
	{
		std::cout << "-------------------- test 2 : Dog unit test --------------------" << std::endl;
		ScavTrap scavTrap = ScavTrap("Dog"); scavTrap.printStatus();
		std::cout << std::endl;

		scavTrap.takeDamage(50);	scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.takeDamage(40);	scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.beRepaired(500); scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.takeDamage(85);	scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.takeDamage(10); scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.takeDamage(10); scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		// can't action
		scavTrap.attack("Target A");	scavTrap.printStatus();
		std::cout << std::endl;
		scavTrap.beRepaired(100); scavTrap.printStatus();
		std::cout << std::endl;
		scavTrap.takeDamage(100); scavTrap.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 3 : Lion unit test --------------------" << std::endl;
		ScavTrap scavTrap = ScavTrap("Lion"); scavTrap.printStatus();
		std::cout << std::endl;

		for (int i=0; i<50; i++) {
			scavTrap.beRepaired(5); scavTrap.printStatus();
			std::cout << std::endl;
		}
		scavTrap.guardGate();

		std::cout << std::endl;
		scavTrap.takeDamage(340); scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.takeDamage(10); scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;

		scavTrap.beRepaired(100); scavTrap.printStatus();
		scavTrap.takeDamage(100); scavTrap.printStatus();
		std::cout << "\n" << std::endl;
	}
//	{
//		std::cout << "-------------------- test 4 : guardGate test --------------------" << std::endl;
//		ScavTrap scavTrap = ScavTrap("Lion"); scavTrap.printStatus();
//		std::cout << std::endl;
//
//		for (int i=0; i<110; i++) {
//			scavTrap.takeDamage(1); scavTrap.printStatus();
//			scavTrap.guardGate();
//			std::cout << std::endl;
//		}
//		std::cout << "\n" << std::endl;
//	}
	{
		std::cout << "-------------------- test 5 : Foo vs Bar --------------------" << std::endl;
		ScavTrap foo = ScavTrap("Foo");
		ScavTrap bar = ScavTrap("Bar");
		std::cout << std::endl;

		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		for (int i=0; i<6; i++) {
			foo.attack_on(bar);

			foo.printStatus();
			bar.printStatus();

			std::cout << std::endl;


			bar.attack_on(foo);

			foo.printStatus();
			bar.printStatus();

			std::cout << std::endl;
		}

		bar.beRepaired(1);
		foo.printStatus();
		bar.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 6 : Foo vs Bar --------------------" << std::endl;

		ScavTrap foo = ScavTrap("Foo");
		ScavTrap bar = ScavTrap("Bar");

		std::cout << std::endl;

		bar.beRepaired(5);
		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		std::cout << std::endl;
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);

		std::cout << std::endl;

		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		std::cout << std::endl;

		bar.beRepaired(10);
		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		std::cout << std::endl;

		foo.attack_on(bar);

		std::cout << std::endl;

		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		std::cout << std::endl;
		foo.attack_on(bar);
		foo.attack_on(bar);

		std::cout << std::endl;

		foo.printStatus();
		foo.guardGate();
		bar.printStatus();
		bar.guardGate();

		std::cout << std::endl;
		bar.attack_on(foo);
		std::cout << "\n" << std::endl;
	}
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
