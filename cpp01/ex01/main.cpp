#include "Zombie.hpp"

void test_zombie_horder(int N, std::string name, std::string chump) {
	try {
		std::cout << "=== [" << name << "] N = " << N << " construct ===" << std::endl;
		Zombie *zombies = zombieHorde(N, name);

		std::cout << "\n=== [" << name << "] announce ===" << std::endl;
		for (int i=0; i<N; i++) {
			zombies[i].announce();
		}

		std::cout << "\n=== [" << name << "] random Chump " << chump << " ===" << std::endl;
		for (int i=0; i<N; i++) {
			zombies[i].randomChump(chump);
		}

		std::cout << "\n=== [" << name << "] delete ===" << std::endl;
		delete[] zombies;

	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	std::cout << "[n=5]" << std::endl;
	std::string nameA = "zombiesA";
	std::string chumpA = "chumpA";
	test_zombie_horder(5, nameA, chumpA);

	std::cout << "\n" <<  std::endl;
	std::cout << "[n=0]" << std::endl;
	std::string nameB = "zombiesB";
	std::string chumpB = "hoge";
	test_zombie_horder(0, nameB, chumpB);

	std::cout << "\n" <<  std::endl;
	std::cout << "[n=-3]" << std::endl;
	std::string nameC = "zombiesC";
	std::string chumpC = "huga";
	test_zombie_horder(-3, nameC, chumpC);

    std::cout << std::endl;
	system("leaks -q a.out");
	return 0;
}
