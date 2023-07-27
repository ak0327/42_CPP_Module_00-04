#include <iostream>

#define WHITE_SPACE_CHR	' '
#define WHITE_SPACE_STR	" "

static void skip_space(std::string &str, size_t &i) {
	while (str[i] == WHITE_SPACE_CHR) {
		i++;
	}
}

static std::string get_upper_str(std::string &str, size_t &i) {
	std::string ret_str = "";
	char c;

	while (str[i] && str[i] != WHITE_SPACE_CHR) {
		c = str[i];
		if (std::islower(c))
			c =  std::toupper(str[i]);
		ret_str += c;
		i++;
	}
	return ret_str;
}

static std::string get_megaphone_str(std::string &str) {
	std::string ret_str = "";
	size_t i = 0;

	skip_space(str, i);
	while (str[i]) {
		ret_str += get_upper_str(str, i);
		skip_space(str, i);
		if (str[i])
			ret_str += WHITE_SPACE_STR;
	}
	return ret_str;
}

static const std::string get_megaphone(int argc, char **argv) {
	std::string megaphone_str = "";
	std::string av, str;

	for (int i=1; i<argc; i++) {
		av = argv[i];
		str = get_megaphone_str(av);
		if (str.empty())
			continue ;
		if (!megaphone_str.empty())
			megaphone_str += WHITE_SPACE_STR;
		megaphone_str += str;
	}
	return megaphone_str;
}

int	main(int argc, char **argv) {
	std::string megaphone_str;

	if (argc > 1) {
		megaphone_str = get_megaphone(argc, argv);
		if (!megaphone_str.empty()) {
			std::cout << megaphone_str << std::endl;
			return EXIT_SUCCESS;
		}
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return EXIT_FAILURE;
}
