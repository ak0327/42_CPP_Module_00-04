#pragma once
#include <iostream>

using namespace std;

class Zombie {
public:
//	Zombie(string name) : name_(name) {}
	Zombie();
	Zombie(string name);
	~Zombie();

	void announce();
	void randomChump(string name);

private:
	string name_;

};

Zombie *zombieHorde(int N, string name);