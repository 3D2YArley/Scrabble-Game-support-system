#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "Letra.h"
#include "Diccionario.h"
#include "ArbolTrie.h"

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

};

#endif // SCRABBLE_H