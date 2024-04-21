#ifndef ARBOLTRIE_H_
#define ARBOLTRIE_H_

#include "TrieNode.h"
#include <string>

using namespace std;

class ArbolTrie {
    private:
        TrieNode* root;
        int num_words;

    public:
        ArbolTrie();

        void setNumWords(bool increase);

        void insert_word(string& word);

        bool search_word(string& word, bool prefijo);

};

#endif