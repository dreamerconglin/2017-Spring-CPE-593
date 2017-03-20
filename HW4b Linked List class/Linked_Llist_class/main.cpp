#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class LinkedList {

private:
    class Node {
    public:
        int val;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;

public:
    LinkedList() {head = tail = nullptr;}

    void addStart(int value) {
        if (head == nullptr || tail == nullptr){
            Node* p = new Node();
            p->val = value;
            p->next = nullptr;
            p->prev = nullptr;
            head = tail = p;
        }
        else{
            Node* p = new Node();
            p->val = value;
            p->next = head;
            p->prev = nullptr;
            head->prev = p;
            head = p;
        }
    }

    void addEnd(int value) {
        if (head == nullptr || tail == nullptr){
            Node* q = new Node();
            q->val = value;
            q->next = nullptr;
            q->prev = nullptr;
            head = tail = q;
        }
        else{
            Node* q = new Node();
            q->val = value;
            q->next = nullptr;
            q->prev = tail;
            tail->next = q;
            tail = q;
        }
    }

    void removeStart() {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void removeEnd() {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    Node* search(int value) {
        Node* x = head;
        while (x != nullptr && x->val != value )
            x = x->next;
        retrun x;
    }

    friend ostream& operator <<(ostream& s, const LinkedList& list){      
        for(Node* p = list.head; p != nullptr; p = p->next)
            s << p->val << " ";
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

    LinkedList list;
    ifstream in ("HW4b.txt");//open the file
    string line;
    char delim = ':';
    map <string,int> instruction_map;
    instruction_map["ADD_FRONT"] = 'A';
    instruction_map["ADD_BACK"] = 'B';
    instruction_map["OUTPUT"] = 'C';
    instruction_map["REMOVE_FRONT"] = 'D';
    instruction_map["REMOVE_BACK"] = 'E';

    while( getline(in, line) ) {

        string instruction, number;
        vector <int> num;
        istringstream record(line);

        record >> instruction;

        switch (instruction_map[instruction]) {

        case 'A': {
            record >> number;
            split(number, delim , num);
            for(int i = num[0]; i <= num[2]; i+= num[1])
                list.addStart(i);
            break;
        }

        case 'B': {
            record >> number;
            split(number, delim , num);
            for(int i = num[0]; i <= num[2]; i+= num[1])
                list.addEnd(i);
            break;
        }

        case 'C': {
            cout << list << endl;
            break;
        }

        case 'D': {
            record >> number;
            split(number, delim , num);
            for(int j = 0; j < num[0]; j++)
                list.removeStart();
            break;
        }

        case 'E': {
            record >> number;
            split(number, delim , num);
            for(int j = 0; j < num[0]; j++)
                list.removeEnd();
            break;
        }
        }
    }

    system("pause");
    return 0;
}
