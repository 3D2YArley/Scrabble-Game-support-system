#include "TrieNode.h"

// Constructores
TrieNode::TrieNode(){
    flagWord = false;
    letter = ' ';
}

TrieNode::TrieNode(char c){
    flagWord = false;
    letter = c;
}
        // Funciones Básicas de clase
void TrieNode::setFlagWord(bool flag){
    flagWord = flag; 
}

bool TrieNode::getFlagWord(){
    return flagWord;
}

void TrieNode::setLetter(char c){
    letter = c; 
} 

char TrieNode::getLetter(){
    return letter; 
}

/*map<char, TrieNode*> TrieNode::getChildNodes(){
    return childNodes;
}*/

void TrieNode::insert_childNode(char c){
    // Aqui se debe agregar el puntaje de esa letra.
    TrieNode* newNode = new TrieNode(c);
    childNodes[c] = newNode;
}

TrieNode* TrieNode::get_nodo_key(char c){
    return childNodes[c];
}

void TrieNode::search_words_childNodes(set<string>& list_words, string wordAux, bool inverso){
    wordAux += this->getLetter();
    string ad = wordAux;

    if (this->flagWord){
        if (inverso)
            reverse(ad.begin(), ad.end());
        list_words.insert(ad);
    }

    if (!this->childNodes_isEmpty()){
        for (auto c : childNodes){
            TrieNode* nodeChild = c.second;
            nodeChild->search_words_childNodes(list_words, wordAux, inverso);
        }
    }
}

bool TrieNode::childNodes_isEmpty(){
    if (childNodes.empty())
        return true;
    else
        return false;
}

bool TrieNode::key_exist(char c){
    auto iterador = childNodes.find(c);

    if (iterador != childNodes.end()){
        return true;
    } else {
        return false;
    }
}

