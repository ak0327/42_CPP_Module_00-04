#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		std::cout << "\nsubject 1" << std::endl;

		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();

		//setTypeをHuman.typeにも反映するため、&typeとする必要がある
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		std::cout << "\nsubject 2" << std::endl;

		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		jim.setWeapon(club);
		jim.attack();

		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl;
	{
		std::cout << "\ntest" << std::endl;

		HumanB humanB("humanB");
		humanB.attack();

		Weapon smile = Weapon("smile :)");
		humanB.setWeapon(smile);
		humanB.attack();
		smile.setType("sad ;-");
		std::cout << "gettype:" << smile.getType() << std::endl;
		humanB.getType();
		humanB.attack();
	}
	std::cout << std::endl;
//	system("leaks a.out");
	return 0;
}