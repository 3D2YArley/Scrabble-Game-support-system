#ifndef TRIENODE_H_
#define TRIENODE_H_

#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class TrieNode {
    private:
        bool flagWord;
        char letter;
        map<char, TrieNode*> childNodes;
    
    public:
        // Constructores
        TrieNode();
        TrieNode(char c);

        // Funciones Básicas de clase
        void setFlagWord(bool flag);
        bool getFlagWord();
        void setLetter(char c);
        char getLetter();

        map<char, TrieNode*> getChildNodes();
        void insert_childNode(char c);
        void search_words_childNodes(set<string>& list_words, string wordAux, bool inverso);
        
        bool childNodes_isEmpty();
        TrieNode* get_nodo_key(char c);
        bool key_exist(char c);
};

#endif