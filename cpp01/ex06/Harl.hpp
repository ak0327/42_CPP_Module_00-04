#pragma once

#include <iostream>
#include <string>

#define SIZE_OF_COMPLAINS	4
#define DEBUG_IDX			0
#define INFO_IDX			1
#define WARNING_IDX			2
#define ERROR_IDX			3


class Harl {
public:
	Harl();
	~Harl();

	void filter(std::string level);

	typedef void (Harl::*funcPtr)();

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	std::string levels[SIZE_OF_COMPLAINS];
	funcPtr complains_[SIZE_OF_COMPLAINS];
};


