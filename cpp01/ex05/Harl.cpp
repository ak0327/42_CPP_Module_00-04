#include "Harl.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

#define MSG_DEBUG		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
#define MSG_INFO		"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define MSG_WARNING		"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define MSG_ERROR		"This is unacceptable! I want to speak to the manager now."

Harl::Harl() {
	complains_[DEBUG_IDX] = &Harl::debug;
	complains_[INFO_IDX] = &Harl::info;
	complains_[WARNING_IDX] = &Harl::warning;
	complains_[ERROR_IDX] = &Harl::error;

	levels[DEBUG_IDX] = "DEBUG";
	levels[INFO_IDX] = "INFO";
	levels[WARNING_IDX] = "WARNING";
	levels[ERROR_IDX] = "ERROR";
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << COLOR_GREEN << MSG_DEBUG << COLOR_RESET << std::endl;
}

void Harl::info() {
	std::cout << COLOR_YELLOW << MSG_INFO << COLOR_RESET << std::endl;
}

void Harl::warning() {
	std::cout << COLOR_BLUE << MSG_WARNING << COLOR_RESET << std::endl;
}

void Harl::error() {
	std::cout << COLOR_MAGENTA << MSG_ERROR << COLOR_RESET << std::endl;
}

void Harl::complain(std::string level) {
	for (int i=0; i<SIZE_OF_COMPLAINS; i++) {
		if (level == levels[i]) {
			(this->*complains_[i])();
			return ;
		}
	}
	throw std::invalid_argument("[Error] Invalid argument. Input following Levels:"
						   " DEBUG / INFO / WARNING / ERROR");
}
