#ifndef ARBOLTRIE_H_
#define ARBOLTRIE_H_

#include "TrieNode.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

/* Definición del TAD ArbolTrie como una clase. */
class ArbolTrie {
    private:
        /* Datos mínimos */
        TrieNode* root;
        int cantWords;

    public:
        /* Constructores */
        ArbolTrie();

        /* Getters and Setters */
        int getCantWords();
        void setCantWords(bool increase);

        /* Busqueda y inserción */
        void insert_word(string& word);
        TrieNode* search_prefix(string& prefix);
        set<string> search_words(string& word, bool inverse);

        /* empty() */
        bool isEmpty();
};

#endif