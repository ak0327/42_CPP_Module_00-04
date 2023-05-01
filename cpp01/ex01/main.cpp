#include "Zombie.hpp"

void test_zombie_horder(int N, string name, string chump) {
	try {
		cout << "\n=== [" << name << "] N = " << N << " construct ===" << endl;
		Zombie *zombies = zombieHorde(N, name);

		cout << "\n=== [" << name << "] announce ===" << endl;
		for (int i=0; i<N; i++) {
			zombies[i].announce();
		}

		cout << "\n=== [" << name << "] random Chump " << chump << " ===" << endl;
		for (int i=0; i<N; i++) {
			zombies[i].randomChump(chump);
		}

		cout << "\n=== [" << name << "] delete ===" << endl;
		delete[] zombies;

	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
}

int main() {
	string nameA = "zombiesA";
	string chumpA = "ABCDE";
	test_zombie_horder(5, nameA, chumpA);

	cout << "\n" <<  endl;

	string nameB = "zombiesB";
	string chumpB = "hoge";
	test_zombie_horder(0, nameB, chumpB);

	cout << "\n" <<  endl;

	string nameC = "zombiesC";
	string chumpC = "huga";
	test_zombie_horder(-3, nameC, chumpC);
}