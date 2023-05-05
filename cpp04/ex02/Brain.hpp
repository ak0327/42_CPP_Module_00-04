#pragma once
#include <iostream>
#include <string>

#define IDEAS_SIZE 100

using namespace std;

class Brain {
public:
	Brain();
	Brain(const Brain &brain);
	~Brain();
	Brain &operator=(const Brain &brain);

private:
	string ideas_[IDEAS_SIZE];

};