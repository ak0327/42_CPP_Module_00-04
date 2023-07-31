#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

int main() {
	{
		std::cout << "-------------------- test 1 : constructor --------------------" << std::endl;
		ClapTrap test1 = ClapTrap(); test1.printStatus();
		std::cout << std::endl;

		ClapTrap test2 = ClapTrap("test2"); test2.printStatus();
		std::cout << std::endl;

		ClapTrap test3 = ClapTrap(test2); test3.printStatus();
		std::cout << std::endl;

		ClapTrap test4; test4 = test1; test4.printStatus();
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
		std::cout << "-------------------- test 2 : HP 10->0 --------------------" << std::endl;
		ClapTrap clapTrap = ClapTrap("Hoge");
		std::cout << std::endl;

		clapTrap.printStatus();

		clapTrap.takeDamage(5);	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.beRepaired(5);	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.takeDamage(15);	clapTrap.printStatus();
		std::cout << std::endl;

		// can't action
		clapTrap.beRepaired(5);	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.attack("Target A");	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.takeDamage(15);	clapTrap.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 3 : HP 10->0 --------------------" << std::endl;
		ClapTrap clapTrap = ClapTrap("Huga");
		std::cout << std::endl;

		clapTrap.printStatus();

		std::cout << std::endl;
		for (int i=0; i<15; i++) {
			clapTrap.takeDamage(1);	clapTrap.printStatus();
			std::cout << std::endl;
		}

		// can't action
		clapTrap.beRepaired(5);	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.attack("Target A");	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.takeDamage(15);	clapTrap.printStatus();

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 4 : EP 10->0 --------------------" << std::endl;

		ClapTrap clapTrap = ClapTrap("Piyo");
		std::cout << std::endl;
		clapTrap.printStatus();

//		std::cout << std::endl;
//		clapTrap.takeDamage(201);	clapTrap.printStatus();

		std::cout << std::endl;
		for (int i=0; i<11; i++) {
			clapTrap.beRepaired(100); clapTrap.printStatus();
			std::cout << std::endl;
		}

		clapTrap.attack("Target A");	clapTrap.printStatus();
		std::cout << std::endl;

		clapTrap.takeDamage(100);	clapTrap.printStatus();
		std::cout << std::endl;

		clapTrap.beRepaired(100); clapTrap.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 5 : take big damage --------------------" << std::endl;

		ClapTrap clapTrap = ClapTrap("Foo");
		std::cout << std::endl;
		clapTrap.printStatus();

		std::cout << std::endl;
		clapTrap.beRepaired(UINT_MAX); clapTrap.printStatus();
		std::cout << std::endl;

		for (int i=0; i<6; i++) {
			clapTrap.takeDamage(UINT_MAX); clapTrap.printStatus();
			std::cout << std::endl;
		}

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 6 : take 0 damage --------------------" << std::endl;

		ClapTrap clapTrap = ClapTrap("Huga");
		std::cout << std::endl;
		clapTrap.printStatus();

		std::cout << std::endl;

		for (int i=0; i<10; i++) {
			clapTrap.takeDamage(0);	clapTrap.printStatus();
			std::cout << std::endl;
		}

		clapTrap.beRepaired(100); clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.takeDamage(1000);	clapTrap.printStatus();
		std::cout << std::endl;
		clapTrap.beRepaired(100); clapTrap.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 7 : repaired 0 --------------------" << std::endl;

		ClapTrap clapTrap = ClapTrap("Huga");
		std::cout << std::endl;
		clapTrap.printStatus();

		std::cout << std::endl;
		for (int i=0; i<10; i++) {
			clapTrap.beRepaired(0); clapTrap.printStatus();
			std::cout << std::endl;
		}

		clapTrap.attack("Piyo");	clapTrap.printStatus();
		std::cout << std::endl;

		clapTrap.beRepaired(0); clapTrap.printStatus();
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "-------------------- test 8 : Foo vs Bar --------------------" << std::endl;

		ClapTrap foo = ClapTrap("Foo");
		ClapTrap bar = ClapTrap("Bar");
		std::cout << std::endl;

		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

		bar.attack_on(foo);
		foo.printStatus();
		bar.printStatus();

		std::cout << std::endl;

//		foo.attack_on(bar);
		bar.takeDamage(100); // tmp
		foo.printStatus();
		bar.printStatus();
		std::cout << std::endl;

		bar.attack_on(foo);
		foo.printStatus();
		bar.printStatus();
		std::cout << std::endl;

		foo.beRepaired(1);
		foo.printStatus();
		bar.printStatus();
		std::cout << std::endl;

		bar.beRepaired(1);
		foo.printStatus();
		bar.printStatus();
		std::cout << std::endl;
	}
	return 0;
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}
