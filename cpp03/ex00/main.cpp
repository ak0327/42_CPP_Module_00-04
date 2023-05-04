#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {
	{
		ClapTrap clapTrap = ClapTrap("Hoge");
		clapTrap.printStatus();

		clapTrap.attack("huga"); clapTrap.printStatus();
		clapTrap.attack("huga");	clapTrap.printStatus();
		clapTrap.takeDamage(5);	clapTrap.printStatus();
		clapTrap.beRepaired(5);	clapTrap.printStatus();
		clapTrap.takeDamage(15);	clapTrap.printStatus();

		// can't action
		clapTrap.beRepaired(5);	clapTrap.printStatus();
		clapTrap.attack("huga");	clapTrap.printStatus();
		clapTrap.takeDamage(15);	clapTrap.printStatus();
		cout << endl;
	}
	{
		ClapTrap clapTrap = ClapTrap("Huga");
		clapTrap.printStatus();

		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		clapTrap.takeDamage(1);	clapTrap.printStatus();
		cout << endl;
	}
	{
		ClapTrap clapTrap = ClapTrap("Piyo");
		clapTrap.printStatus();

		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();

		clapTrap.takeDamage(100);	clapTrap.printStatus();
		clapTrap.attack("hoge");	clapTrap.printStatus();
		cout << endl;
	}
	{
		ClapTrap clapTrap = ClapTrap("Foo");
		clapTrap.printStatus();
		clapTrap.beRepaired(UINT_MAX - 11); clapTrap.printStatus();
		clapTrap.beRepaired(1); clapTrap.printStatus();
		clapTrap.beRepaired(1); clapTrap.printStatus();
		clapTrap.beRepaired(1); clapTrap.printStatus();
		clapTrap.beRepaired(1); clapTrap.printStatus();
		clapTrap.beRepaired(1); clapTrap.printStatus();
		clapTrap.beRepaired(1); clapTrap.printStatus();
		clapTrap.takeDamage(UINT_MAX);	clapTrap.printStatus();
		cout << endl;
	}
	{
		ClapTrap clapTrap = ClapTrap("Huga");
		clapTrap.printStatus();

		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.takeDamage(0);	clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.attack("hoge");	clapTrap.printStatus();
		clapTrap.takeDamage(1000);	clapTrap.printStatus();
		clapTrap.beRepaired(100); clapTrap.printStatus();
		clapTrap.attack("hoge");	clapTrap.printStatus();
		cout << endl;
	}
	{
		ClapTrap clapTrap = ClapTrap("Huga");
		clapTrap.printStatus();

		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.beRepaired(0); clapTrap.printStatus();
		clapTrap.takeDamage(10);	clapTrap.printStatus();
		clapTrap.attack("hoge");	clapTrap.printStatus();
		cout << endl;
	}
	{
		ClapTrap foo = ClapTrap("Foo");
		ClapTrap bar = ClapTrap("Bar");
		foo.printStatus();
		bar.printStatus();

		foo.attack_on(bar);
		foo.printStatus();
		bar.printStatus();

		bar.attack_on(foo);
		foo.printStatus();
		bar.printStatus();

		foo.takeDamage(100);
		bar.attack_on(foo);
		foo.printStatus();
		bar.printStatus();
	}

	//	system("leaks a.out");
	return 0;
}