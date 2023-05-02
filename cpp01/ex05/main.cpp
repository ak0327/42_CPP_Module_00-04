#include <iostream>
#include "Harl.hpp"

using namespace std;

void checkArgument(int argc) {
	if (argc != 2) {
		throw invalid_argument("[Error] Invalid argument."
							   " Input as: $ ./a.out <Complain Level>\n"
							   "        Complain Level: DEBUG/INFO/WARNING/ERROR");
	}
}

int main(int argc, char **argv) {
	try {
		checkArgument(argc);
		Harl harl = Harl();
		harl.complain(argv[1]);
	}
	catch (exception &e){
		cerr << e.what() << endl;
	}
	return 0;
}