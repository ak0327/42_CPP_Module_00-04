#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i, n) for (int i=0; i<(int)n; i++)
#define my_cout(x) cout << x << endl;

#include "PhoneBook.hpp"
#include "Contact.hpp"

using namespace std; //名前空間 std::を省略


int main() {
	//phone book, contactの初期化

//	Contact contact("aaa",
//					"bbb",
//					"hoge",
//					"1212",
//					"hoge");
//	contact.GetData();
//
//	Contact contact2;
//	contact2.GetData();
	string	input_cmd;
	PhoneBook phonebook;

	cout << "############ PHONE  BOOK ###########" << endl;
	while (true)
	{
		cout << "### command: ADD / SEARCH / EXIT ###" << endl;
		cout << "# Input Command >> " << ends;
		if (!getline(cin, input_cmd)) {
			cout << "# ^D" << endl;
			return (0);
		}
		if (input_cmd == "ADD") {
			phonebook.add();
		} else if (input_cmd == "SEARCH") {
			phonebook.search();
		} else if (input_cmd == "EXIT") {
			cout << "# BYE :)" << endl;
			break ;
		} else {
			cout << "# [Error] Invalid command" << endl;
		}
		cout << "#" << endl;
	}

}