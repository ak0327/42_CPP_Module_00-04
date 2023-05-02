#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();

		//setTypeをHuman.typeにも反映するため、&typeとする必要がある
		club.setType("some other type of club");
		bob.attack();
	}
	cout << endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		jim.setWeapon(club);
		jim.attack();

		club.setType("some other type of club");
		jim.attack();
	}
	cout << endl;
	{
		HumanB humanB("humanB");
		humanB.attack();

		Weapon smile = Weapon("smile :)");
		humanB.setWeapon(smile);
		humanB.attack();
		smile.setType("sad ;-");
		cout << "gettype:" << smile.getType() << endl;
		humanB.getType();
		humanB.attack();
	}
	cout << endl;
//	system("leaks a.out");
	return 0;
}