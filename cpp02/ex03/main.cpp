#include <iostream>
#include "Fixed.hpp"
using namespace std;

int main() {
	cout.precision(10);
	try {

	}
	catch (exception &e){
		cerr << e.what() << endl;
	}
//	system("leaks a.out");
	return 0;
}