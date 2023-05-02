#pragma once

#include <string>
#include <iostream>
#include "File.hpp"

using namespace std;

class Replace {
public:
	Replace(File &file) : file_(file) {};
	~Replace();

	void execReplace(const string &toBeReplaced, const string &toReplace);

private:
	File &file_;
};