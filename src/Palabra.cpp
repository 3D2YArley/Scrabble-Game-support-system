#include "Palabra.h"

string Palabra::getPalabra(){
    return palabra;
}

bool Palabra::operator<(const Palabra& otra) const {
    return palabra < otra.palabra;
}