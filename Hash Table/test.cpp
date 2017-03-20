#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
	ifstream in ("dict.txt");
	string s, max_string;
	size_t sum = 0;
	while ( getline(in, s) ){
		size_t temp = max(sum, s.size() );
		if (sum != temp) max_string = s;
		sum = temp;
	}

	cout << sum <<endl;
	cout << max_string;
	return 0;
}
