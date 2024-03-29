#include "Zombie.hpp"

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"


Zombie::Zombie(std::string name) {
	name_ = name;
	std::cout << COLOR_BLUE << name_ << " created" << COLOR_RESET << std::endl;
}

Zombie::~Zombie() {
	std::cout << COLOR_GREEN << name_ << " destroyed...\n" << COLOR_RESET << std::endl;
}

void Zombie::announce() {
	std::cout << COLOR_RED << name_ << ": BraiiiiiiinnnzzzZ..." << COLOR_RESET << std::endl;
}

void Zombie::randomChump(std::string name) {
	Zombie newZombie = Zombie(name);
	newZombie.announce();
}

Zombie *newZombie(std::string name) {
	return (new Zombie(name));
}
