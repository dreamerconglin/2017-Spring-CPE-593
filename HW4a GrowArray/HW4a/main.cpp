#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class GrowArray {

private:
    int* data;
    size_t used;
    size_t capacity;
    void grow(){
        if (capacity == 0){
            capacity = 100;
            data = new int [capacity];
        }
        else{
            capacity *= 2;
            int* temp = new int [used];
            for (int i = 0; i < used; i++)
                temp[i] = data[i];
            data = new int[capacity];
            for (int i = 0; i < used; i++)
                data[i] = temp[i];
            delete [] temp;
        }
    }

public:
    GrowArray() : data(nullptr),used(0),capacity(0) {}

    GrowArray(int initialCapacity) {
        data = new int[initialCapacity];
        capacity = initialCapacity;
    }

    ~GrowArray() {
        delete [] data;
    }

    void addStart(int value) {
        if (capacity == 0 && used == capacity)
            grow();
        int* temp = new int [used];
        for (int i = 0; i < used; i++)
            temp[i] = data[i];
        for (int i = 0; i < used; i++)
            data[i + 1] = temp[i];
        data[0] = value;
        delete [] temp;
        ++ used;
    }

    void addEnd(int value) {
        if (capacity == 0 && used == capacity)
            grow();
        data [used] = value;
        ++ used;
    }

    void removeStart() {
        if (used == 0)
            cout << "Error! You cannot execute REMOVE_FRONT in an empty array!" << endl;
        else{
            int* temp = new int [used];
            for (int i = 0; i < used; i++)
                temp[i] = data[i];
            for (int i = 0; i < used - 1; i++)
                data[i] = temp[i + 1];
            delete [] temp;
            -- used;
        }      
    }

    void removeEnd() {
        if (used == 0)
            cout << "Error! You cannot execute REMOVE_BACK in an empty array!" << endl;
        else{
            data[used - 1] = 0;
            -- used;
        }
    }

    friend ostream& operator <<(ostream& s, const GrowArray& arr){
        if (arr.used == 0)
            s << "Empty Array!" << endl;
        else
            for(int i = 0; i < arr.used; ++i)
                s << arr.data[i] << ",";
        return s;
    }
};

void split(const string& s, char delim, vector<int>& num) {
    stringstream ss;
    ss.str(s);
    string item;
    while( getline(ss, item, delim) )
        num.push_back( atoi( item.c_str() ) );
}

int main() {

    GrowArray arr;
    ifstream in ("growArray.txt");//open the file
    string line;
    char delim = ':';
    map<string,int> instruction_map;
    instruction_map["ADD_FRONT"] = 'A';
    instruction_map["ADD_BACK"] = 'B';
    instruction_map["OUTPUT"] = 'C';
    instruction_map["REMOVE_FRONT"] = 'D';
    instruction_map["REMOVE_BACK"] = 'E';

    while( getline(in, line) ) {

        string instruction, number;
        vector<int> num;
        istringstream record(line);

        record >> instruction;

        switch (instruction_map[instruction]) {

        case 'A': {
            record >> number;
            split(number, delim , num);
            for(int i = num[0]; i <= num[2]; i+= num[1])
                arr.addStart(i);
            break;
        }

        case 'B': {
            record >> number;
            split(number, delim , num);
            for(int i = num[0]; i <= num[2]; i+= num[1])
                arr.addEnd(i);
            break;
        }

        case 'C': {
            cout << arr << endl;
            break;
        }

        case 'D': {
            record >> number;
            split(number, delim , num);
            for(int j = 0; j < num[0]; j++)
                arr.removeStart();
            break;
        }

        case 'E': {
            record >> number;
            split(number, delim , num);
            for(int j = 0; j < num[0]; j++)
                arr.removeEnd();
            break;
        }
        }
    }

    system("pause");
    return 0;
}
