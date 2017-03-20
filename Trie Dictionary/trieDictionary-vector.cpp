#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include<ctime>
using namespace std;

int main() {

    clock_t startTime,endTime;
    startTime = clock();

    ifstream dict("dict.txt"), in("hw5.txt");//read in dict.txt and hw5.txt

    vector <string> vec;//store the dict data in an unordered_map
    string word;
	int count = 0;
    while ( getline(dict, word) ) {
        vec.push_back(word);
		++count;
	}
	cout << "Complete loading dictionary! " << count << " words loaded\n\n";

    string test;
    while ( getline(in, test) )
		cout<< test << " : " << (find(vec.cbegin(), vec.cend(),test) != vec.cend() ? "True" : "Fasle") << endl;	

    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");

    return 0;
}
