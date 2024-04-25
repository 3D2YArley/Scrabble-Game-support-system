#ifndef ARBOLTRIE_H_
#define ARBOLTRIE_H_

#include "TrieNode.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

class ArbolTrie {
    private:
        TrieNode* root;
        int num_words;

    public:
        ArbolTrie();

        int getNumWords();
        void setNumWords(bool increase);

        void insert_word(string& word);
        TrieNode* search_prefix(string& prefix);

        bool isEmpty();
        set<string> search_words(string& word, bool inverso);
};

#endif