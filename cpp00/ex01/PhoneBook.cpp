#include "PhoneBook.hpp"
#include <math.h>
#include <limits>

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

PhoneBook::PhoneBook() {
	num_of_register = 0;
	std::cout << "phonebook create" << std::endl;
}

void PhoneBook::add() {
	int			register_idx;
	std::string	string_arr[NUM_OF_INPUT];
	const std::string item_str[NUM_OF_INPUT] = {"FIRST NAME  ",
										   "LAST NAME   ",
										   "NICKNAME    ",
										   "PHONE NUMBER",
										   "SECRET      "};
	std::cout << COLOR_BLUE"# ***** [ADD] Add new contact to phonebook *****"COLOR_RESET<< std::endl;
	for (int i=0; i<NUM_OF_INPUT; i++)
	{
		while (true)
		{
			std::cout << COLOR_BLUE"## " << item_str[i] << " : "COLOR_RESET << std::ends;
			if (!getline(std::cin, string_arr[i])) {
				std::cout << "input ^D, exit" << std::endl;
				exit(0) ;
			}
			string_arr[i] = trim(string_arr[i]);
			if (string_arr[i] == "EXIT") {
				std::cout << "# EXIT from ADD ..." << std::endl;
				return;
			}
			if (string_arr[i].empty())
			{
				std::cout << "[Error] : Can't have EMPTY" << std::endl;
				continue ;
			}
			if (i == PHONE_NUMBER_IDX && !is_str_digit(string_arr[i]))
			{
				std::cout << COLOR_YELLOW"## [ERROR] : Phone number required ONLY DIGIT"COLOR_RESET << std::endl;
				continue ;
			}
			break ;
		}
	}
	num_of_register++;
	register_idx = (num_of_register - 1) % MAXIMUM_SIZE;
	contact_arr[register_idx].SetData(string_arr[FIRST_NAME_IDX],
									string_arr[LAST_NAME_IDX],
									string_arr[NICKNAME_IDX],
									string_arr[PHONE_NUMBER_IDX],
									string_arr[SECRET_IDX]);
}



void PhoneBook::search() {
	std::string	index_str;

	std::cout << COLOR_MAGENTA"#"COLOR_RESET << std::endl;
	std::cout << COLOR_MAGENTA"# ***** [SEARCH] Search contact from phonebook *****"COLOR_RESET << std::endl;

	if (num_of_register == 0) {
		std::cout << COLOR_MAGENTA"# No contact registered"COLOR_RESET << std::endl;
		return ;
	}

	display();

	while (true)
	{
		std::cout << COLOR_MAGENTA"# Input index to display detail >> "COLOR_RESET << std::ends;
		if (!getline(std::cin, index_str)) {
			std::cout << "# ^D" << std::endl;
			return ;
		}
		if (index_str == "EXIT") {
			std::cout << COLOR_MAGENTA"# EXIT from SEARCH ..."COLOR_RESET << std::endl;
			return ;
		}
		if (detail_display_by_display_index(index_str) == SUCCESS)
			return ;
	}
}









/*
 1234567890 1234567890 1234567890 1234567890 1234567890
+ -------- + -------- + -------- + -------- + -------- +
|   Index  | FirstName| LastName | Nickname | PhoneNbr |
# ======== # ======== # ======== # ======== # ======== #
|1234567890|123456789.| 123456789|       123|         1|
+ -------- + -------- + -------- + -------- + -------- +

 */

//
// 0123456789
//

void PhoneBook::display() const {
	std::string	index_str;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	int		start_idx;
	int 	arr_idx;

	if (num_of_register == 0)
		return ;

	display_header();

	start_idx = (num_of_register < MAXIMUM_SIZE) ? 0 : (num_of_register - MAXIMUM_SIZE);
	for (int i=0; i<std::min(num_of_register, MAXIMUM_SIZE); i++) {
		arr_idx = (i + start_idx) % MAXIMUM_SIZE;
		std::cout << COLOR_CYAN" |" << std::ends;
		index_str = ft_to_string(i); //display_index != arr_idx
	std::cout << get_valid_width_string(index_str) << std::ends;
		std::cout << "|" << std::ends;
		first_name = contact_arr[arr_idx].get_first_name();
		std::cout << get_valid_width_string(first_name) << std::ends;
		std::cout << "|" << std::ends;
		last_name = contact_arr[arr_idx].get_last_name();
		std::cout << get_valid_width_string(last_name) << std::ends;
		std::cout << "|" << std::ends;
		nickname = contact_arr[arr_idx].get_nickname();
		std::cout << get_valid_width_string(nickname) << std::ends;
		std::cout << "|"COLOR_RESET << std::endl;

	}
	display_row_delim();

}

int PhoneBook::detail_display_by_display_index(const std::string &search_index) const {
	int	start_idx;
	int idx;

	if (num_of_register == 0)
		return (SUCCESS);

	start_idx = (num_of_register <= MAXIMUM_SIZE) ? 0 : (num_of_register - MAXIMUM_SIZE);
	for (int i=0; i<std::min(num_of_register, MAXIMUM_SIZE); i++) {
		idx = (i + start_idx) % MAXIMUM_SIZE;
		if (search_index == ft_to_string(i)) {
			contact_arr[idx].GetData();
			return (SUCCESS);
		}
	}
	std::cout << COLOR_RED"# Invalid index"COLOR_RESET << std::endl;
	return (FAILURE);
}

bool PhoneBook::is_str_digit(const std::string &str) const {
	for (size_t i=0; i<str.size(); i++) {
		if (!isdigit(str.at(i))) {
			return (false);
		}
	}
	return (true);
}

std::string PhoneBook::get_valid_width_string(const std::string &str) const {
	size_t	space_size;
	std::string	ret_str;

	space_size = str.size() >= 10 ? 0 : 10 - str.size();
	for (size_t i=0; i<space_size; i++) {
		ret_str += " ";
	}

	for (size_t i=0; i+space_size < 10; i++) {
		ret_str += str.at(i);
	}
	if (str.size() > 10) {
		ret_str.at(9) = '.';
	}
	return (ret_str);
}

void PhoneBook::display_row_delim() const {
	std::cout << COLOR_CYAN" + -------- + -------- + -------- + -------- +"COLOR_RESET << std::endl;
}

void	PhoneBook::display_header() const {
	std::cout << COLOR_CYAN" + -------- + -------- + -------- + -------- +"COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN" |   Index  | FirstName| LastName | Nickname |"COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN" # ======== # ======== # ======== # ======== #"COLOR_RESET << std::endl;
}

std::string PhoneBook::trim(std::string str) const {
	const std::string space = " ";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return (str);
}

std::string PhoneBook::ft_to_string(int num) const {
	std::string ret;
	std::string sign;

	if (num == 0) {
		return "0";
	}

	unsigned int un;
	if (num < 0) {
		sign = '-';
		un = -num;
	} else {
		un = num;
	}
	while (un) {
		ret = (char)(un % 10 + '0') + ret;
		un /= 10;
	}
	return sign + ret;
}













