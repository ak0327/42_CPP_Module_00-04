#pragma once

#include <string>
#include <iostream>
#include "FileHandler.hpp"

class ReplaceHandler {
public:
	ReplaceHandler(FileHandler &file);
	~ReplaceHandler();

	FileHandler &get_file();

	void execReplace(const std::string &toBeReplaced,
					 const std::string &toReplace);

private:
	FileHandler &file_;

	std::string get_replaced_line(std::string src,
								  const std::string &toBeReplaced,
								  const std::string &toReplace) const;
};

