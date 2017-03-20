#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MaxBranchNum = 52;

static int getIndex(char c){ return c - 'a' < 0 ? c - 'A' : c - 'a' + 26; }

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

    void add(const string& word) {
        TrieNode* p = root;
        for(auto c : word) {
            int index = getIndex(c);
            if(p->next[index] == nullptr)
                p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isEnd=true;
        ++count;
    }

    bool contains(const string& s) {
        TrieNode* p = root;
        for(auto c : s){
            int index = getIndex(c);
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return p->isEnd;
    }

    bool containsPrefix(const string& s) {
        TrieNode* p = root;
        for(auto c : s){
            int index = getIndex(c);
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return true;
    }

    int getCount(){ return count; }
};

void dfs(vector <vector <char>> board, vector <vector <bool>> visited, string str, int x, int y, int n, Trie trie) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y]) return;
    str += board[x][y];
    if (!trie.containsPrefix(str)) return;

    if (str.length() >= n - 1 && trie.contains(str)) cout << str << " is a word." << endl;

    visited[x][y] = true;
    dfs(board, visited, str, x - 1, y, n, trie);
    dfs(board, visited, str, x + 1, y, n, trie);
    dfs(board, visited, str, x, y - 1, n, trie);
    dfs(board, visited, str, x, y + 1, n, trie);
    visited[x][y] = false;
}

void findWords(int n, vector <vector <char>> board, Trie trie) {
    vector <vector <bool>> visited(n ,vector <bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dfs(board, visited, "", i, j, n, trie);
}

int main () {

    ifstream dict("dictionary.txt"), fin("boggle.dat");
    Trie trie;

    string word;
    while ( getline(dict, word) )
        trie.add(word);
    cout << "Complete loading dictionary! " << trie.getCount() << " words loaded\n\n";

    int n;
    fin >> n;
    vector <vector <char>> board(n ,vector <char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> board[i][j];

    findWords(n, board, trie);

    system("pause");
    return 0;
}
