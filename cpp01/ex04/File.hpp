#pragma once

#include <fstream>
#include <string>

using namespace std;

class File {
public:
	File(string inputFilename);
	~File();

	ifstream &get_ifs();
	ofstream &get_ofs();
	void set_ifs(const string &filename);
	void set_ofs(const string &filename);

private:
	string inputFilename_;
	ifstream ifs_;
	ofstream ofs_;
};