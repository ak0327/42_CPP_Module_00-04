#include "Zombie.hpp"

int main() {
	{
		std::string nameA = "zombieA";
		std::string nameB = "zombieB";
		std::cout << "\n=== [zombie A] construct ===" << std::endl;
		Zombie zombieA = Zombie(nameA);

		zombieA.announce();

		std::cout << "\n=== [zombieA] random Chump \"zombieB\" ===" << std::endl;
		zombieA.randomChump(nameB);

		std::cout << "\n=== [zombieA] destroy ===" << std::endl;
	}
	{
		std::string nameC = "zombieC";
		std::string nameD = "zombieD";

		std::cout << "\n=== [zombieC] create by newZombie ===" << std::endl;
		Zombie *zombieC = newZombie(nameC);

		std::cout << "\n=== [zombieC] announce ===" << std::endl;
		zombieC->announce();

		std::cout << "\n=== [zombieC] random Chump \"zombieD\" ===" << std::endl;
		zombieC->randomChump(nameD);

		std::cout << "\n=== [zombieC] delete ===" << std::endl;
		delete zombieC;
		std::cout << std::endl;

	}
	system("leaks -q a.out");
}
