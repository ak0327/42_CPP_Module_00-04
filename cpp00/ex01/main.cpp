#include <iostream> // cout, endl, cin

#include "PhoneBook.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

int main() {
	std::string input_cmd;
	PhoneBook phonebook;

	std::cout << COLOR_GREEN "############ PHONE  BOOK ###########" COLOR_RESET << std::endl;
	while (true)
	{
		std::cout << COLOR_GREEN "### command: ADD / SEARCH / EXIT ###" COLOR_RESET << std::endl;
		std::cout << COLOR_GREEN "# Input Command >> " COLOR_RESET << std::ends;

		if (!getline(std::cin, input_cmd)) {
			std::cout << "# input ^D, exit" << std::endl;
			return 0;
		}
		if (input_cmd == "ADD") {
			phonebook.add();
		} else if (input_cmd == "SEARCH") {
			phonebook.search();
		} else if (input_cmd == "EXIT") {
			std::cout << "# BYE :)" << std::endl;
			break ;
		} else {
			std::cout << COLOR_RED "# [Error] Invalid command" COLOR_RESET << std::endl;
		}
		std::cout << COLOR_GREEN "#" COLOR_RESET << std::endl;
	}
//	system("leaks phonebook");
	return 0;
}
