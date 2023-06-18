#include "FileHandler.hpp"

FileHandler::FileHandler(const std::string &filename) {
	set_ifs(filename);
	set_ofs(filename);
}

FileHandler::~FileHandler() {
	ifs_.close();
	ofs_.close();
}

void FileHandler::set_ifs(const std::string &filename) {
	if (!is_file(filename) || !can_open_file(filename)) {
		throw std::invalid_argument("[Error] invalid filename");
	}

	ifs_.open(filename, std::ifstream::in);
	if (!ifs_) {
		throw std::invalid_argument("[Error] abort");
	}
}

void FileHandler::set_ofs(const std::string &filename) {
	std::string outputFileName;
	outputFileName = filename + ".replace";

	ofs_.open(outputFileName, std::ofstream::out | std::ofstream::trunc);
	if (!ofs_) {
		throw std::invalid_argument("[Error] abort");
	}
}

std::ifstream &FileHandler::get_ifs() {
	return ifs_;
}

std::ofstream &FileHandler::get_ofs() {
	return ofs_;
}

bool	is_file(const std::string &inputFilePath) {
	std::string		directoryPath;
	std::ifstream	ifs;
	bool			res;

	directoryPath = inputFilePath + "/";
	ifs.open(directoryPath);
	if (!ifs)
		res = true;
	else
		res = false;
	ifs.close();
	return res;
}

// todo: ifs.fail()
bool	can_open_file(const std::string &inputFilePath) {
	std::ifstream	ifs;
	bool			res;

	ifs.open(inputFilePath, std::ifstream::in);
	if (ifs)
		res = true;
	else
		res = false;
	ifs.close();
	return res;
}