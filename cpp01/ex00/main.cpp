#include "Zombie.hpp"

int main() {
	string nameA = "zombieA";
	string nameB = "zombieB";
	string nameC = "zombieC";
	string nameD = "zombieD";

	cout << "\n=== [zombie A] construct ===" << endl;
	Zombie zombieA = Zombie(nameA);

	zombieA.announce();

	cout << "\n=== [zombieA] random Chump \"zombieB\" ===" << endl;
	zombieA.randomChump(nameB);

//	cout << "\n=== [zombieA] destroy ===" << endl;
//	zombieA.~Zombie();

	cout << endl;

	cout << "\n=== [zombieC] create by newZombie ===" << endl;
	Zombie *zombieC = newZombie(nameC);
	cout << "\n=== [zombieC] announce ===" << endl;
	zombieC->announce();
	cout << "\n=== [zombieC] random Chymp \"zombieD\" ===" << endl;
	zombieC->randomChump(nameD);
	cout << "\n=== [zombieC] delete ===" << endl;
	delete zombieC;

//	system("leaks a.out");
}