#pragma once
#include <iostream>

class Zombie {
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce();
	void randomChump(std::string name);

private:
	std::string name_;

};

Zombie *zombieHorde(int N, std::string name);