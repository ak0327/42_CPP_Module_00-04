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
	void display();
	int	detail_display_by_display_index(const string &search_index);

private:
	// variable
	Contact contact_arr[MAXIMUM_SIZE];
	int		num_of_register;

};