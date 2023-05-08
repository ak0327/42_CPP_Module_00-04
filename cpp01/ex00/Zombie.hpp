#pragma once
#include <iostream>
#include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie();

	void announce(void);

	void randomChump(std::string name);

private:
	std::string name_;
};

Zombie *newZombie(std::string name);
