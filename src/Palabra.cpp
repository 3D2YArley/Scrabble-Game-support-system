#include "Palabra.h"

string Palabra::getPalabra(){
    return palabra;
}

void Palabra::setPalabra(string word){
    palabra = word;
}

int Palabra::getPoints(){
    return puntos;
}

void Palabra::setPoints(int points){
    puntos = points;
}

bool Palabra::operator<(const Palabra& otra) const {
    return palabra < otra.palabra;
}