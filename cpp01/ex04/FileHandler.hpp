#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
	FileHandler(std::string &filename);
	~FileHandler();

	std::ifstream &get_ifs();
	std::ofstream &get_ofs();
	void set_ifs(std::string &filename);
	void set_ofs(std::string &filename);

private:
	std::ifstream ifs_;
	std::ofstream ofs_;
};

bool is_file(std::string &inputFilePath);
bool can_open_file(std::string &inputFilePath);