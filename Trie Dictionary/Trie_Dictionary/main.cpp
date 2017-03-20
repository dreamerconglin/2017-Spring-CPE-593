#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
const int MaxBranchNum = 26;//如果区分大小写，可以扩展到52

class Trie {
private:
    class TrieNode {
    public:
        TrieNode* next[MaxBranchNum];
        bool isEnd;
        TrieNode():isEnd(false){ memset(next,false,sizeof(next)); }
    };
    int count;
    TrieNode* root;

public:
    Trie(): count(0){ root = new TrieNode(); }

    void insert(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            int index = c - 'a';
            if(p->next[index] == nullptr)
                p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isEnd=true;
        ++count;
    }

    bool find(string s) {
        TrieNode* p = root;
        for(auto c : s){
            if(p->next[c - 'a'] == nullptr)
                return false;
            p = p->next[c - 'a'];
        }
        return p->isEnd;
    }

    int getCount(){ return count; }
};

int main () {
    clock_t startTime,endTime;
    startTime = clock();

    ifstream dict("dict.txt"), in("hw5.txt");
    Trie trie;

    string word;
    while ( getline(dict, word) )
        trie.insert(word);
    cout << "Complete loading dictionary! " << trie.getCount() << " words loaded\n\n";

    string test;
    while ( getline(in, test) )
        cout<< test << " : " << (trie.find(test) ? "True" : "Fasle") << endl;

    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    system("pause");
    return 0;
}
