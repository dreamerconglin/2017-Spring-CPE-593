#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int main () {
	clock_t startTime,endTime;
	startTime = clock();

	ifstream dict("dict.txt"), in("hw5.txt");
	unordered_map <string, int> mp;//store the dict data in an unordered_map

	string word;
	int count = 0;
	for (int i = 0; getline(dict, word); ++i){
		mp[word]= i;
		++count;
	}
	cout << "Complete loading dictionary! " << count << " words loaded\n\n";

	string test;
	while ( getline(in, test) )	
		cout<< test << " : " << (mp.find(test) != mp.end() ? "True" : "Fasle") << endl; 

	endTime = clock();
	cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

	system("pause");
	return 0;
}
