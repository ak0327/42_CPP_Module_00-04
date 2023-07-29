#include <iostream>
#include "Harl.hpp"


void checkArgument(int argc) {
	if (argc != 2) {
		throw std::invalid_argument("[Error] Invalid argument."
							   " Input as: $ ./a.out <Complain Level>\n"
							   "        Complain Level: DEBUG/INFO/WARNING/ERROR");
	}
}

int main(int argc, char **argv) {
	try {
		checkArgument(argc);
		Harl harl = Harl();
		harl.filter(argv[1]);
	}
	catch (std::exception const &e){
		std::cerr << e.what() << std::endl;
	}

//	system("leaks -q harlFilter");
	return 0;
}
