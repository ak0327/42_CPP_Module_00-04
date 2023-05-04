#pragma once

#include <string>
#include <iostream>
#include "FileHandler.hpp"

using namespace std;

class ReplaceHandler {
public:
	ReplaceHandler(FileHandler &file);
	~ReplaceHandler();

	FileHandler &get_file();

	void execReplace(const string &toBeReplaced,
					 const string &toReplace);

private:
	FileHandler &file_;
};

string get_replaced_line(string src, const string &toBeReplaced, const string &toReplace);
