#include "ArbolTrie.h"

using namespace std;

ArbolTrie::ArbolTrie(){
    root = new TrieNode();
    num_words = 0;
}

int ArbolTrie::getNumWords() {
    return num_words; 
}

void ArbolTrie::setNumWords(bool increase){
    if (increase)
        num_words++;
    else 
        num_words--;
}

void ArbolTrie::insert_word(string &word){
    TrieNode* currentNode = this->root;

    for (auto c : word){
        if (!currentNode->key_exist(c)){
            currentNode->insert_childNode(c);
        }
        currentNode = currentNode->get_nodo_key(c);
    }
    currentNode->setFlagWord(true);
    this->setNumWords(true);
}

TrieNode* ArbolTrie::search_prefix(string& prefix){
    TrieNode* currentNode = this->root;

    for (auto c : prefix){
        if (currentNode->key_exist(c)){
            currentNode = currentNode->get_nodo_key(c);
        } else 
            return nullptr;
    }
    return currentNode;
}

bool ArbolTrie::isEmpty(){
    return root->childNodes_isEmpty();
}

set<string> ArbolTrie::search_words(string& word, bool inverso){
    set<string> result;

    TrieNode* currentNode = search_prefix(word);

    if (currentNode == nullptr){
        string str = inverso ? "sufijo" : "prefijo";
        str += " " + word;
        cout << "El " << str << " no se ha podido encontrar en el arbol diccionario." << endl;
        return result;
    } else
        word.pop_back();
        currentNode->search_words_childNodes(result, word, inverso);
    
    return result;
}