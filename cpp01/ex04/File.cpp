#include "File.hpp"
static bool	is_file(const string &inputFilePath);
static bool	can_open_file(const string &inputFilePath);

File::File(const string filename) {
	set_ifs(filename);
	set_ofs(filename);
}

void File::set_ifs(const string &filename) {
	if (!is_file(filename) || !can_open_file(filename)) {
		throw invalid_argument("[Error] invalid filename");
	}

	ifs_.open(filename, ifstream::in);
	if (!ifs_) {
		throw invalid_argument("[Error] abort");
	}
}

void File::set_ofs(const string &filename) {
	string outputFileName;
	outputFileName = filename + ".replace";

	ofs_.open(outputFileName, ofstream::out | ofstream::trunc);
	if (!ofs_) {
		throw invalid_argument("[Error] abort");
	}
}

ifstream &File::get_ifs() {
	return ifs_;
}

ofstream &File::get_ofs() {
	return ofs_;
}

File::~File() {
	ifs_.close();
	ofs_.close();
}

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