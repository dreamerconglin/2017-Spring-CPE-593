#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class HashTable {
private:
    struct Node {
        string key;
        Node* next;
        Node(string s, Node* node) : key(s), next(node){}
    };
    vector<Node *> vec;
    int count;

    static int hash (const string& key) {
        int hash = 0;
        for (auto c : key)
            hash += c;
        return (hash % 101);
    }

public:
    HashTable() : count(0) { vec.resize(101, nullptr); }
    void add(const string& s) {
        Node * new_node = new Node(s, vec[hash(s)]);
        vec[hash(s)] = new_node;
        ++count;
    }
    bool contains(const string& s) const {
        if(vec[hash(s)] == nullptr) return false;
        Node* p = vec[hash(s)];
        while (p != nullptr){
            if (p->key == s) return true;
            p = p->next;
        }
        return false;
    }
    int getCount(){ return count; }

    void display (){
        for (int i = 0; i <101; ++i) {
            Node* p = vec[i];
            int display_count = 0;
            while ( p != nullptr ) {
                ++display_count;
                p = p->next;
            }
            cout << "Insert: " << i << " Count: " << display_count <<endl;
        }
    }
};

int main () {
    clock_t startTime,endTime;
    startTime = clock();

    ifstream dict("dict.txt"), in("hw8.txt");
    HashTable ht;

    string word;
    while ( getline(dict, word) )
        ht.add(word);
    cout << "Complete loading dictionary! " << ht.getCount() << " words loaded\n\n";

    string test;
    while ( getline(in, test) )
        cout<< test << " : " << (ht.contains(test) ? "True\n" : "Fasle\n");
    cout << endl;

    ht.display();

    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    system("pause");
    return 0;
}
