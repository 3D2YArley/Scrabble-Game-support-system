#ifndef DICCIONARIO_H_
#define DICCIONARIO_H_

#include "Palabra.h"
#include <list>

using namespace std;

class Diccionario {
    private:
        list<Palabra> palabras;

    public:
        list<Palabra> getListaPalabras();
        void setListaPalabras(list<Palabra> works);

        void add_palabra(Palabra p);
        Palabra* search_word(const string& word);

        bool palabras_is_empty();

};

#endif