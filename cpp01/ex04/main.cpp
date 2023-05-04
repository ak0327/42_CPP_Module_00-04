#include <iostream>
#include <string>

#include "FileHandler.hpp"
#include "ReplaceHandler.hpp"

using namespace std;

static void check_argc(int argc) {
	if (argc != 4) {
		throw invalid_argument(
				"[Error] Invalid argument. Input following:\n"
				"        $ ./a.out <filename> <string to be replaced> <string to replace>");
	}
}

// ./a.out <filename> <s1> <s2>
int main(int argc, char **argv) {
	try {
		check_argc(argc);
		string filename = argv[1];
		FileHandler file(filename);
		ReplaceHandler replace = ReplaceHandler(file);
		replace.execReplace(argv[2], argv[3]);
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
	return 0;
}
















