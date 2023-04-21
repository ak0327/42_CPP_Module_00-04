#pragma once
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi

using namespace std;

class Contact {

public:
	// デフォルトコンストラクタ（初期化は成り行き）
	Contact();
	// 引数付きコンストラクタ（初期値指定）
	Contact(string first_name,
			string last_name,
			string nickname,
			string phone_number,
			string secret);

	void SetData(string first_name,
				 string last_name,
				 string nickname,
				 string phone_number,
				 string secret);
	void GetData();

	string get_first_name();
	string get_last_name();
	string get_nickname();
	string get_phone_number();
	string get_secret();

private:
	string	first_name_;
	string	last_name_;
	string 	nickname_;
	string	phone_number_;
	string	secret_;
};