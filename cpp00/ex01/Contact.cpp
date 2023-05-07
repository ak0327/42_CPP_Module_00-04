#include "Contact.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Contact::Contact() :
		first_name_(),
		last_name_(),
		nickname_(),
		phone_number_(),
		secret_() {
}

Contact::Contact(std::string first_name,
				 std::string last_name,
				 std::string nickname,
				 std::string phone_number,
				 std::string secret) :
	first_name_(first_name),
	last_name_(last_name),
	nickname_(nickname),
	phone_number_(phone_number),
	secret_(secret) {
}

void Contact::SetData(std::string first_name,
					  std::string last_name,
					  std::string nickname,
					  std::string phone_number,
					  std::string secret ) {
	first_name_ = first_name;
	last_name_ = last_name;
	nickname_ = nickname;
	phone_number_ = phone_number;
	secret_ = secret;
}

void Contact::GetData() const {
	std::cout << COLOR_CYAN << std::ends;
	std::cout << "#   First Name   : " << first_name_ << std::endl;
	std::cout << "#   Last Name    : " << last_name_ << std::endl;
	std::cout << "#   Nickname     : " << nickname_ << std::endl;
	std::cout << "#   Phone Number : " << phone_number_ << std::endl;
	std::cout << "#   Secret       : " << secret_ << std::endl;
	std::cout << COLOR_RESET << std::ends;
}

const std::string Contact::get_first_name() const {
	return (first_name_);
}

const std::string Contact::get_last_name() const {
	return (last_name_);
}

const std::string Contact::get_nickname() const {
	return (nickname_);
}

const std::string Contact::get_phone_number() const {
	return (phone_number_);
}

const std::string Contact::get_secret() const {
	return (secret_);
}