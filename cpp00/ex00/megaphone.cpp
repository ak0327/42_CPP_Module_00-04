#include <iostream>
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

using namespace std; //名前空間 std::を省略

string trim(string str) {
	const string space = " ";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return (str);
}

string str_toupper(string &str) {
	for (size_t i=0; i<str.size(); i++) {
		str.at(i) = toupper(str.at(i));
	}
	return (str);
}

int	main(int argc, char **argv) {
	if (argc > 1) {
		string str, ans;

		for (int i=1; i<argc; i++) {
			str = trim(argv[i]);

			if (str.empty()) {
				continue ;
			}

			str_toupper(str);

			if (!ans.empty()) {
				ans += " ";
			}
			ans += str;
		}
		if (!ans.empty()) {
			cout << ans << endl;
			return (0);
		}
	}
	cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return (1);
}