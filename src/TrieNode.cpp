#include "TrieNode.h"

// Constructores
TrieNode::TrieNode(){
    wordCount = 0;
    letter = ' ';
}
TrieNode::TrieNode(char c){
    wordCount = 0;
    letter = c;
}
        // Funciones Básicas de clase
void TrieNode::increase_wordCount(){ wordCount++; }

void TrieNode::decrease_wordCount(){ wordCount--; }

void TrieNode::setLetter(char c){ letter = c; } 

char TrieNode::getLetter(){ return letter; }

int TrieNode::getNumWord(){ return wordCount; }

void TrieNode::insert_childNode(char c){
    TrieNode* newNode = new TrieNode(c);
    childNodes[c] = newNode;
}

TrieNode* TrieNode::getNode(char c){
    return childNodes[c];
}

bool TrieNode::key_exist(char c){
    auto iterador = childNodes.find(c);

    if (iterador != childNodes.end()){
        return true;
    } else {
        return false;
    }
}