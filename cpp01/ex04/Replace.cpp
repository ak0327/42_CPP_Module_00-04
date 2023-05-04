//#include "Replace.hpp"
//
//string get_replaced_line(string src, const string &toBeReplaced, const string &toReplace) {
//	size_t i, j;
//	string line, tmp;
//
//	i = 0;
//	line = "";
//	while (src[i])
//	{
//		while (src[i] && src[i] != toBeReplaced[0]) {
//			line += src[i];
//			i++;
//		}
//		if (!src[i])
//			break ;
//		j = 0;
//		tmp = "";
//		while (src[i + j] && toBeReplaced[j] && src[i + j] == toBeReplaced[j]) {
//			tmp += src[i + j];
//			j++;
//		}
//		if (!toBeReplaced[j]) {
//			line += toReplace;
//		}
//		else {
//			line += tmp;
//		}
//		i += j;
//	}
//	return (line);
//}
//
//Replace::~Replace() {}
//
//// abc a->A
//// Abc
//
//void Replace::execReplace(FileHandler file,
//						  const std::string &toBeReplaced,
//						  const std::string &toReplace) {
//	string	line, content;
//	string replaced;
//
//	// todo: string + '\n'
//	while (getline(file.get_ifs(), content)) {
//		if (!file.get_ifs().eof()) {
//			content += "\n";
//		}
//		replaced = get_replaced_line(content, toBeReplaced, toReplace);
//		if (!replaced.empty()) {
//			file.get_ofs() << replaced;
//		}
//	}
//}
