//#include "FileHandler.hpp"
//
//static bool	is_file(const string &inputFilePath);
//static bool	can_open_file(const string &inputFilePath);
//
//FileHandler::FileHandler(const string &filename) {
////: ifs_(filename.c_str()), ofs_((filename + ".replace").c_str()){
////	if (!ifs_ || !ofs_) {
////		throw invalid_argument("[Error] File can't open");
////	}
//
//	set_ifs(filename);
//	set_ofs(filename);
//}
//
//void FileHandler::set_ifs(const string &filename) {
//	if (!is_file(filename) || !can_open_file(filename)) {
//		throw invalid_argument("[Error] invalid filename");
//	}
//
//	ifs_.open(filename, ifstream::in);
//	if (!ifs_) {
//		throw invalid_argument("[Error] abort");
//	}
//}
//
//void FileHandler::set_ofs(const string &filename) {
//	string outputFileName;
//	outputFileName = filename + ".replace";
//
//	ofs_.open(outputFileName, ofstream::out | ofstream::trunc);
//	if (!ofs_) {
//		throw invalid_argument("[Error] abort");
//	}
//}
//
//ifstream &FileHandler::get_ifs() {
//	return ifs_;
//}
//
//ofstream &FileHandler::get_ofs() {
//	return ofs_;
//}
//
//FileHandler::~FileHandler() {
//	ifs_.close();
//	ofs_.close();
//}
//
//static bool	is_file(const string &inputFilePath) {
//	string		directoryPath;
//	ifstream	ifs;
//	bool		res;
//
//	directoryPath = inputFilePath + "/";
//	ifs.open(directoryPath);
//	if (!ifs)
//		res = true;
//	else
//		res = false;
//	ifs.close();
//	return res;
//}
//
//static bool	can_open_file(const string &inputFilePath) {
//	ifstream	ifs;
//	bool		res;
//
//	ifs.open(inputFilePath, ifstream::in);
//	if (ifs)
//		res = true;
//	else
//		res = false;
//	ifs.close();
//	return res;
//}