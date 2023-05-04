#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler {
public:
	FileHandler(const string &filename);
	~FileHandler();

	ifstream &get_ifs();
	ofstream &get_ofs();
	void set_ifs(const string &filename);
	void set_ofs(const string &filename);

private:
	ifstream ifs_;
	ofstream ofs_;
};

bool is_file(const string &inputFilePath);
bool can_open_file(const string &inputFilePath);