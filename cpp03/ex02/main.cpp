#include <iostream>
#include "FragTrap.hpp"

int main() {
	{
		std::cout << "-------------------- test 1 : constructor --------------------" << std::endl;
		FragTrap test1 = FragTrap(); test1.printStatus();
		std::cout << std::endl;

		FragTrap test2 = FragTrap("test2"); test2.printStatus();
		std::cout << std::endl;

		FragTrap test3 = FragTrap(test2); test3.printStatus();
		std::cout << std::endl;

		FragTrap test4; test4 = test1; test4.printStatus();
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


		test1.set_name("AAAAA");
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();

		std::cout << std::endl;

		test2.set_name("BBBBB");
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();

		std::cout << std::endl;

		test3.set_name("CCCCC");
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();

		std::cout << std::endl;

		test4.set_name("DDDDD");
		test1.printStatus();
		test2.printStatus();
		test3.printStatus();
		test4.printStatus();

		std::cout << "\n" << std::endl;

	}
	{
		std::cout << "-------------------- test 2 :  --------------------" << std::endl;
		FragTrap fragTrap = FragTrap("Alpha"); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.highFiveGuys();
		fragTrap.takeDamage(50);	fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.beRepaired(5); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.beRepaired(500); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.takeDamage(50);	fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.takeDamage(150); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.beRepaired(100); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.takeDamage(100); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.highFiveGuys();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 3 :  --------------------" << std::endl;
		FragTrap fragTrap = FragTrap("Beta"); fragTrap.printStatus();
		std::cout << std::endl;

		fragTrap.highFiveGuys();
		for (int i=0; i<99; i++) {
			fragTrap.beRepaired(10);
		}
		std::cout << std::endl;
		fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.highFiveGuys();
		std::cout << std::endl;
		fragTrap.beRepaired(5); fragTrap.printStatus();
		std::cout << std::endl;
		fragTrap.highFiveGuys();
		std::cout << "\n" << std::endl;
	}
	std::cout << "-------------------- test 4 : Foo vs Bar --------------------" << std::endl;
	{
		FragTrap foo = FragTrap("Foo");
		FragTrap bar = FragTrap("Bar");
		std::cout << std::endl;

		foo.printStatus();
		foo.highFiveGuys();

		std::cout << std::endl;

		bar.beRepaired(5);
		bar.printStatus();
		bar.highFiveGuys();

		std::cout << std::endl;
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);
		foo.attack_on(bar);

		std::cout << std::endl;

		foo.printStatus();
		foo.highFiveGuys();
		bar.printStatus();
		bar.highFiveGuys();

		std::cout << "\n" << std::endl;
	}
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
