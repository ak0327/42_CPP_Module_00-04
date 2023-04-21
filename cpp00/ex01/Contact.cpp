#include "Contact.hpp"

Contact::Contact() :
		first_name_(""),
		last_name_(""),
		nickname_(""),
		phone_number_(""),
		secret_("") {
}

Contact::Contact(string first_name,
				 string last_name,
				 string nickname,
				 string phone_number,
				 string secret) :
	first_name_(first_name),
	last_name_(last_name),
	nickname_(nickname),
	phone_number_(phone_number),
	secret_(secret) {
}

void Contact::SetData(string first_name,
					  string last_name,
					  string nickname,
					  string phone_number,
					  string secret ) {
	first_name_ = first_name;
	last_name_ = last_name;
	nickname_ = nickname;
	phone_number_ = phone_number;
	secret_ = secret;
}

void Contact::GetData() {
	cout << "#   First Name   : " << first_name_ << endl;
	cout << "#   Last Name    : " << last_name_ << endl;
	cout << "#   Nickname     : " << nickname_ << endl;
	cout << "#   Phone Number : " << phone_number_ << endl;
	cout << "#   Secret       : " << secret_ << endl;
}

string Contact::get_first_name() {
	return (first_name_);
}

string Contact::get_last_name() {
	return (last_name_);
}

string Contact::get_nickname() {
	return (nickname_);
}

string Contact::get_phone_number() {
	return (phone_number_);
}

string Contact::get_secret() {
	return (secret_);
}