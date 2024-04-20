#ifndef DICCIONARIO_H_
#define DICCIONARIO_H_

#include "Palabra.h"
#include <list>

using namespace std;

class Diccionario {
    private:
        list<Palabra> palabras;

    public:
        bool palabras_is_empty();

};

#endif