#include <iostream>
#include <iomanip>

static void print_ptr_info(std::string str, std::string *ptr, std::string &ref)
{
	std::cout << std::setw(10) << "strVAR : " << std::setw(15) <<  str << " " << &str << std::endl;
	std::cout << std::setw(10) << "strPTR : " << std::setw(15) <<  *ptr << " " << &ptr << std::endl;
	std::cout << std::setw(10) << "strREF : " << std::setw(15) <<  ref << " " << &ref << std::endl;
	std::cout << std::endl;
}

int main() {
	std::string strVAR = "HI THIS IS BRAIN";
	std::string *strPTR = &strVAR;
	std::string &strREF = strVAR;

	print_ptr_info(strVAR, strPTR, strREF);

	strVAR = "hello";
	print_ptr_info(strVAR, strPTR, strREF);

	*strPTR = "world";
	print_ptr_info(strVAR, strPTR, strREF);

	strREF = "42Tokyo";
	print_ptr_info(strVAR, strPTR, strREF);

	return 0;
}
