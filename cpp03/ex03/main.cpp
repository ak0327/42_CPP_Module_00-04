#include <iostream>
#include "DiamondTrap.hpp"


int main() {
	{
		std::cout << "-------------------- test 1 : constructor --------------------" << std::endl;
		DiamondTrap test1 = DiamondTrap(); test1.printStatus();
		std::cout << std::endl;

		DiamondTrap test2 = DiamondTrap("test2"); test2.printStatus();
		std::cout << std::endl;

		DiamondTrap test3 = DiamondTrap(test2); test3.printStatus();
		std::cout << std::endl;

		DiamondTrap test4; test4 = test1; test4.printStatus();
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
		std::cout << "-------------------- test 2 :  --------------------" << std::endl;
		DiamondTrap diamond = DiamondTrap("Alpha"); diamond.printStatus();

		std::cout << std::endl;

		diamond.whoAmI();
		std::cout << std::endl;

		diamond.attack("Target A");
		std::cout << std::endl;

		diamond.takeDamage(50);	diamond.printStatus();
		std::cout << std::endl;
		diamond.beRepaired(500); diamond.printStatus();
		std::cout << std::endl;
		diamond.takeDamage(50);	diamond.printStatus();
		std::cout << std::endl;
		diamond.takeDamage(150); diamond.printStatus();
		std::cout << std::endl;
		diamond.beRepaired(100); diamond.printStatus();
		std::cout << std::endl;
		diamond.takeDamage(100); diamond.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 3 :  --------------------" << std::endl;
		DiamondTrap diamond = DiamondTrap("Beta"); diamond.printStatus();

		std::cout << std::endl;

		diamond.whoAmI();
		diamond.highFiveGuys();
		for (int i=0; i<51; i++) {
			diamond.beRepaired(10);
		}

		std::cout << std::endl;

		diamond.printStatus();
		std::cout << std::endl;
		diamond.beRepaired(5); diamond.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 4 :  --------------------" << std::endl;
		DiamondTrap diamond = DiamondTrap("Gamma"); diamond.printStatus();

		std::cout << std::endl;

		diamond.whoAmI();
		diamond.highFiveGuys();
		diamond.guardGate();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 5 : Foo vs Bar --------------------" << std::endl;

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
		std::cout << std::endl;

		foo.printStatus();
		bar.printStatus();
		std::cout << std::endl;

		bar.attack_on(foo);
		std::cout << std::endl;

		foo.printStatus();
		bar.printStatus();
		std::cout << std::endl;

		foo.attack_on(bar);
		std::cout << std::endl;
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		foo.attack_on(bar);
		std::cout << std::endl;
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		foo.attack_on(bar);
		foo.attack_on(bar);
		std::cout << std::endl;
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		bar.guardGate();
		bar.highFiveGuys();
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
