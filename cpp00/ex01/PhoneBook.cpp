#include "PhoneBook.hpp"

static bool is_str_digit(const string &str);
static void	display_header();
static void display_row_delim();
static string get_valid_width_string(const string &str);
static string trim(string str);

PhoneBook::PhoneBook() {
	num_of_register = 0;
	cout << "phonebook create" << endl;
}

void PhoneBook::add() {
	int		register_idx;
	string	string_arr[NUM_OF_INPUT];
	const string item_str[NUM_OF_INPUT] = {"FIRST NAME  ",
										   "LAST NAME   ",
										   "NICKNAME    ",
										   "PHONE NUMBER",
										   "SECRET      "};
	cout << "# ***** [ADD] Add new contact to phonebook *****" << endl;
	for (int i=0; i<NUM_OF_INPUT; i++)
	{
		while (true)
		{
			cout << "## " << item_str[i] << " : " << ends;
			if (!getline(cin, string_arr[i])) {
				cout << "^D" << endl;
				exit (0);
			}
			string_arr[i] = trim(string_arr[i]);
			if (string_arr[i] == "EXIT") {
				cout << "# EXIT from ADD ..." << endl;
				return;
			}
			if (string_arr[i].empty())
			{
				cout << "[Error] : Can't have EMPTY" << endl;
				continue ;
			}
			if (i == PHONE_NUMBER_IDX && !is_str_digit(string_arr[i]))
			{
				cout << "## [ERROR] : Phone number required ONLY DIGIT" << endl;
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

void PhoneBook::display() {
	string	index_str;
	string	first_name;
	string	last_name;
	string	nickname;
	int		start_idx;
	int 	arr_idx;

	if (num_of_register == 0)
		return ;

	display_header();

	start_idx = (num_of_register < MAXIMUM_SIZE) ? 0 : (num_of_register - MAXIMUM_SIZE);
	for (int i=0; i<min(num_of_register, MAXIMUM_SIZE); i++) {
		arr_idx = (i + start_idx) % MAXIMUM_SIZE;
		cout << " |" << ends;
		index_str = to_string(i); //display_index != arr_idx
		cout << get_valid_width_string(index_str) << ends;
		cout << "|" << ends;
		first_name = contact_arr[arr_idx].get_first_name();
		cout << get_valid_width_string(first_name) << ends;
		cout << "|" << ends;
		last_name = contact_arr[arr_idx].get_last_name();
		cout << get_valid_width_string(last_name) << ends;
		cout << "|" << ends;
		nickname = contact_arr[arr_idx].get_nickname();
		cout << get_valid_width_string(nickname) << ends;
		cout << "|" << endl;

		display_row_delim();
	}

}

void PhoneBook::search() {
	string	index_str;

	cout << "#" << endl;
	cout << "# ***** [SEARCH] Search contact from phonebook *****" << endl;

	if (num_of_register == 0) {
		cout << "# No contact registered" << endl;
		return ;
	}

	display();

	while (true)
	{
		cout << "# Input index to display detail >> " << ends;
		if (!getline(cin, index_str)) {
			cout << "# ^D" << endl;
			return ;
		}
		if (index_str == "EXIT") {
			cout << "# EXIT from SEARCH ..." << endl;
			return ;
		}
		if (detail_display_by_display_index(index_str) == SUCCESS)
			return ;
	}
}

int PhoneBook::detail_display_by_display_index(const string &search_index) {
	int	start_idx;
	int idx;

	if (num_of_register == 0)
		return (SUCCESS);

	start_idx = (num_of_register <= MAXIMUM_SIZE) ? 0 : (num_of_register - MAXIMUM_SIZE);
	for (int i=0; i<min(num_of_register, MAXIMUM_SIZE); i++) {
		idx = (i + start_idx) % MAXIMUM_SIZE;
		if (search_index == to_string(i)) {
			contact_arr[idx].GetData();
			return (SUCCESS);
		}
	}
	cout << "# Invalid index" << endl;
	return (FAILURE);
}

static bool is_str_digit(const string &str) {
	for (size_t i=0; i<str.size(); i++) {
		if (!isdigit(str.at(i))) {
			return (false);
		}
	}
	return (true);
}

static string get_valid_width_string(const string &str) {
	size_t	space_size;
	string	ret_str;

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

static void display_row_delim() {
	cout << " + -------- + -------- + -------- + -------- +" << endl;
}

static void	display_header() {
	cout << " + -------- + -------- + -------- + -------- +" << endl;
	cout << " |   Index  | FirstName| LastName | Nickname |" << endl;
	cout << " # ======== # ======== # ======== # ======== #" << endl;
}

static string trim(string str) {
	const string space = " ";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return (str);
}