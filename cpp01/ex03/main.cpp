#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		std::cout << "\n---------- subject 1 ----------" << std::endl;

		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();

        std::cout << std::endl;

		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		std::cout << "\n---------- subject 2 ----------" << std::endl;

		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

        std::cout << std::endl;

		jim.setWeapon(club);
		jim.attack();

        std::cout << std::endl;

		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << "\n---------- test human B----------" << std::endl;

		HumanB humanB("humanB");
		humanB.attack();

        std::cout << std::endl;

		Weapon smile = Weapon("smile :)");
		humanB.setWeapon(smile);
		humanB.attack();

        std::cout << std::endl;

		smile.setType("sad ;-");
		std::cout << "gettype:" << smile.getType() << std::endl;
		humanB.getType();
		humanB.attack();
	}
	std::cout << std::endl;
	system("leaks -q a.out");
	return 0;
}
