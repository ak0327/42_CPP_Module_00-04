#include <fstream>
#include <iostream>
#include <string>

#include "FileHandler.hpp"
#include "Replace.hpp"

using namespace std;

static bool	is_file(const string &inputFilePath) {
	string		directoryPath;
	ifstream	ifs;
	bool		res;

	directoryPath = inputFilePath + "/";
	ifs.open(directoryPath);
	if (!ifs)
		res = true;
	else
		res = false;
	ifs.close();
	return res;
}

static bool	can_open_file(const string &inputFilePath) {
	ifstream	ifs;
	bool		res;

	ifs.open(inputFilePath, ifstream::in);
	if (ifs)
		res = true;
	else
		res = false;
	ifs.close();
	return res;
}

static void check_argc(int argc) {
	if (argc != 4) {
		throw invalid_argument(
				"[Error] Invalid argument. Input following:\n"
				"        $ ./a.out <˜˜filename> <string to be replaced> <string to replace>");
	}
}

static string get_replaced_line(string src, string &toBeReplaced, string &toReplace) {
	size_t i, j;
	string line, tmp;

	i = 0;
	line = "";
	while (src[i])
	{
		while (src[i] && src[i] != toBeReplaced[0]) {
			line += src[i];
			i++;
		}
		if (!src[i])
			break ;
		j = 0;
		tmp = "";
		while (src[i + j] && toBeReplaced[j] && src[i + j] == toBeReplaced[j]) {
			tmp += src[i + j];
			j++;
		}
		if (!toBeReplaced[j]) {
			line += toReplace;
		}
		else {
			line += tmp;
		}
		i += j;
	}
	return (line);
}

// ./a.out <filename> <s1> <s2>
int main(int argc, char **argv) {
	try {
		check_argc(argc);
//		string filename = argv[1];
//		FileHandler file = FileHandler(filename);
//		Replace replace = Replace(file);
//		replace.execReplace(file, argv[2], argv[3]);

		string filename = argv[1];
		string outputFileName = filename + ".replace";;
		string toBeReplaced = argv[2];
		string toReplace = argv[3];

		ifstream ifs;
		ofstream ofs;

		if (!is_file(filename) || !can_open_file(filename)) {
			throw invalid_argument("[Error] invalid filename");
		}

		ifs.open(filename, ifstream::in);
		ofs.open(outputFileName, ofstream::out | ofstream::trunc);
		if (!ifs || !ofs) {
			throw invalid_argument("[Error] abort");
		}

		string	line, content;
		string replaced;

		// todo: string + '\n'
		while (getline(ifs, content)) {
			if (!ifs.eof()) {
				content += "\n";
			}
			replaced = get_replaced_line(content, toBeReplaced, toReplace);
			if (!replaced.empty()) {
				ofs << replaced;
			}
		}

		ifs.close();
		ofs.close();
	}
	catch (exception &e) {
		cerr << e.what() << endl;
	}
	return 0;
}
















