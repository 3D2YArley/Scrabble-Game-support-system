#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <fstream>
#include <iostream>
#include <sstream>

#include <iomanip>
#include <algorithm>

#include <deque>
#include <set>

#include "Letra.h"
#include "Diccionario.h"
#include "ArbolTrie.h"

using namespace std;

class Scrabble {
    private:
        list<Letra> letras;

        Diccionario diccionario;
        Diccionario dicc_inverso;

        ArbolTrie arbol;
        ArbolTrie arbol_inverso;

    public:
        Scrabble();

        bool fill_letter(string nom_archivo);
        
        bool inicializar_diccionario(string nom_archivo, bool invertir);
        string word_score(string word);

        void inicializar_Arbol(string nom_archivo, bool invertir);
        set<Palabra> search_words(string word, bool isPrefix);
        int calculate_score(string& word);
};

#endif