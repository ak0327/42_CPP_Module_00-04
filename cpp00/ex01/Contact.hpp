#pragma once
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi

class Contact {

public:
	Contact();
	Contact(std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone_number,
			std::string secret);

	void SetData(std::string first_name,
				 std::string last_name,
				 std::string nickname,
				 std::string phone_number,
				 std::string secret);
	void GetData() const;

	const std::string get_first_name() const;
	const std::string get_last_name() const;
	const std::string get_nickname() const;
	const std::string get_phone_number() const;
	const std::string get_secret() const;

private:
	std::string	first_name_;
	std::string	last_name_;
	std::string 	nickname_;
	std::string	phone_number_;
	std::string	secret_;
};