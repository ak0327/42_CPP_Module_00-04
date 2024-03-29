#pragma once

#include <iostream>
#include <string>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

class Weapon {
public:
	Weapon(std::string type);
	~Weapon();

	const std::string &getType();
	void setType(std::string newType);

private:
	// A private attribute type, which is a string.
	std::string type_;
};
