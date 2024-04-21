#ifndef TRIENODE_H_
#define TRIENODE_H_

#include <map>

using namespace std;

class TrieNode {
    private:
        int wordCount;
        char letter;
        map<char, TrieNode*> childNodes;
    
    public:
        // Constructores
        TrieNode();
        TrieNode(char c);
        // Funciones Básicas de clase
        void increase_wordCount();

        void decrease_wordCount();
        void setLetter(char c);

        char getLetter();

        int getNumWord();

        void insert_childNode(char c);
        TrieNode* getNode(char c);

        bool key_exist(char c);
};

#endif