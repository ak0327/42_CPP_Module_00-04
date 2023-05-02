#include "Replace.hpp"

Replace::~Replace() {}

// abc a->A
// Abc

void Replace::execReplace(const std::string &toBeReplaced,
						  const std::string &toReplace) {
	if (toBeReplaced.length() == 0)
		return ;

	string	line;
//	size_t	idx, size;
//	idx = 0;
//	size = 0;
	cout << "execReplace" << endl;
	cout << toBeReplaced << "->" << toReplace << endl;

	cout << "\ngetline(file)" << endl;
	while (getline(file_.get_ifs(), line)) {
		cout << line << endl;
	}
}