#include "ReplaceHandler.hpp"

ReplaceHandler::ReplaceHandler(FileHandler &file) : file_(file) {}
ReplaceHandler::~ReplaceHandler() {}

FileHandler &ReplaceHandler::get_file() {
	return file_;
}

void ReplaceHandler::execReplace(const std::string &toBeReplaced,
								 const std::string &toReplace) {
	std::string	content;
	std::string replaced;

	while (getline(get_file().get_ifs(), content)) {
		if (!get_file().get_ifs().eof()) {
			content += "\n";
		}
		replaced = get_replaced_line(content, toBeReplaced, toReplace);
		if (!replaced.empty()) {
			get_file().get_ofs() << replaced;
		}
	}
}

std::string ReplaceHandler::get_replaced_line(std::string src,
											  std::string &toBeReplaced,
											  std::string &toReplace) const {
	size_t		i, j;
	std::string	line, tmp;

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