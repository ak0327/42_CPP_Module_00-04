#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zombie {
public:
	Zombie(string name);
	~Zombie();

	void announce(void);

	void randomChump(string name);

private:
	string name_;
};

Zombie *newZombie(string name);