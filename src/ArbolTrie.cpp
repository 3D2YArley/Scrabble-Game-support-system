#include "ArbolTrie.h"

ArbolTrie::ArbolTrie(){
    root = new TrieNode();
    num_words = 0;
}

void ArbolTrie::setNumWords(bool increase){
    if (increase)
        num_words++;
    else 
        num_words--;
}

void ArbolTrie::insert_word(string& word){
    TrieNode* currentNode = root;

    for (auto c : word){
        if (!currentNode->key_exist(c)){
            currentNode->insert_childNode(c);
        }
        currentNode = currentNode->getNode(c);
    }
    currentNode->increase_wordCount();
    this->setNumWords(true);
}

bool ArbolTrie::search_word(string& word, bool prefijo){
    TrieNode* currentNode = root;

    for (auto c : word){
        if (!currentNode->key_exist(c)){
            return false;
        }
        currentNode = currentNode->getNode(c);
    }
    if (prefijo)
        return true;
    else
        return (currentNode->getNumWord() > 0);
}

