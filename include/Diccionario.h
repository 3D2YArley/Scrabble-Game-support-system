#ifndef DICCIONARIO_H_
#define DICCIONARIO_H_

#include "Palabra.h"
#include <list>

using namespace std;

/* Definición del TAD Diccionario como una clase. */
class Diccionario {
    private:
        /* Datos mínimos */
        list<Palabra> list_words;

    public:
        /* Constructores */
        Diccionario();

        /* getters */
        list<Palabra> getListWords();
        void setListWords(list<Palabra> works);

        /* Busqueda y inserción */
        void addWord(Palabra p);
        Palabra* searchWord(const string& word);

        /* size() */
        
        /* empty() */
        bool palabras_is_empty();

};

#endif