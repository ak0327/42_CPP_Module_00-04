#pragma once
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <utility> // pair, make_pair

#include "Contact.hpp"

#define	MAXIMUM_SIZE		8
#define NUM_OF_INPUT		5
#define FIRST_NAME_IDX		0
#define LAST_NAME_IDX		1
#define NICKNAME_IDX		2
#define PHONE_NUMBER_IDX	3
#define SECRET_IDX			4

#define SUCCESS	0
#define FAILURE 1

class PhoneBook {
public:
	// accessor
	PhoneBook();

	void add();
	void search();

private:
	// variable
	Contact contact_arr[MAXIMUM_SIZE];
	int		num_of_register;

	void display() const;
	int	detail_display_by_display_index(const std::string &search_index) const;
	std::string ft_to_string(int num) const;
	bool is_str_digit(const std::string &str) const;
	void display_header() const;
	void display_row_delim() const;
	std::string get_valid_width_string(const std::string &str) const;
	std::string trim(std::string str) const;
};
