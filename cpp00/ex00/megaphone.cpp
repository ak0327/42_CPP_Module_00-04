#include <iostream>

std::string trim(std::string str) {
	const std::string space = " ";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return (str);
}

std::string str_toupper(std::string &str) {
	for (size_t i=0; i<str.size(); i++) {
		str.at(i) = toupper(str.at(i));
	}
	return (str);
}

int	main(int argc, char **argv) {
	if (argc > 1) {
		std::string str, ans;

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
			std::cout << ans << std::endl;
			return (0);
		}
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (1);
}