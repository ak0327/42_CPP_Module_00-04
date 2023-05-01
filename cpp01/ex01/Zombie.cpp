#include "Zombie.hpp"

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

Zombie::Zombie() {
	name_ = "";
}

Zombie::Zombie(string name) {
	name_ = name;
	cout << COLOR_BLUE << name_ << " created" << COLOR_RESET << endl;
}

Zombie::~Zombie() {
	cout << COLOR_GREEN << name_ << " destroyed..." << COLOR_RESET << endl;
}

void Zombie::announce() {
	cout << COLOR_RED << name_ << ": BraiiiiiiinnnzzzZ..." << COLOR_RESET << endl;
}

void Zombie::randomChump(string name) {
	Zombie newZombie = Zombie(name);
	newZombie.announce();
}

Zombie *zombieHorde(int N, string name) {
	if (N <= 0) {
		throw invalid_argument("[Error] invalid argument: N <= 0\n");
	}
	Zombie *zombies = new Zombie[N];
	for (int i=0; i<N; i++) {
		zombies[i] = Zombie(name); //デフォルトコンストラクタを上書き->デストラクタが呼ばれる
	}
	return (zombies);
}
