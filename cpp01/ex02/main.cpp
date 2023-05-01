#include <iostream>
#include <string>

using namespace std;

void print_strs(string var, string *ptr, string &ref)
{
	cout << "strVAR:" << var << ", " << &var << endl;
	cout << "strPTR:" << *ptr << ", " << &ptr << endl;
	cout << "strREF:" << ref << ", " << &ref << endl;
	cout << endl;
}

int main() {
	string strVAR = "HI THIS IS BRAIN";
	string *strPTR = &strVAR;
	string &strREF = strVAR;

	print_strs(strVAR, strPTR, strREF);

	strVAR = "hello";
	print_strs(strVAR, strPTR, strREF);

	*strPTR = "world";
	print_strs(strVAR, strPTR, strREF);

	strREF = "42Tokyo";
	print_strs(strVAR, strPTR, strREF);

}