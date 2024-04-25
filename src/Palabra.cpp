#include "Palabra.h"

Palabra::Palabra(){ }

Palabra::Palabra(string word){
    this->palabra = word;
    this->longitud = palabra.length();
}

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

int Palabra::getLength(){
    return longitud;
}

void Palabra::setLength(int length){
    longitud = length;
}

bool Palabra::operator<(const Palabra& other) const {
    return palabra < other.palabra;
}

